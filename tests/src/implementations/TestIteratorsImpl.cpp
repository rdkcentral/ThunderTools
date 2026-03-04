/*
 * Copyright 2026 Metrological - Apache 2.0
 *
 * The Register* methods spawn a detached thread to drain the incoming iterator.
 * This avoids the deadlock that would occur if we called iterator->Next()
 * from within the stub handler (the channel is busy with the incoming call,
 * so an outgoing Next() call would block indefinitely).
 *
 * The detached thread AddRef()s the iterator before the call returns, drains
 * it into local storage, then Release()s it. The test waits a fixed interval
 * before querying results.
 */

#include "TestRegistry.h"
#include <ITestIterators.h>
#include <map>
#include <thread>
#include <chrono>

namespace Thunder {
namespace TestImplementations {

    class TestIteratorsImpl : public FunctionalTest::ITestIterators {
    public:
        TestIteratorsImpl() : _nextId(1) {}
        ~TestIteratorsImpl() override = default;

        TestIteratorsImpl(const TestIteratorsImpl&) = delete;
        TestIteratorsImpl& operator=(const TestIteratorsImpl&) = delete;

        // ===== Iterator creation =====

        Core::hresult GetStrings(const uint16_t count, RPC::IStringIterator*& iterator) override
        {
            std::vector<string> items;
            items.reserve(count);
            for (uint16_t i = 0; i < count; ++i) {
                items.push_back("item_" + std::to_string(i));
            }
            iterator = Core::ServiceType<RPC::IteratorType<RPC::IStringIterator>>::Create<RPC::IStringIterator>(items);
            return Core::ERROR_NONE;
        }

        Core::hresult GetValues(const uint16_t count, RPC::IValueIterator*& iterator) override
        {
            std::vector<uint32_t> items;
            items.reserve(count);
            for (uint16_t i = 0; i < count; ++i) {
                items.push_back(i);
            }
            iterator = Core::ServiceType<RPC::IteratorType<RPC::IValueIterator>>::Create<RPC::IValueIterator>(items);
            return Core::ERROR_NONE;
        }

        Core::hresult GetEmptyStringIterator(RPC::IStringIterator*& iterator) override
        {
            std::vector<string> empty;
            iterator = Core::ServiceType<RPC::IteratorType<RPC::IStringIterator>>::Create<RPC::IStringIterator>(empty);
            return Core::ERROR_NONE;
        }

        Core::hresult GetEmptyValueIterator(RPC::IValueIterator*& iterator) override
        {
            std::vector<uint32_t> empty;
            iterator = Core::ServiceType<RPC::IteratorType<RPC::IValueIterator>>::Create<RPC::IValueIterator>(empty);
            return Core::ERROR_NONE;
        }

        Core::hresult GetLargeStringIterator(const uint16_t size, RPC::IStringIterator*& iterator) override
        {
            std::vector<string> items;
            items.reserve(size);
            for (uint16_t i = 0; i < size; ++i) {
                items.push_back("large_item_" + std::to_string(i));
            }
            iterator = Core::ServiceType<RPC::IteratorType<RPC::IStringIterator>>::Create<RPC::IStringIterator>(items);
            return Core::ERROR_NONE;
        }

        Core::hresult GetLargeValueIterator(const uint16_t size, RPC::IValueIterator*& iterator) override
        {
            std::vector<uint32_t> items;
            items.reserve(size);
            for (uint16_t i = 0; i < size; ++i) {
                items.push_back(i);
            }
            iterator = Core::ServiceType<RPC::IteratorType<RPC::IValueIterator>>::Create<RPC::IValueIterator>(items);
            return Core::ERROR_NONE;
        }

        // ===== Store-and-Query =====

        Core::hresult RegisterStringIterator(RPC::IStringIterator* iterator, uint32_t& id) override
        {
            if (iterator == nullptr) {
                return Core::ERROR_INVALID_INPUT_LENGTH;
            }
            id = _nextId++;
            iterator->AddRef();

            std::thread([this, iterator, id]() {
                StringData data;
                string element;
                iterator->Reset(0);
                while (iterator->Next(element)) {
                    if (data.count == 0) {
                        data.first = element;
                    }
                    ++data.count;
                }
                iterator->Release();

                _lock.Lock();
                _stringStore[id] = data;
                _lock.Unlock();
            }).detach();

            return Core::ERROR_NONE;
        }

        Core::hresult RegisterValueIterator(RPC::IValueIterator* iterator, uint32_t& id) override
        {
            if (iterator == nullptr) {
                return Core::ERROR_INVALID_INPUT_LENGTH;
            }
            id = _nextId++;
            iterator->AddRef();

            std::thread([this, iterator, id]() {
                ValueData data;
                uint32_t element;
                iterator->Reset(0);
                bool firstSet = false;
                while (iterator->Next(element)) {
                    if (!firstSet) { data.first = element; firstSet = true; }
                    data.sum += element;
                    ++data.count;
                }
                iterator->Release();

                _lock.Lock();
                _valueStore[id] = data;
                _lock.Unlock();
            }).detach();

            return Core::ERROR_NONE;
        }

        Core::hresult GetStringIteratorCount(const uint32_t id, uint32_t& count) override
        {
            _lock.Lock();
            auto it = _stringStore.find(id);
            count = (it != _stringStore.end()) ? it->second.count : 0;
            _lock.Unlock();
            return (count == 0 && _stringStore.find(id) == _stringStore.end())
                ? Core::ERROR_NOT_EXIST : Core::ERROR_NONE;
        }

        Core::hresult GetStringIteratorFirst(const uint32_t id, string& value) override
        {
            _lock.Lock();
            auto it = _stringStore.find(id);
            bool found = (it != _stringStore.end());
            if (found) value = it->second.first;
            _lock.Unlock();
            return found ? Core::ERROR_NONE : Core::ERROR_NOT_EXIST;
        }

        Core::hresult IsStringIteratorEmpty(const uint32_t id, bool& empty) override
        {
            _lock.Lock();
            auto it = _stringStore.find(id);
            bool found = (it != _stringStore.end());
            if (found) empty = (it->second.count == 0);
            _lock.Unlock();
            return found ? Core::ERROR_NONE : Core::ERROR_NOT_EXIST;
        }

        Core::hresult GetValueIteratorCount(const uint32_t id, uint32_t& count) override
        {
            _lock.Lock();
            auto it = _valueStore.find(id);
            bool found = (it != _valueStore.end());
            if (found) count = it->second.count;
            _lock.Unlock();
            return found ? Core::ERROR_NONE : Core::ERROR_NOT_EXIST;
        }

        Core::hresult GetValueIteratorSum(const uint32_t id, uint32_t& sum) override
        {
            _lock.Lock();
            auto it = _valueStore.find(id);
            bool found = (it != _valueStore.end());
            if (found) sum = it->second.sum;
            _lock.Unlock();
            return found ? Core::ERROR_NONE : Core::ERROR_NOT_EXIST;
        }

        Core::hresult GetValueIteratorFirst(const uint32_t id, uint32_t& value) override
        {
            _lock.Lock();
            auto it = _valueStore.find(id);
            bool found = (it != _valueStore.end());
            if (found) value = it->second.first;
            _lock.Unlock();
            return found ? Core::ERROR_NONE : Core::ERROR_NOT_EXIST;
        }

        Core::hresult UnregisterIterator(const uint32_t id) override
        {
            _lock.Lock();
            bool found = (_stringStore.erase(id) > 0 || _valueStore.erase(id) > 0);
            _lock.Unlock();
            return found ? Core::ERROR_NONE : Core::ERROR_NOT_EXIST;
        }

        BEGIN_INTERFACE_MAP(TestIteratorsImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestIterators)
        END_INTERFACE_MAP

    private:
        struct StringData { uint32_t count{0}; string first; };
        struct ValueData  { uint32_t count{0}; uint32_t sum{0}; uint32_t first{0}; };

        uint32_t _nextId;
        std::map<uint32_t, StringData> _stringStore;
        std::map<uint32_t, ValueData>  _valueStore;
        Core::CriticalSection          _lock;
    };

    static TestRegistry::ImplementationRegistrar<FunctionalTest::ITestIterators, TestIteratorsImpl> g_iteratorsRegistrar;

} // namespace TestImplementations
} // namespace Thunder
