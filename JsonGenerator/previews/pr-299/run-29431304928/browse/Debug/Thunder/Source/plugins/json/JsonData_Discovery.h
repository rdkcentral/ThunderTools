// C++ types for Discovery API.
// Generated automatically from 'IController.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Discovery {

        // Method params/result classes
        //

        class DiscoveryResultData : public Core::JSON::Container {
        public:
            DiscoveryResultData()
                : Core::JSON::Container()
            {
                _Init();
            }

            DiscoveryResultData(const DiscoveryResultData& _other)
                : Core::JSON::Container()
                , Locator(_other.Locator)
                , Latency(_other.Latency)
                , Model(_other.Model)
                , Secure(_other.Secure)
            {
                _Init();
            }

            DiscoveryResultData(DiscoveryResultData&& _other) noexcept
                : Core::JSON::Container()
                , Locator(std::move(_other.Locator))
                , Latency(std::move(_other.Latency))
                , Model(std::move(_other.Model))
                , Secure(std::move(_other.Secure))
            {
                _Init();
            }

            DiscoveryResultData(const Exchange::Controller::IDiscovery::Data::DiscoveryResult& _other)
                : Core::JSON::Container()
            {
                Locator = _other.Locator;
                Latency = _other.Latency;
                if (_other.Model.IsSet() == true) {
                    Model = _other.Model.Value();
                }
                Secure = _other.Secure;
                _Init();
            }

            DiscoveryResultData& operator=(const DiscoveryResultData& _rhs)
            {
                Locator = _rhs.Locator;
                Latency = _rhs.Latency;
                if (_rhs.Model.IsSet() == true) {
                    Model = _rhs.Model;
                }
                Secure = _rhs.Secure;
                return (*this);
            }

            DiscoveryResultData& operator=(DiscoveryResultData&& _rhs) noexcept
            {
                Locator = std::move(_rhs.Locator);
                Latency = std::move(_rhs.Latency);
                Model = std::move(_rhs.Model);
                Secure = std::move(_rhs.Secure);
                return (*this);
            }

            DiscoveryResultData& operator=(const Exchange::Controller::IDiscovery::Data::DiscoveryResult& _rhs)
            {
                Locator = _rhs.Locator;
                Latency = _rhs.Latency;
                if (_rhs.Model.IsSet() == true) {
                    Model = _rhs.Model.Value();
                }
                Secure = _rhs.Secure;
                return (*this);
            }

            operator Exchange::Controller::IDiscovery::Data::DiscoveryResult() const
            {
                Exchange::Controller::IDiscovery::Data::DiscoveryResult _value{};
                _value.Locator = Locator;
                _value.Latency = Latency;
                if (Model.IsSet() == true) {
                    _value.Model = Model;
                }
                _value.Secure = Secure;
                return (_value);
            }

            ~DiscoveryResultData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Locator.IsSet() == true) && (Latency.IsSet() == true) && (Secure.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("locator"), &Locator);
                Add(_T("latency"), &Latency);
                Add(_T("model"), &Model);
                Add(_T("secure"), &Secure);
            }

        public:
            Core::JSON::String Locator; // Locator for the discovery
            Core::JSON::DecUInt32 Latency; // Latency for the discovery
            Core::JSON::String Model; // Model
            Core::JSON::Boolean Secure; // Secure or not
        }; // class DiscoveryResultData

        class StartDiscoveryParamsData : public Core::JSON::Container {
        public:
            StartDiscoveryParamsData()
                : Core::JSON::Container()
            {
                Add(_T("ttl"), &Ttl);
            }

            StartDiscoveryParamsData(const StartDiscoveryParamsData&) = delete;
            StartDiscoveryParamsData(StartDiscoveryParamsData&&) noexcept  = delete;

            StartDiscoveryParamsData& operator=(const StartDiscoveryParamsData&) = delete;
            StartDiscoveryParamsData& operator=(StartDiscoveryParamsData&&) noexcept  = delete;

            ~StartDiscoveryParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Ttl.IsSet() == false) || (Ttl.Value() >= 1 && Ttl.Value() <= 255));
            }

        public:
            Core::JSON::DecUInt8 Ttl; // Time to live, parameter for SSDP discovery
        }; // class StartDiscoveryParamsData

    } // namespace Discovery

    POP_WARNING()

} // namespace JsonData

}

