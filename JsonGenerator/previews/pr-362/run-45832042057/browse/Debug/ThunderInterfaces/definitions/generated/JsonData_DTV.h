// C++ types for DTV API.
// Generated automatically from 'DTV.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace DTV {

        // Common enums
        //

        // Video or audio codec type
        enum class CodecType : uint8_t {
            MPEG2,
            H264,
            H265,
            AVS,
            MPEG1,
            AAC,
            HEAAC,
            HEAACV2,
            AC3,
            EAC3
        };

        // Diseqc cswitch
        enum class Diseqc_cswitchType : uint8_t {
            OFF,
            A,
            B,
            C,
            D
        };

        // Diseqc Tone
        enum class Diseqc_toneType : uint8_t {
            OFF,
            A,
            B
        };

        // DVB C Modulation supported by the platform
        enum class DvbcmodulationType : uint8_t {
            AUTO,
            E4QAM,
            E8QAM,
            E16QAM,
            E32QAM,
            E64QAM,
            E128QAM,
            E256QAM
        };

        // DVB S Modulation supported by the platform
        enum class DvbsmodulationType : uint8_t {
            AUTO,
            QPSK,
            E8PSK,
            E16QAM
        };

        // Channel bandwidth
        enum class DvbtbandwidthType : uint8_t {
            E5MHZ,
            E6MHZ,
            E7MHZ,
            E8MHZ,
            E10MHZ,
            UNDEFINED
        };

        // Event type that's sent as an asynchronous notification
        enum class EventtypeType : uint8_t {
            SERVICESEARCHSTATUS,
            SERVICEUPDATED,
            SERVICEADDED,
            SERVICEDELETED,
            VIDEOCHANGED,
            AUDIOCHANGED,
            SUBTITLESCHANGED,
            EVENTCHANGED
        };

        // Forward error correction setting
        enum class FecType : uint8_t {
            FECAUTO,
            FEC1_2,
            FEC2_3,
            FEC3_4,
            FEC5_6,
            FEC7_8,
            FEC1_4,
            FEC1_3,
            FEC2_5,
            FEC8_9,
            FEC9_10,
            FEC3_5,
            FEC4_5
        };

        // LNB power values
        enum class LnbpowerType : uint8_t {
            OFF,
            ON,
            AUTO
        };

        // LNB type
        enum class LnbtypeType : uint8_t {
            SINGLE,
            UNIVERSAL,
            UNICABLE
        };

        // OFDM mode
        enum class OfdmmodeType : uint8_t {
            OFDM_1K,
            OFDM_2K,
            OFDM_4K,
            OFDM_8K,
            OFDM_16K,
            OFDM_32K,
            UNDEFINED
        };

        // Polarity setting
        enum class PolarityType : uint8_t {
            HORIZONTAL,
            VERTICAL,
            LEFT,
            RIGHT
        };

        // (Version 2) The running status as given by the service descriptor in the SDT
        enum class RunningstatusType : uint8_t {
            UNDEFINED,
            NOTRUNNING,
            STARTSSOON,
            PAUSING,
            RUNNING,
            OFFAIR
        };

        // (Version 2) Service type as given by the service descriptor in the SDT
        enum class ServicetypeType : uint8_t {
            TV,
            RADIO,
            TELETEXT,
            NVOD,
            NVOD_TIMESHIFT,
            MOSAIC,
            AVC_RADIO,
            AVC_MOSAIC,
            DATA,
            MPEG2_HD,
            AVC_SD_TV,
            AVC_SD_NVOD_TIMESHIFT,
            AVC_SD_NVOD,
            HD_TV,
            AVC_HD_NVOD_TIMESHIFT,
            AVC_HD_NVOD,
            UHD_TV,
            UNKNOWN
        };

        // Tuner type
        enum class TunertypeType : uint8_t {
            NONE = 0,
            DVBS = 1,
            DVBT = 2,
            DVBC = 4
        };

        // Common classes
        //

        class DvbctuningparamsInfo : public Core::JSON::Container {
        public:
            DvbctuningparamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("frequency"), &Frequency);
                Add(_T("symbolrate"), &Symbolrate);
                Add(_T("modulation"), &Modulation);
            }

            DvbctuningparamsInfo(const DvbctuningparamsInfo&) = delete;
            DvbctuningparamsInfo(DvbctuningparamsInfo&&) noexcept  = delete;

            DvbctuningparamsInfo& operator=(const DvbctuningparamsInfo&) = delete;
            DvbctuningparamsInfo& operator=(DvbctuningparamsInfo&&) noexcept  = delete;

            ~DvbctuningparamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Frequency.IsSet() == true) && (Symbolrate.IsSet() == true) && (Modulation.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt32 Frequency; // Frequency of the transport, in Hz
            Core::JSON::DecUInt16 Symbolrate; // Symbol rate in Ksymb/sec
            Core::JSON::EnumType<DvbcmodulationType> Modulation; // DVB C Modulation supported by the platform
        }; // class DvbctuningparamsInfo

        class DvbstuningparamsInfo : public Core::JSON::Container {
        public:
            DvbstuningparamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("satellite"), &Satellite);
                Add(_T("frequency"), &Frequency);
                Add(_T("polarity"), &Polarity);
                Add(_T("symbolrate"), &Symbolrate);
                Add(_T("fec"), &Fec);
                Add(_T("modulation"), &Modulation);
                Add(_T("dvbs2"), &Dvbs2);
            }

            DvbstuningparamsInfo(const DvbstuningparamsInfo&) = delete;
            DvbstuningparamsInfo(DvbstuningparamsInfo&&) noexcept  = delete;

            DvbstuningparamsInfo& operator=(const DvbstuningparamsInfo&) = delete;
            DvbstuningparamsInfo& operator=(DvbstuningparamsInfo&&) noexcept  = delete;

            ~DvbstuningparamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Satellite.IsSet() == true) && (Frequency.IsSet() == true) && (Polarity.IsSet() == true) && (Symbolrate.IsSet() == true) && (Fec.IsSet() == true) && (Modulation.IsSet() == true) && (Dvbs2.IsSet() == true));
            }

        public:
            Core::JSON::String Satellite; // Name of the satellite settings to be used
            Core::JSON::DecUInt32 Frequency; // Frequency of the transponder, in kHz
            Core::JSON::EnumType<PolarityType> Polarity; // Polarity setting
            Core::JSON::DecUInt16 Symbolrate; // Symbol rate in Ksymb/sec
            Core::JSON::EnumType<FecType> Fec; // Forward error correction setting
            Core::JSON::EnumType<DvbsmodulationType> Modulation; // DVB S Modulation supported by the platform
            Core::JSON::Boolean Dvbs2; // True when tuning to a DVB-S2 signal
        }; // class DvbstuningparamsInfo

        class DvbttuningparamsInfo : public Core::JSON::Container {
        public:
            DvbttuningparamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("frequency"), &Frequency);
                Add(_T("bandwidth"), &Bandwidth);
                Add(_T("mode"), &Mode);
                Add(_T("dvbt2"), &Dvbt2);
                Add(_T("plpid"), &Plpid);
            }

            DvbttuningparamsInfo(const DvbttuningparamsInfo&) = delete;
            DvbttuningparamsInfo(DvbttuningparamsInfo&&) noexcept  = delete;

            DvbttuningparamsInfo& operator=(const DvbttuningparamsInfo&) = delete;
            DvbttuningparamsInfo& operator=(DvbttuningparamsInfo&&) noexcept  = delete;

            ~DvbttuningparamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Frequency.IsSet() == true) && (Bandwidth.IsSet() == true) && (Mode.IsSet() == true) && (Dvbt2.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt32 Frequency; // Frequency of the transport, in Hz
            Core::JSON::EnumType<DvbtbandwidthType> Bandwidth; // Channel bandwidth
            Core::JSON::EnumType<OfdmmodeType> Mode; // OFDM mode
            Core::JSON::Boolean Dvbt2; // True when tuning to a DVB-T2 signal
            Core::JSON::DecUInt8 Plpid; // PLP ID for tuning to a DVB-T2 signal
        }; // class DvbttuningparamsInfo

        class EiteventInfo : public Core::JSON::Container {
        public:
            EiteventInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            EiteventInfo(const EiteventInfo& _other)
                : Core::JSON::Container()
                , Name(_other.Name)
                , Starttime(_other.Starttime)
                , Duration(_other.Duration)
                , Eventid(_other.Eventid)
                , Shortdescription(_other.Shortdescription)
                , Hassubtitles(_other.Hassubtitles)
                , Hasaudiodescription(_other.Hasaudiodescription)
                , Parentalrating(_other.Parentalrating)
                , Contentdata(_other.Contentdata)
                , Hasextendedinfo(_other.Hasextendedinfo)
            {
                _Init();
            }

            EiteventInfo(EiteventInfo&& _other) noexcept
                : Core::JSON::Container()
                , Name(std::move(_other.Name))
                , Starttime(std::move(_other.Starttime))
                , Duration(std::move(_other.Duration))
                , Eventid(std::move(_other.Eventid))
                , Shortdescription(std::move(_other.Shortdescription))
                , Hassubtitles(std::move(_other.Hassubtitles))
                , Hasaudiodescription(std::move(_other.Hasaudiodescription))
                , Parentalrating(std::move(_other.Parentalrating))
                , Contentdata(std::move(_other.Contentdata))
                , Hasextendedinfo(std::move(_other.Hasextendedinfo))
            {
                _Init();
            }

            EiteventInfo& operator=(const EiteventInfo& _rhs)
            {
                Name = _rhs.Name;
                Starttime = _rhs.Starttime;
                Duration = _rhs.Duration;
                Eventid = _rhs.Eventid;
                Shortdescription = _rhs.Shortdescription;
                Hassubtitles = _rhs.Hassubtitles;
                Hasaudiodescription = _rhs.Hasaudiodescription;
                Parentalrating = _rhs.Parentalrating;
                Contentdata = _rhs.Contentdata;
                Hasextendedinfo = _rhs.Hasextendedinfo;
                return (*this);
            }

            EiteventInfo& operator=(EiteventInfo&& _rhs) noexcept
            {
                Name = std::move(_rhs.Name);
                Starttime = std::move(_rhs.Starttime);
                Duration = std::move(_rhs.Duration);
                Eventid = std::move(_rhs.Eventid);
                Shortdescription = std::move(_rhs.Shortdescription);
                Hassubtitles = std::move(_rhs.Hassubtitles);
                Hasaudiodescription = std::move(_rhs.Hasaudiodescription);
                Parentalrating = std::move(_rhs.Parentalrating);
                Contentdata = std::move(_rhs.Contentdata);
                Hasextendedinfo = std::move(_rhs.Hasextendedinfo);
                return (*this);
            }

            ~EiteventInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Name.IsSet() == true) && (Starttime.IsSet() == true) && (Duration.IsSet() == true) && (Eventid.IsSet() == true) && (Shortdescription.IsSet() == true) && (Hassubtitles.IsSet() == true) && (Hasaudiodescription.IsSet() == true) && (Parentalrating.IsSet() == true) && (Contentdata.IsSet() == true) && (Hasextendedinfo.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("name"), &Name);
                Add(_T("starttime"), &Starttime);
                Add(_T("duration"), &Duration);
                Add(_T("eventid"), &Eventid);
                Add(_T("shortdescription"), &Shortdescription);
                Add(_T("hassubtitles"), &Hassubtitles);
                Add(_T("hasaudiodescription"), &Hasaudiodescription);
                Add(_T("parentalrating"), &Parentalrating);
                Add(_T("contentdata"), &Contentdata);
                Add(_T("hasextendedinfo"), &Hasextendedinfo);
            }

        public:
            Core::JSON::String Name; // Name of the DVB event as defined in the short event descriptor
            Core::JSON::DecUInt32 Starttime; // UTC start time of the event in seconds
            Core::JSON::DecUInt32 Duration; // Duration of the event in seconds
            Core::JSON::DecUInt16 Eventid; // ID of the event from the event information table
            Core::JSON::String Shortdescription; // Event description from the EIT short event descriptor
            Core::JSON::Boolean Hassubtitles; // (Version 2) True if subtitles are available
            Core::JSON::Boolean Hasaudiodescription; // (Version 2) True if audio description is available
            Core::JSON::DecUInt8 Parentalrating; // (Version 2) Parental rating for the event, will be 0 if undefined
            Core::JSON::ArrayType<Core::JSON::DecUInt8> Contentdata; // (Version 2) The first 2 4-bit values from the content descriptor as separate bytes
            Core::JSON::Boolean Hasextendedinfo; // (Version 2) True if there's extended event information available
        }; // class EiteventInfo

        class LnbsettingsInfo : public Core::JSON::Container {
        public:
            LnbsettingsInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            LnbsettingsInfo(const LnbsettingsInfo& _other)
                : Core::JSON::Container()
                , Name(_other.Name)
                , Type(_other.Type)
                , Power(_other.Power)
                , Diseqc_tone(_other.Diseqc_tone)
                , Diseqc_cswitch(_other.Diseqc_cswitch)
                , Is22k(_other.Is22k)
                , Is12v(_other.Is12v)
                , Ispulseposition(_other.Ispulseposition)
                , Isdiseqcposition(_other.Isdiseqcposition)
                , Issmatv(_other.Issmatv)
                , Diseqcrepeats(_other.Diseqcrepeats)
                , U_switch(_other.U_switch)
                , Unicablechannel(_other.Unicablechannel)
                , Unicablefreq(_other.Unicablefreq)
            {
                _Init();
            }

            LnbsettingsInfo(LnbsettingsInfo&& _other) noexcept
                : Core::JSON::Container()
                , Name(std::move(_other.Name))
                , Type(std::move(_other.Type))
                , Power(std::move(_other.Power))
                , Diseqc_tone(std::move(_other.Diseqc_tone))
                , Diseqc_cswitch(std::move(_other.Diseqc_cswitch))
                , Is22k(std::move(_other.Is22k))
                , Is12v(std::move(_other.Is12v))
                , Ispulseposition(std::move(_other.Ispulseposition))
                , Isdiseqcposition(std::move(_other.Isdiseqcposition))
                , Issmatv(std::move(_other.Issmatv))
                , Diseqcrepeats(std::move(_other.Diseqcrepeats))
                , U_switch(std::move(_other.U_switch))
                , Unicablechannel(std::move(_other.Unicablechannel))
                , Unicablefreq(std::move(_other.Unicablefreq))
            {
                _Init();
            }

            LnbsettingsInfo& operator=(const LnbsettingsInfo& _rhs)
            {
                Name = _rhs.Name;
                Type = _rhs.Type;
                Power = _rhs.Power;
                Diseqc_tone = _rhs.Diseqc_tone;
                Diseqc_cswitch = _rhs.Diseqc_cswitch;
                Is22k = _rhs.Is22k;
                Is12v = _rhs.Is12v;
                Ispulseposition = _rhs.Ispulseposition;
                Isdiseqcposition = _rhs.Isdiseqcposition;
                Issmatv = _rhs.Issmatv;
                Diseqcrepeats = _rhs.Diseqcrepeats;
                U_switch = _rhs.U_switch;
                Unicablechannel = _rhs.Unicablechannel;
                if (_rhs.Unicablefreq != 0) {
                    Unicablefreq = _rhs.Unicablefreq;
                }
                return (*this);
            }

            LnbsettingsInfo& operator=(LnbsettingsInfo&& _rhs) noexcept
            {
                Name = std::move(_rhs.Name);
                Type = std::move(_rhs.Type);
                Power = std::move(_rhs.Power);
                Diseqc_tone = std::move(_rhs.Diseqc_tone);
                Diseqc_cswitch = std::move(_rhs.Diseqc_cswitch);
                Is22k = std::move(_rhs.Is22k);
                Is12v = std::move(_rhs.Is12v);
                Ispulseposition = std::move(_rhs.Ispulseposition);
                Isdiseqcposition = std::move(_rhs.Isdiseqcposition);
                Issmatv = std::move(_rhs.Issmatv);
                Diseqcrepeats = std::move(_rhs.Diseqcrepeats);
                U_switch = std::move(_rhs.U_switch);
                Unicablechannel = std::move(_rhs.Unicablechannel);
                Unicablefreq = std::move(_rhs.Unicablefreq);
                return (*this);
            }

            ~LnbsettingsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Name.IsSet() == true) && (Type.IsSet() == true) && (Power.IsSet() == true) && (Diseqc_tone.IsSet() == true) && (Diseqc_cswitch.IsSet() == true) && (Is22k.IsSet() == true) && (Is12v.IsSet() == true) && (Ispulseposition.IsSet() == true) && (Isdiseqcposition.IsSet() == true) && (Issmatv.IsSet() == true) && (Diseqcrepeats.IsSet() == true) && (U_switch.IsSet() == true) && (Unicablechannel.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("name"), &Name);
                Add(_T("type"), &Type);
                Add(_T("power"), &Power);
                Add(_T("diseqc_tone"), &Diseqc_tone);
                Add(_T("diseqc_cswitch"), &Diseqc_cswitch);
                Add(_T("is22k"), &Is22k);
                Add(_T("is12v"), &Is12v);
                Add(_T("ispulseposition"), &Ispulseposition);
                Add(_T("isdiseqcposition"), &Isdiseqcposition);
                Add(_T("issmatv"), &Issmatv);
                Add(_T("diseqcrepeats"), &Diseqcrepeats);
                Add(_T("u_switch"), &U_switch);
                Add(_T("unicablechannel"), &Unicablechannel);
                Add(_T("unicablefreq"), &Unicablefreq);
            }

        public:
            Core::JSON::String Name; // User specified name for the LNB settings
            Core::JSON::EnumType<LnbtypeType> Type; // LNB type
            Core::JSON::EnumType<LnbpowerType> Power; // LNB power values
            Core::JSON::EnumType<Diseqc_toneType> Diseqc_tone; // Diseqc Tone
            Core::JSON::EnumType<Diseqc_cswitchType> Diseqc_cswitch; // Diseqc cswitch
            Core::JSON::Boolean Is22k; // 22kHz tone on/off
            Core::JSON::Boolean Is12v; // 12 volts on/off
            Core::JSON::Boolean Ispulseposition; // Pulse position motor used to control dish position
            Core::JSON::Boolean Isdiseqcposition; // Dish positioning is controlled by DiSEqC
            Core::JSON::Boolean Issmatv; // SMATV switcher on/off
            Core::JSON::DecUInt8 Diseqcrepeats; // Number of times to send a DiSEqC message to make sure it's been received
            Core::JSON::DecUInt8 U_switch; // DiSEqC uncommitted switch selector
            Core::JSON::DecUInt8 Unicablechannel; // Unicable channel
            Core::JSON::DecUInt32 Unicablefreq; // Unicable frequency
        }; // class LnbsettingsInfo

        class SatellitesettingsInfo : public Core::JSON::Container {
        public:
            SatellitesettingsInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            SatellitesettingsInfo(const SatellitesettingsInfo& _other)
                : Core::JSON::Container()
                , Name(_other.Name)
                , Longitude(_other.Longitude)
                , Lnb(_other.Lnb)
            {
                _Init();
            }

            SatellitesettingsInfo(SatellitesettingsInfo&& _other) noexcept
                : Core::JSON::Container()
                , Name(std::move(_other.Name))
                , Longitude(std::move(_other.Longitude))
                , Lnb(std::move(_other.Lnb))
            {
                _Init();
            }

            SatellitesettingsInfo& operator=(const SatellitesettingsInfo& _rhs)
            {
                Name = _rhs.Name;
                Longitude = _rhs.Longitude;
                Lnb = _rhs.Lnb;
                return (*this);
            }

            SatellitesettingsInfo& operator=(SatellitesettingsInfo&& _rhs) noexcept
            {
                Name = std::move(_rhs.Name);
                Longitude = std::move(_rhs.Longitude);
                Lnb = std::move(_rhs.Lnb);
                return (*this);
            }

            ~SatellitesettingsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Name.IsSet() == true) && (Longitude.IsSet() == true) && (Lnb.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("name"), &Name);
                Add(_T("longitude"), &Longitude);
                Add(_T("lnb"), &Lnb);
            }

        public:
            Core::JSON::String Name; // User specified name for the satellite settings
            Core::JSON::DecSInt16 Longitude; // Longitudinal location of the satellite in 1/10ths of a degree, with an east coordinate given as a positive value and a west coordinate as negative. Astra 28.2E would be defined as 282 and Eutelsat 5.0W would be -50.
            Core::JSON::String Lnb; // Name of the LNB settings to be used when tuning to this satellite
        }; // class SatellitesettingsInfo

        class ServiceInfo : public Core::JSON::Container {
        public:
            ServiceInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            ServiceInfo(const ServiceInfo& _other)
                : Core::JSON::Container()
                , Fullname(_other.Fullname)
                , Shortname(_other.Shortname)
                , Dvburi(_other.Dvburi)
                , Servicetype(_other.Servicetype)
                , Lcn(_other.Lcn)
                , Scrambled(_other.Scrambled)
                , Hascadescriptor(_other.Hascadescriptor)
                , Hidden(_other.Hidden)
                , Selectable(_other.Selectable)
                , Runningstatus(_other.Runningstatus)
            {
                _Init();
            }

            ServiceInfo(ServiceInfo&& _other) noexcept
                : Core::JSON::Container()
                , Fullname(std::move(_other.Fullname))
                , Shortname(std::move(_other.Shortname))
                , Dvburi(std::move(_other.Dvburi))
                , Servicetype(std::move(_other.Servicetype))
                , Lcn(std::move(_other.Lcn))
                , Scrambled(std::move(_other.Scrambled))
                , Hascadescriptor(std::move(_other.Hascadescriptor))
                , Hidden(std::move(_other.Hidden))
                , Selectable(std::move(_other.Selectable))
                , Runningstatus(std::move(_other.Runningstatus))
            {
                _Init();
            }

            ServiceInfo& operator=(const ServiceInfo& _rhs)
            {
                Fullname = _rhs.Fullname;
                Shortname = _rhs.Shortname;
                Dvburi = _rhs.Dvburi;
                Servicetype = _rhs.Servicetype;
                Lcn = _rhs.Lcn;
                Scrambled = _rhs.Scrambled;
                Hascadescriptor = _rhs.Hascadescriptor;
                Hidden = _rhs.Hidden;
                Selectable = _rhs.Selectable;
                Runningstatus = _rhs.Runningstatus;
                return (*this);
            }

            ServiceInfo& operator=(ServiceInfo&& _rhs) noexcept
            {
                Fullname = std::move(_rhs.Fullname);
                Shortname = std::move(_rhs.Shortname);
                Dvburi = std::move(_rhs.Dvburi);
                Servicetype = std::move(_rhs.Servicetype);
                Lcn = std::move(_rhs.Lcn);
                Scrambled = std::move(_rhs.Scrambled);
                Hascadescriptor = std::move(_rhs.Hascadescriptor);
                Hidden = std::move(_rhs.Hidden);
                Selectable = std::move(_rhs.Selectable);
                Runningstatus = std::move(_rhs.Runningstatus);
                return (*this);
            }

            ~ServiceInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Fullname.IsSet() == true) && (Shortname.IsSet() == true) && (Dvburi.IsSet() == true) && (Servicetype.IsSet() == true) && (Lcn.IsSet() == true) && (Scrambled.IsSet() == true) && (Hascadescriptor.IsSet() == true) && (Hidden.IsSet() == true) && (Selectable.IsSet() == true) && (Runningstatus.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("fullname"), &Fullname);
                Add(_T("shortname"), &Shortname);
                Add(_T("dvburi"), &Dvburi);
                Add(_T("servicetype"), &Servicetype);
                Add(_T("lcn"), &Lcn);
                Add(_T("scrambled"), &Scrambled);
                Add(_T("hascadescriptor"), &Hascadescriptor);
                Add(_T("hidden"), &Hidden);
                Add(_T("selectable"), &Selectable);
                Add(_T("runningstatus"), &Runningstatus);
            }

        public:
            Core::JSON::String Fullname; // (Version 2) Full service name as given by the service descriptor in the SDT
            Core::JSON::String Shortname; // Short service name as given by the service descriptor in the SDT
            Core::JSON::String Dvburi; // DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal
            Core::JSON::EnumType<ServicetypeType> Servicetype; // (Version 2) Service type as given by the service descriptor in the SDT
            Core::JSON::DecUInt16 Lcn; // Logical channel number
            Core::JSON::Boolean Scrambled; // (Version 2) True if the service is marked as scrambled in the SDT
            Core::JSON::Boolean Hascadescriptor; // (Version 2) True if there is at least one CA descriptor in the service's PMT
            Core::JSON::Boolean Hidden; // (Version 2) True if the service should be hidden
            Core::JSON::Boolean Selectable; // (Version 2) True if the service should be user selectable
            Core::JSON::EnumType<RunningstatusType> Runningstatus; // (Version 2) The running status as given by the service descriptor in the SDT
        }; // class ServiceInfo

        class ServiceupdatedParamsInfo : public Core::JSON::Container {
        public:
            ServiceupdatedParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("eventtype"), &Eventtype);
                Add(_T("service"), &Service);
            }

            ServiceupdatedParamsInfo(const ServiceupdatedParamsInfo&) = delete;
            ServiceupdatedParamsInfo(ServiceupdatedParamsInfo&&) noexcept  = delete;

            ServiceupdatedParamsInfo& operator=(const ServiceupdatedParamsInfo&) = delete;
            ServiceupdatedParamsInfo& operator=(ServiceupdatedParamsInfo&&) noexcept  = delete;

            ~ServiceupdatedParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Eventtype.IsSet() == true) && ((Service.IsSet() == true) && (Service.IsDataValid() == true)));
            }

        public:
            Core::JSON::EnumType<EventtypeType> Eventtype; // Event type that's sent as an asynchronous notification
            ServiceInfo Service; // Service information
        }; // class ServiceupdatedParamsInfo

        class TransportInfo : public Core::JSON::Container {
        public:
            TransportInfo()
                : Core::JSON::Container()
            {
                Add(_T("tunertype"), &Tunertype);
                Add(_T("originalnetworkid"), &Originalnetworkid);
                Add(_T("transportid"), &Transportid);
                Add(_T("strength"), &Strength);
                Add(_T("quality"), &Quality);
                Add(_T("dvbctuningparams"), &Dvbctuningparams);
                Add(_T("dvbstuningparams"), &Dvbstuningparams);
                Add(_T("dvbttuningparams"), &Dvbttuningparams);
            }

            TransportInfo(const TransportInfo&) = delete;
            TransportInfo(TransportInfo&&) noexcept  = delete;

            TransportInfo& operator=(const TransportInfo&) = delete;
            TransportInfo& operator=(TransportInfo&&) noexcept  = delete;

            ~TransportInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Tunertype.IsSet() == true) && (Originalnetworkid.IsSet() == true) && (Transportid.IsSet() == true) && (Strength.IsSet() == true) && (Quality.IsSet() == true) && ((Dvbctuningparams.IsSet() == false) || (Dvbctuningparams.IsDataValid() == true)) && ((Dvbstuningparams.IsSet() == false) || (Dvbstuningparams.IsDataValid() == true)) && ((Dvbttuningparams.IsSet() == false) || (Dvbttuningparams.IsDataValid() == true)));
            }

        public:
            Core::JSON::EnumType<TunertypeType> Tunertype; // Tuner type
            Core::JSON::DecUInt16 Originalnetworkid; // Original network ID of the transport
            Core::JSON::DecUInt16 Transportid; // Transport ID of the transport
            Core::JSON::DecUInt8 Strength; // Signal strength as a percentage
            Core::JSON::DecUInt8 Quality; // Signal quality as a percentage
            DvbctuningparamsInfo Dvbctuningparams; // Parameters required to tune to a DVB-C signal
            DvbstuningparamsInfo Dvbstuningparams; // Parameters required to tune to a DVB-S/S2 signal
            DvbttuningparamsInfo Dvbttuningparams; // Parameters required to tune to a DVB-T/T2 signal
        }; // class TransportInfo

        // Method params/result classes
        //

        class CountryconfigData : public Core::JSON::Container {
        public:
            CountryconfigData()
                : Core::JSON::Container()
            {
                _Init();
            }

            CountryconfigData(const CountryconfigData& _other)
                : Core::JSON::Container()
                , Name(_other.Name)
                , Code(_other.Code)
            {
                _Init();
            }

            CountryconfigData(CountryconfigData&& _other) noexcept
                : Core::JSON::Container()
                , Name(std::move(_other.Name))
                , Code(std::move(_other.Code))
            {
                _Init();
            }

            CountryconfigData& operator=(const CountryconfigData& _rhs)
            {
                Name = _rhs.Name;
                Code = _rhs.Code;
                return (*this);
            }

            CountryconfigData& operator=(CountryconfigData&& _rhs) noexcept
            {
                Name = std::move(_rhs.Name);
                Code = std::move(_rhs.Code);
                return (*this);
            }

            ~CountryconfigData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Name.IsSet() == true) && (Code.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("name"), &Name);
                Add(_T("code"), &Code);
            }

        public:
            Core::JSON::String Name; // Name of the country as a UTF-8 string
            Core::JSON::DecUInt32 Code; // 3-character ISO code for the country
        }; // class CountryconfigData

        class EventchangedParamsData : public Core::JSON::Container {
        public:
            EventchangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("eventtype"), &Eventtype);
                Add(_T("service"), &Service);
                Add(_T("event"), &Event);
            }

            EventchangedParamsData(const EventchangedParamsData&) = delete;
            EventchangedParamsData(EventchangedParamsData&&) noexcept  = delete;

            EventchangedParamsData& operator=(const EventchangedParamsData&) = delete;
            EventchangedParamsData& operator=(EventchangedParamsData&&) noexcept  = delete;

            ~EventchangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Eventtype.IsSet() == true) && ((Service.IsSet() == true) && (Service.IsDataValid() == true)) && ((Event.IsSet() == true) && (Event.IsDataValid() == true)));
            }

        public:
            Core::JSON::EnumType<EventtypeType> Eventtype; // Event type that's sent as an asynchronous notification
            ServiceInfo Service; // Service information
            EiteventInfo Event; // EIT event information
        }; // class EventchangedParamsData

        class ExtendedeventinfoData : public Core::JSON::Container {
        public:
            class ExtendedeventitemData : public Core::JSON::Container {
            public:
                ExtendedeventitemData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                ExtendedeventitemData(const ExtendedeventitemData& _other)
                    : Core::JSON::Container()
                    , Description(_other.Description)
                    , Item(_other.Item)
                {
                    _Init();
                }

                ExtendedeventitemData(ExtendedeventitemData&& _other) noexcept
                    : Core::JSON::Container()
                    , Description(std::move(_other.Description))
                    , Item(std::move(_other.Item))
                {
                    _Init();
                }

                ExtendedeventitemData& operator=(const ExtendedeventitemData& _rhs)
                {
                    Description = _rhs.Description;
                    Item = _rhs.Item;
                    return (*this);
                }

                ExtendedeventitemData& operator=(ExtendedeventitemData&& _rhs) noexcept
                {
                    Description = std::move(_rhs.Description);
                    Item = std::move(_rhs.Item);
                    return (*this);
                }

                ~ExtendedeventitemData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Description.IsSet() == true) && (Item.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("description"), &Description);
                    Add(_T("item"), &Item);
                }

            public:
                Core::JSON::String Description; // Description of the item
                Core::JSON::String Item; // Item text
            }; // class ExtendedeventitemData

            ExtendedeventinfoData()
                : Core::JSON::Container()
            {
                Add(_T("description"), &Description);
                Add(_T("items"), &Items);
            }

            ExtendedeventinfoData(const ExtendedeventinfoData&) = delete;
            ExtendedeventinfoData(ExtendedeventinfoData&&) noexcept  = delete;

            ExtendedeventinfoData& operator=(const ExtendedeventinfoData&) = delete;
            ExtendedeventinfoData& operator=(ExtendedeventinfoData&&) noexcept  = delete;

            ~ExtendedeventinfoData() = default;

        public:
            bool IsDataValid() const
            {
                return (true);
            }

        public:
            Core::JSON::String Description; // Extended event description text
            Core::JSON::ArrayType<ExtendedeventinfoData::ExtendedeventitemData> Items; // An array of extended event item
        }; // class ExtendedeventinfoData

        class FinishServiceSearchParamsData : public Core::JSON::Container {
        public:
            FinishServiceSearchParamsData()
                : Core::JSON::Container()
            {
                Add(_T("tunertype"), &Tunertype);
                Add(_T("savechanges"), &Savechanges);
            }

            FinishServiceSearchParamsData(const FinishServiceSearchParamsData&) = delete;
            FinishServiceSearchParamsData(FinishServiceSearchParamsData&&) noexcept  = delete;

            FinishServiceSearchParamsData& operator=(const FinishServiceSearchParamsData&) = delete;
            FinishServiceSearchParamsData& operator=(FinishServiceSearchParamsData&&) noexcept  = delete;

            ~FinishServiceSearchParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Tunertype.IsSet() == true) && (Savechanges.IsSet() == true));
            }

        public:
            Core::JSON::EnumType<TunertypeType> Tunertype; // Tuner type
            Core::JSON::Boolean Savechanges; // Set true if the services found during the search should be saved
        }; // class FinishServiceSearchParamsData

        class NowNextEventsData : public Core::JSON::Container {
        public:
            NowNextEventsData()
                : Core::JSON::Container()
            {
                Add(_T("now"), &Now);
                Add(_T("next"), &Next);
            }

            NowNextEventsData(const NowNextEventsData&) = delete;
            NowNextEventsData(NowNextEventsData&&) noexcept  = delete;

            NowNextEventsData& operator=(const NowNextEventsData&) = delete;
            NowNextEventsData& operator=(NowNextEventsData&&) noexcept  = delete;

            ~NowNextEventsData() = default;

        public:
            bool IsDataValid() const
            {
                return (((Now.IsSet() == false) || (Now.IsDataValid() == true)) && ((Next.IsSet() == false) || (Next.IsDataValid() == true)));
            }

        public:
            EiteventInfo Now; // EIT event information
            EiteventInfo Next; // EIT event information
        }; // class NowNextEventsData

        class SearchstatusParamsData : public Core::JSON::Container {
        public:
            SearchstatusParamsData()
                : Core::JSON::Container()
            {
                Add(_T("handle"), &Handle);
                Add(_T("eventtype"), &Eventtype);
                Add(_T("finished"), &Finished);
                Add(_T("progress"), &Progress);
                Add(_T("transport"), &Transport);
            }

            SearchstatusParamsData(const SearchstatusParamsData&) = delete;
            SearchstatusParamsData(SearchstatusParamsData&&) noexcept  = delete;

            SearchstatusParamsData& operator=(const SearchstatusParamsData&) = delete;
            SearchstatusParamsData& operator=(SearchstatusParamsData&&) noexcept  = delete;

            ~SearchstatusParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Handle.IsSet() == true) && (Eventtype.IsSet() == true) && (Finished.IsSet() == true) && (Progress.IsSet() == true) && ((Transport.IsSet() == false) || (Transport.IsDataValid() == true)));
            }

        public:
            Core::JSON::DecUInt32 Handle; // The handle assigned for the search and to which this information is relevant
            Core::JSON::EnumType<EventtypeType> Eventtype; // Event type that's sent as an asynchronous notification
            Core::JSON::Boolean Finished; // Set to true if the service search has finished, false otherwise
            Core::JSON::DecUInt8 Progress; // Progress of the search expressed as a percentage
            TransportInfo Transport; // (Version 2) Details for a transport
        }; // class SearchstatusParamsData

        class ComponentData : public Core::JSON::Container {
        public:
            // Type of data contained in this component
            enum class TypeType : uint8_t {
                VIDEO,
                AUDIO,
                SUBTITLES,
                TELETEXT,
                DATA
            };

            class AudioData : public Core::JSON::Container {
            public:
                // Type of the audio contained in the component
                enum class TypeType : uint8_t {
                    UNDEFINED,
                    CLEAN,
                    HEARINGIMPAIRED,
                    VISUALLYIMPAIRED,
                    UNKNOWN
                };

                // Audio mode
                enum class ModeType : uint8_t {
                    MONO,
                    LEFT,
                    RIGHT,
                    STEREO,
                    MULTICHANNEL,
                    UNDEFINED
                };

                AudioData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                AudioData(const AudioData& _other)
                    : Core::JSON::Container()
                    , Codec(_other.Codec)
                    , Language(_other.Language)
                    , Type(_other.Type)
                    , Mode(_other.Mode)
                {
                    _Init();
                }

                AudioData(AudioData&& _other) noexcept
                    : Core::JSON::Container()
                    , Codec(std::move(_other.Codec))
                    , Language(std::move(_other.Language))
                    , Type(std::move(_other.Type))
                    , Mode(std::move(_other.Mode))
                {
                    _Init();
                }

                AudioData& operator=(const AudioData& _rhs)
                {
                    Codec = _rhs.Codec;
                    Language = _rhs.Language;
                    Type = _rhs.Type;
                    Mode = _rhs.Mode;
                    return (*this);
                }

                AudioData& operator=(AudioData&& _rhs) noexcept
                {
                    Codec = std::move(_rhs.Codec);
                    Language = std::move(_rhs.Language);
                    Type = std::move(_rhs.Type);
                    Mode = std::move(_rhs.Mode);
                    return (*this);
                }

                ~AudioData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Language.IsSet() == true) && (Type.IsSet() == true) && (Mode.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("codec"), &Codec);
                    Add(_T("language"), &Language);
                    Add(_T("type"), &Type);
                    Add(_T("mode"), &Mode);
                }

            public:
                Core::JSON::EnumType<CodecType> Codec; // Video or audio codec type
                Core::JSON::String Language; // ISO 3-char language code
                Core::JSON::EnumType<ComponentData::AudioData::TypeType> Type; // Type of the audio contained in the component
                Core::JSON::EnumType<ComponentData::AudioData::ModeType> Mode; // Audio mode
            }; // class AudioData

            class CodecData : public Core::JSON::Container {
            public:
                CodecData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                CodecData(const CodecData& _other)
                    : Core::JSON::Container()
                    , Codec(_other.Codec)
                {
                    _Init();
                }

                CodecData(CodecData&& _other) noexcept
                    : Core::JSON::Container()
                    , Codec(std::move(_other.Codec))
                {
                    _Init();
                }

                CodecData& operator=(const CodecData& _rhs)
                {
                    Codec = _rhs.Codec;
                    return (*this);
                }

                CodecData& operator=(CodecData&& _rhs) noexcept
                {
                    Codec = std::move(_rhs.Codec);
                    return (*this);
                }

                ~CodecData() = default;

            public:
                bool IsDataValid() const
                {
                    return (Codec.IsSet() == true);
                }

            private:
                void _Init()
                {
                    Add(_T("codec"), &Codec);
                }

            public:
                Core::JSON::EnumType<CodecType> Codec; // Video or audio codec type
            }; // class CodecData

            class SubtitlesData : public Core::JSON::Container {
            public:
                // Intended TV format for the subtitles
                enum class FormatType : uint8_t {
                    DEFAULT,
                    E4_3,
                    E16_9,
                    E221_1,
                    HD,
                    HARDOFHEARING,
                    HARDOFHEARING4_3,
                    HARDOFHEARING16_9,
                    HARDOFHEARING221_1,
                    HARDOFHEARINGHD
                };

                SubtitlesData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                SubtitlesData(const SubtitlesData& _other)
                    : Core::JSON::Container()
                    , Language(_other.Language)
                    , Format(_other.Format)
                    , Compositionpage(_other.Compositionpage)
                    , Ancillarypage(_other.Ancillarypage)
                {
                    _Init();
                }

                SubtitlesData(SubtitlesData&& _other) noexcept
                    : Core::JSON::Container()
                    , Language(std::move(_other.Language))
                    , Format(std::move(_other.Format))
                    , Compositionpage(std::move(_other.Compositionpage))
                    , Ancillarypage(std::move(_other.Ancillarypage))
                {
                    _Init();
                }

                SubtitlesData& operator=(const SubtitlesData& _rhs)
                {
                    Language = _rhs.Language;
                    Format = _rhs.Format;
                    Compositionpage = _rhs.Compositionpage;
                    Ancillarypage = _rhs.Ancillarypage;
                    return (*this);
                }

                SubtitlesData& operator=(SubtitlesData&& _rhs) noexcept
                {
                    Language = std::move(_rhs.Language);
                    Format = std::move(_rhs.Format);
                    Compositionpage = std::move(_rhs.Compositionpage);
                    Ancillarypage = std::move(_rhs.Ancillarypage);
                    return (*this);
                }

                ~SubtitlesData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Language.IsSet() == true) && (Format.IsSet() == true) && (Compositionpage.IsSet() == true) && (Ancillarypage.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("language"), &Language);
                    Add(_T("format"), &Format);
                    Add(_T("compositionpage"), &Compositionpage);
                    Add(_T("ancillarypage"), &Ancillarypage);
                }

            public:
                Core::JSON::String Language; // ISO 3-char language code
                Core::JSON::EnumType<ComponentData::SubtitlesData::FormatType> Format; // Intended TV format for the subtitles
                Core::JSON::DecUInt16 Compositionpage; // Composition page to be used for subtitles in this component
                Core::JSON::DecUInt16 Ancillarypage; // Ancillary page to be used for subtitles in this component
            }; // class SubtitlesData

            class TeletextData : public Core::JSON::Container {
            public:
                TeletextData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                TeletextData(const TeletextData& _other)
                    : Core::JSON::Container()
                    , Language(_other.Language)
                    , Type(_other.Type)
                    , Magazine(_other.Magazine)
                    , Page(_other.Page)
                {
                    _Init();
                }

                TeletextData(TeletextData&& _other) noexcept
                    : Core::JSON::Container()
                    , Language(std::move(_other.Language))
                    , Type(std::move(_other.Type))
                    , Magazine(std::move(_other.Magazine))
                    , Page(std::move(_other.Page))
                {
                    _Init();
                }

                TeletextData& operator=(const TeletextData& _rhs)
                {
                    Language = _rhs.Language;
                    Type = _rhs.Type;
                    Magazine = _rhs.Magazine;
                    Page = _rhs.Page;
                    return (*this);
                }

                TeletextData& operator=(TeletextData&& _rhs) noexcept
                {
                    Language = std::move(_rhs.Language);
                    Type = std::move(_rhs.Type);
                    Magazine = std::move(_rhs.Magazine);
                    Page = std::move(_rhs.Page);
                    return (*this);
                }

                ~TeletextData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Language.IsSet() == true) && (Type.IsSet() == true) && (Magazine.IsSet() == true) && (Page.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("language"), &Language);
                    Add(_T("type"), &Type);
                    Add(_T("magazine"), &Magazine);
                    Add(_T("page"), &Page);
                }

            public:
                Core::JSON::String Language; // ISO 3-char language code
                Core::JSON::DecUInt8 Type; // Type of teletext data
                Core::JSON::DecUInt8 Magazine; // Magazine number for this type and language
                Core::JSON::DecUInt8 Page; // Page number for this type and language
            }; // class TeletextData

            ComponentData()
                : Core::JSON::Container()
            {
                _Init();
            }

            ComponentData(const ComponentData& _other)
                : Core::JSON::Container()
                , Type(_other.Type)
                , Tags(_other.Tags)
                , Pid(_other.Pid)
                , Video(_other.Video)
                , Audio(_other.Audio)
                , Subtitles(_other.Subtitles)
                , Teletext(_other.Teletext)
            {
                _Init();
            }

            ComponentData(ComponentData&& _other) noexcept
                : Core::JSON::Container()
                , Type(std::move(_other.Type))
                , Tags(std::move(_other.Tags))
                , Pid(std::move(_other.Pid))
                , Video(std::move(_other.Video))
                , Audio(std::move(_other.Audio))
                , Subtitles(std::move(_other.Subtitles))
                , Teletext(std::move(_other.Teletext))
            {
                _Init();
            }

            ComponentData& operator=(const ComponentData& _rhs)
            {
                Type = _rhs.Type;
                Tags = _rhs.Tags;
                Pid = _rhs.Pid;
                Video = _rhs.Video;
                Audio = _rhs.Audio;
                Subtitles = _rhs.Subtitles;
                Teletext = _rhs.Teletext;
                return (*this);
            }

            ComponentData& operator=(ComponentData&& _rhs) noexcept
            {
                Type = std::move(_rhs.Type);
                Tags = std::move(_rhs.Tags);
                Pid = std::move(_rhs.Pid);
                Video = std::move(_rhs.Video);
                Audio = std::move(_rhs.Audio);
                Subtitles = std::move(_rhs.Subtitles);
                Teletext = std::move(_rhs.Teletext);
                return (*this);
            }

            ~ComponentData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Pid.IsSet() == true) && ((Video.IsSet() == false) || (Video.IsDataValid() == true)) && ((Audio.IsSet() == false) || (Audio.IsDataValid() == true)) && ((Subtitles.IsSet() == false) || (Subtitles.IsDataValid() == true)) && ((Teletext.IsSet() == false) || (Teletext.IsDataValid() == true)));
            }

        private:
            void _Init()
            {
                Add(_T("type"), &Type);
                Add(_T("tags"), &Tags);
                Add(_T("pid"), &Pid);
                Add(_T("video"), &Video);
                Add(_T("audio"), &Audio);
                Add(_T("subtitles"), &Subtitles);
                Add(_T("teletext"), &Teletext);
            }

        public:
            Core::JSON::EnumType<ComponentData::TypeType> Type; // Type of data contained in this component
            Core::JSON::ArrayType<Core::JSON::DecUInt8> Tags; // Array of component tags
            Core::JSON::DecUInt16 Pid; // PID of the component
            ComponentData::CodecData Video; // Video related information for a video component
            ComponentData::AudioData Audio; // Audio related information for an audio component
            ComponentData::SubtitlesData Subtitles; // DVB subtitle related information for a subtitle component
            ComponentData::TeletextData Teletext; // Teletext related information for a teletext component
        }; // class ComponentData

        class SignalInfoData : public Core::JSON::Container {
        public:
            SignalInfoData()
                : Core::JSON::Container()
            {
                Add(_T("locked"), &Locked);
                Add(_T("strength"), &Strength);
                Add(_T("quality"), &Quality);
            }

            SignalInfoData(const SignalInfoData&) = delete;
            SignalInfoData(SignalInfoData&&) noexcept  = delete;

            SignalInfoData& operator=(const SignalInfoData&) = delete;
            SignalInfoData& operator=(SignalInfoData&&) noexcept  = delete;

            ~SignalInfoData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Locked.IsSet() == true) && (Strength.IsSet() == true) && (Quality.IsSet() == true));
            }

        public:
            Core::JSON::Boolean Locked; // Tuned locked status
            Core::JSON::DecUInt8 Strength; // The signal strength as a percentage
            Core::JSON::DecUInt8 Quality; // The signal quality as a percentage
        }; // class SignalInfoData

        class StartPlayingParamsData : public Core::JSON::Container {
        public:
            StartPlayingParamsData()
                : Core::JSON::Container()
            {
                Add(_T("dvburi"), &Dvburi);
                Add(_T("lcn"), &Lcn);
                Add(_T("monitoronly"), &Monitoronly);
            }

            StartPlayingParamsData(const StartPlayingParamsData&) = delete;
            StartPlayingParamsData(StartPlayingParamsData&&) noexcept  = delete;

            StartPlayingParamsData& operator=(const StartPlayingParamsData&) = delete;
            StartPlayingParamsData& operator=(StartPlayingParamsData&&) noexcept  = delete;

            ~StartPlayingParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (true);
            }

        public:
            Core::JSON::String Dvburi; // DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal
            Core::JSON::DecUInt16 Lcn; // LCN of the service to be tuned to
            Core::JSON::Boolean Monitoronly; // (Version 2) set to 'true' to monitor SI/PSI data only. Will default to 'false' if not defined
        }; // class StartPlayingParamsData

        class StartServiceSearchParamsData : public Core::JSON::Container {
        public:
            // Supported Search Type
            enum class SearchtypeType : uint8_t {
                FREQUENCY,
                NETWORK
            };

            StartServiceSearchParamsData()
                : Core::JSON::Container()
            {
                Add(_T("tunertype"), &Tunertype);
                Add(_T("searchtype"), &Searchtype);
                Add(_T("retune"), &Retune);
                Add(_T("usetuningparams"), &Usetuningparams);
                Add(_T("dvbstuningparams"), &Dvbstuningparams);
                Add(_T("dvbctuningparams"), &Dvbctuningparams);
                Add(_T("dvbttuningparams"), &Dvbttuningparams);
            }

            StartServiceSearchParamsData(const StartServiceSearchParamsData&) = delete;
            StartServiceSearchParamsData(StartServiceSearchParamsData&&) noexcept  = delete;

            StartServiceSearchParamsData& operator=(const StartServiceSearchParamsData&) = delete;
            StartServiceSearchParamsData& operator=(StartServiceSearchParamsData&&) noexcept  = delete;

            ~StartServiceSearchParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Tunertype.IsSet() == true) && (Searchtype.IsSet() == true) && (Retune.IsSet() == true) && (Usetuningparams.IsSet() == true) && ((Dvbstuningparams.IsSet() == false) || (Dvbstuningparams.IsDataValid() == true)) && ((Dvbctuningparams.IsSet() == false) || (Dvbctuningparams.IsDataValid() == true)) && ((Dvbttuningparams.IsSet() == false) || (Dvbttuningparams.IsDataValid() == true)));
            }

        public:
            Core::JSON::EnumType<TunertypeType> Tunertype; // Tuner type
            Core::JSON::EnumType<StartServiceSearchParamsData::SearchtypeType> Searchtype; // Supported Search Type
            Core::JSON::Boolean Retune; // Set to true if current services are to be replaced in the database, false if the scan is to update the existing services
            Core::JSON::Boolean Usetuningparams; // Set to true if the optional tuning parameters are defined
            DvbstuningparamsInfo Dvbstuningparams; // Parameters required to tune to a DVB-S/S2 signal
            DvbctuningparamsInfo Dvbctuningparams; // Parameters required to tune to a DVB-C signal
            DvbttuningparamsInfo Dvbttuningparams; // Parameters required to tune to a DVB-T/T2 signal
        }; // class StartServiceSearchParamsData

        class StatusData : public Core::JSON::Container {
        public:
            StatusData()
                : Core::JSON::Container()
            {
                Add(_T("tuner"), &Tuner);
                Add(_T("demux"), &Demux);
                Add(_T("pmtpid"), &Pmtpid);
                Add(_T("dvburi"), &Dvburi);
                Add(_T("lcn"), &Lcn);
            }

            StatusData(const StatusData&) = delete;
            StatusData(StatusData&&) noexcept  = delete;

            StatusData& operator=(const StatusData&) = delete;
            StatusData& operator=(StatusData&&) noexcept  = delete;

            ~StatusData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Tuner.IsSet() == true) && (Demux.IsSet() == true) && (Pmtpid.IsSet() == true) && (Dvburi.IsSet() == true) && (Lcn.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt8 Tuner; // The tuner id used by the play handle
            Core::JSON::DecUInt8 Demux; // The demux id used by the play handle
            Core::JSON::DecUInt16 Pmtpid; // The PMT PID of the service being played
            Core::JSON::String Dvburi; // DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal
            Core::JSON::DecUInt16 Lcn; // LCN of the service being played
        }; // class StatusData

    } // namespace DTV

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::DTV::LnbtypeType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::LnbpowerType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::Diseqc_toneType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::Diseqc_cswitchType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::TunertypeType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::StartServiceSearchParamsData::SearchtypeType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::PolarityType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::FecType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::DvbsmodulationType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::DvbcmodulationType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::DvbtbandwidthType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::OfdmmodeType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::ServicetypeType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::RunningstatusType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::ComponentData::TypeType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::CodecType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::ComponentData::AudioData::TypeType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::ComponentData::AudioData::ModeType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::ComponentData::SubtitlesData::FormatType)
ENUM_CONVERSION_HANDLER(JsonData::DTV::EventtypeType)

}

