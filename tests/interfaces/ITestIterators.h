/*
 * ITestIterators.h
 *
 * Store-and-query pattern: avoids COM-RPC channel deadlock by decoupling
 * iterator registration (which crosses the wire) from iterator consumption
 * (which happens locally after the call returns).
 */

#pragma once

#include "Module.h"
#include "Ids.h"

// @insert <com/ICOM.h>

namespace Thunder {
namespace FunctionalTest {

    // JSON-RPC not applicable: iterators have no clean JSON mapping.
    struct EXTERNAL ITestIterators : virtual public Core::IUnknown {
        enum { ID = ID_TEST_ITERATORS };

        // ===== Iterator creation =====

        // @brief Create an IStringIterator that yields count sequential strings
        //        of the form "item_0", "item_1", …, "item_{count-1}".
        // @param count    Number of elements in the returned iterator.
        // @param iterator Receives the newly created iterator (caller must Release).
        virtual Core::hresult GetStrings(const uint16_t count, RPC::IStringIterator*& iterator /* @out */) = 0;

        // @brief Create an IValueIterator that yields count sequential uint32_t values
        //        starting from 0.
        // @param count    Number of elements in the returned iterator.
        // @param iterator Receives the newly created iterator (caller must Release).
        virtual Core::hresult GetValues(const uint16_t count, RPC::IValueIterator*& iterator /* @out */) = 0;

        // @brief Create an IStringIterator that yields zero elements.
        //        Used to test empty-iterator edge cases.
        // @param iterator Receives an empty iterator (caller must Release).
        virtual Core::hresult GetEmptyStringIterator(RPC::IStringIterator*& iterator /* @out */) = 0;

        // @brief Create an IValueIterator that yields zero elements.
        //        Used to test empty-iterator edge cases.
        // @param iterator Receives an empty iterator (caller must Release).
        virtual Core::hresult GetEmptyValueIterator(RPC::IValueIterator*& iterator /* @out */) = 0;

        // @brief Create an IStringIterator with size elements for large-iterator testing.
        //        Intended to stress-test marshalling with sizes that exceed typical buffer limits.
        // @param size     Number of elements (e.g. 1000+).
        // @param iterator Receives the newly created iterator (caller must Release).
        virtual Core::hresult GetLargeStringIterator(const uint16_t size, RPC::IStringIterator*& iterator /* @out */) = 0;

        // @brief Create an IValueIterator with size elements for large-iterator testing.
        // @param size     Number of elements (e.g. 1000+).
        // @param iterator Receives the newly created iterator (caller must Release).
        virtual Core::hresult GetLargeValueIterator(const uint16_t size, RPC::IValueIterator*& iterator /* @out */) = 0;

        // ===== Store-and-Query Pattern =====
        //
        // Register hands the iterator to the server, which consumes it synchronously
        // before returning. Querying happens in a separate call after Register returns,
        // so the COM-RPC channel is never blocked by a re-entrant call into the client.

        // @brief Hand an IStringIterator to the server for storage.
        //        The server drains the iterator immediately inside this call and stores
        //        the resulting string list under a generated handle.  The iterator is
        //        Released by the server before the call returns.
        // @param iterator Input iterator to consume; ownership passes to the server.
        // @param id       Receives a unique handle for subsequent query calls.
        virtual Core::hresult RegisterStringIterator(
            RPC::IStringIterator* iterator /* @in */,
            uint32_t& id /* @out */) = 0;

        // @brief Hand an IValueIterator to the server for storage.
        //        The server drains the iterator immediately inside this call.
        // @param iterator Input iterator to consume; ownership passes to the server.
        // @param id       Receives a unique handle for subsequent query calls.
        virtual Core::hresult RegisterValueIterator(
            RPC::IValueIterator* iterator /* @in */,
            uint32_t& id /* @out */) = 0;

        // @brief Return the number of strings stored under the given handle.
        // @param id    Handle returned by RegisterStringIterator.
        // @param count Receives the element count.
        // @retval ERROR_NOT_EXIST id does not correspond to a registered iterator.
        virtual Core::hresult GetStringIteratorCount(const uint32_t id, uint32_t& count /* @out */) = 0;

        // @brief Return the first string stored under the given handle.
        // @param id    Handle returned by RegisterStringIterator.
        // @param value Receives the first element.
        // @retval ERROR_NOT_EXIST id is unknown or the stored list is empty.
        virtual Core::hresult GetStringIteratorFirst(const uint32_t id, string& value /* @out */) = 0;

        // @brief Determine whether the stored string list is empty.
        // @param id    Handle returned by RegisterStringIterator.
        // @param empty Receives true if the list has zero elements.
        // @retval ERROR_NOT_EXIST id does not correspond to a registered iterator.
        virtual Core::hresult IsStringIteratorEmpty(const uint32_t id, bool& empty /* @out */) = 0;

        // @brief Return the number of values stored under the given handle.
        // @param id    Handle returned by RegisterValueIterator.
        // @param count Receives the element count.
        // @retval ERROR_NOT_EXIST id does not correspond to a registered iterator.
        virtual Core::hresult GetValueIteratorCount(const uint32_t id, uint32_t& count /* @out */) = 0;

        // @brief Return the arithmetic sum of all values stored under the given handle.
        // @param id  Handle returned by RegisterValueIterator.
        // @param sum Receives the sum (0 for an empty list).
        // @retval ERROR_NOT_EXIST id does not correspond to a registered iterator.
        virtual Core::hresult GetValueIteratorSum(const uint32_t id, uint32_t& sum /* @out */) = 0;

        // @brief Return the first value stored under the given handle.
        // @param id    Handle returned by RegisterValueIterator.
        // @param value Receives the first element.
        // @retval ERROR_NOT_EXIST id is unknown or the stored list is empty.
        virtual Core::hresult GetValueIteratorFirst(const uint32_t id, uint32_t& value /* @out */) = 0;

        // @brief Release all data stored under the given handle.
        //        After this call the handle is invalid and must not be reused.
        // @param id Handle returned by RegisterStringIterator or RegisterValueIterator.
        // @retval ERROR_NOT_EXIST id does not correspond to a registered iterator.
        virtual Core::hresult UnregisterIterator(const uint32_t id) = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder