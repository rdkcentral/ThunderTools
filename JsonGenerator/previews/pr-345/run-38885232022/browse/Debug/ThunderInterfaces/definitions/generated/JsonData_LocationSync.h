// C++ types for LocationSync API.
// Generated automatically from 'ILocationSync.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/ILocationSync.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace LocationSync {

        // Method params/result classes
        //

        class LocationInfoData : public Core::JSON::Container {
        public:
            LocationInfoData()
                : Core::JSON::Container()
            {
                _Init();
            }

            LocationInfoData(const LocationInfoData& _other)
                : Core::JSON::Container()
                , City(_other.City)
                , Country(_other.Country)
                , Region(_other.Region)
                , TimeZone(_other.TimeZone)
                , PublicIP(_other.PublicIP)
            {
                _Init();
            }

            LocationInfoData(LocationInfoData&& _other) noexcept
                : Core::JSON::Container()
                , City(std::move(_other.City))
                , Country(std::move(_other.Country))
                , Region(std::move(_other.Region))
                , TimeZone(std::move(_other.TimeZone))
                , PublicIP(std::move(_other.PublicIP))
            {
                _Init();
            }

            LocationInfoData(const Exchange::ILocationSync::LocationInfo& _other)
                : Core::JSON::Container()
            {
                if (_other.city.IsSet() == true) {
                    City = _other.city.Value();
                }
                if (_other.country.IsSet() == true) {
                    Country = _other.country.Value();
                }
                if (_other.region.IsSet() == true) {
                    Region = _other.region.Value();
                }
                if (_other.timeZone.IsSet() == true) {
                    TimeZone = _other.timeZone.Value();
                }
                if (_other.publicIP.IsSet() == true) {
                    PublicIP = _other.publicIP.Value();
                }
                _Init();
            }

            LocationInfoData& operator=(const LocationInfoData& _rhs)
            {
                if (_rhs.City.IsSet() == true) {
                    City = _rhs.City;
                }
                if (_rhs.Country.IsSet() == true) {
                    Country = _rhs.Country;
                }
                if (_rhs.Region.IsSet() == true) {
                    Region = _rhs.Region;
                }
                if (_rhs.TimeZone.IsSet() == true) {
                    TimeZone = _rhs.TimeZone;
                }
                if (_rhs.PublicIP.IsSet() == true) {
                    PublicIP = _rhs.PublicIP;
                }
                return (*this);
            }

            LocationInfoData& operator=(LocationInfoData&& _rhs) noexcept
            {
                City = std::move(_rhs.City);
                Country = std::move(_rhs.Country);
                Region = std::move(_rhs.Region);
                TimeZone = std::move(_rhs.TimeZone);
                PublicIP = std::move(_rhs.PublicIP);
                return (*this);
            }

            LocationInfoData& operator=(const Exchange::ILocationSync::LocationInfo& _rhs)
            {
                if (_rhs.city.IsSet() == true) {
                    City = _rhs.city.Value();
                }
                if (_rhs.country.IsSet() == true) {
                    Country = _rhs.country.Value();
                }
                if (_rhs.region.IsSet() == true) {
                    Region = _rhs.region.Value();
                }
                if (_rhs.timeZone.IsSet() == true) {
                    TimeZone = _rhs.timeZone.Value();
                }
                if (_rhs.publicIP.IsSet() == true) {
                    PublicIP = _rhs.publicIP.Value();
                }
                return (*this);
            }

            operator Exchange::ILocationSync::LocationInfo() const
            {
                Exchange::ILocationSync::LocationInfo _value{};
                if (City.IsSet() == true) {
                    _value.city = City;
                }
                if (Country.IsSet() == true) {
                    _value.country = Country;
                }
                if (Region.IsSet() == true) {
                    _value.region = Region;
                }
                if (TimeZone.IsSet() == true) {
                    _value.timeZone = TimeZone;
                }
                if (PublicIP.IsSet() == true) {
                    _value.publicIP = PublicIP;
                }
                return (_value);
            }

            ~LocationInfoData() = default;

        public:
            bool IsDataValid() const
            {
                return (true);
            }

        private:
            void _Init()
            {
                Add(_T("city"), &City);
                Add(_T("country"), &Country);
                Add(_T("region"), &Region);
                Add(_T("timezone"), &TimeZone);
                Add(_T("publicip"), &PublicIP);
            }

        public:
            Core::JSON::String City; // City name
            Core::JSON::String Country; // Country name
            Core::JSON::String Region; // Region name
            Core::JSON::String TimeZone; // Time zone information
            Core::JSON::String PublicIP; // Public IP
        }; // class LocationInfoData

    } // namespace LocationSync

    POP_WARNING()

} // namespace JsonData

}

