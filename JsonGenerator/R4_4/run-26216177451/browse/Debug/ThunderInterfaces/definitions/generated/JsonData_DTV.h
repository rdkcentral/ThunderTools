// C++ classes for DTV API JSON-RPC API.
// Generated automatically from 'DTV.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    namespace DTV {

        // Common enums
        //

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

        enum class Diseqc_cswitchType : uint8_t {
            OFF,
            A,
            B,
            C,
            D
        };

        enum class Diseqc_toneType : uint8_t {
            OFF,
            A,
            B
        };

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

        enum class DvbsmodulationType : uint8_t {
            AUTO,
            QPSK,
            E8PSK,
            E16QAM
        };

        enum class DvbtbandwidthType : uint8_t {
            E5MHZ,
            E6MHZ,
            E7MHZ,
            E8MHZ,
            E10MHZ,
            UNDEFINED
        };

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

        enum class LnbpowerType : uint8_t {
            OFF,
            ON,
            AUTO
        };

        enum class LnbtypeType : uint8_t {
            SINGLE,
            UNIVERSAL,
            UNICABLE
        };

        enum class OfdmmodeType : uint8_t {
            OFDM_1K,
            OFDM_2K,
            OFDM_4K,
            OFDM_8K,
            OFDM_16K,
            OFDM_32K,
            UNDEFINED
        };

        enum class PolarityType : uint8_t {
            HORIZONTAL,
            VERTICAL,
            LEFT,
            RIGHT
        };

        enum class RunningstatusType : uint8_t {
            UNDEFINED,
            NOTRUNNING,
            STARTSSOON,
            PAUSING,
            RUNNING,
            OFFAIR
        };

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

            bool IsValid() const
            {
                return (true);
            }

            DvbctuningparamsInfo(const DvbctuningparamsInfo&) = delete;
            DvbctuningparamsInfo& operator=(const DvbctuningparamsInfo&) = delete;

        public:
            Core::JSON::DecUInt32 Frequency;
            Core::JSON::DecUInt16 Symbolrate;
            Core::JSON::EnumType<DvbcmodulationType> Modulation;
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

            bool IsValid() const
            {
                return (true);
            }

            DvbstuningparamsInfo(const DvbstuningparamsInfo&) = delete;
            DvbstuningparamsInfo& operator=(const DvbstuningparamsInfo&) = delete;

        public:
            Core::JSON::String Satellite;
            Core::JSON::DecUInt32 Frequency;
            Core::JSON::EnumType<PolarityType> Polarity;
            Core::JSON::DecUInt16 Symbolrate;
            Core::JSON::EnumType<FecType> Fec;
            Core::JSON::EnumType<DvbsmodulationType> Modulation;
            Core::JSON::Boolean Dvbs2;
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

            bool IsValid() const
            {
                return (true);
            }

            DvbttuningparamsInfo(const DvbttuningparamsInfo&) = delete;
            DvbttuningparamsInfo& operator=(const DvbttuningparamsInfo&) = delete;

        public:
            Core::JSON::DecUInt32 Frequency;
            Core::JSON::EnumType<DvbtbandwidthType> Bandwidth;
            Core::JSON::EnumType<OfdmmodeType> Mode;
            Core::JSON::Boolean Dvbt2;
            Core::JSON::DecUInt8 Plpid;
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

            bool IsValid() const
            {
                return (true);
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
            Core::JSON::String Name;
            Core::JSON::DecUInt32 Starttime;
            Core::JSON::DecUInt32 Duration;
            Core::JSON::DecUInt16 Eventid;
            Core::JSON::String Shortdescription;
            Core::JSON::Boolean Hassubtitles;
            Core::JSON::Boolean Hasaudiodescription;
            Core::JSON::DecUInt8 Parentalrating;
            Core::JSON::ArrayType<Core::JSON::DecUInt8> Contentdata;
            Core::JSON::Boolean Hasextendedinfo;
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
                Unicablefreq = _rhs.Unicablefreq;
                return (*this);
            }

            bool IsValid() const
            {
                return (true);
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
            Core::JSON::String Name;
            Core::JSON::EnumType<LnbtypeType> Type;
            Core::JSON::EnumType<LnbpowerType> Power;
            Core::JSON::EnumType<Diseqc_toneType> Diseqc_tone;
            Core::JSON::EnumType<Diseqc_cswitchType> Diseqc_cswitch;
            Core::JSON::Boolean Is22k;
            Core::JSON::Boolean Is12v;
            Core::JSON::Boolean Ispulseposition;
            Core::JSON::Boolean Isdiseqcposition;
            Core::JSON::Boolean Issmatv;
            Core::JSON::DecUInt8 Diseqcrepeats;
            Core::JSON::DecUInt8 U_switch;
            Core::JSON::DecUInt8 Unicablechannel;
            Core::JSON::DecUInt32 Unicablefreq;
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

            SatellitesettingsInfo& operator=(const SatellitesettingsInfo& _rhs)
            {
                Name = _rhs.Name;
                Longitude = _rhs.Longitude;
                Lnb = _rhs.Lnb;
                return (*this);
            }

            bool IsValid() const
            {
                return (true);
            }

        private:
            void _Init()
            {
                Add(_T("name"), &Name);
                Add(_T("longitude"), &Longitude);
                Add(_T("lnb"), &Lnb);
            }

        public:
            Core::JSON::String Name;
            Core::JSON::DecSInt16 Longitude; // Longitudinal location of the satellite in 1/10ths of a degree,
                    //  with an east coordinate given as a positive value and a west coordinate as negative. Astra 28.2E would be defined as 282 and Eutelsat 5.0W would be -50.
            Core::JSON::String Lnb;
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

            bool IsValid() const
            {
                return (true);
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
            Core::JSON::String Fullname;
            Core::JSON::String Shortname;
            Core::JSON::String Dvburi;
            Core::JSON::EnumType<ServicetypeType> Servicetype;
            Core::JSON::DecUInt16 Lcn;
            Core::JSON::Boolean Scrambled;
            Core::JSON::Boolean Hascadescriptor;
            Core::JSON::Boolean Hidden;
            Core::JSON::Boolean Selectable;
            Core::JSON::EnumType<RunningstatusType> Runningstatus;
        }; // class ServiceInfo

        class ServiceupdatedParamsInfo : public Core::JSON::Container {
        public:
            ServiceupdatedParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("eventtype"), &Eventtype);
                Add(_T("service"), &Service);
            }

            bool IsValid() const
            {
                return (true);
            }

            ServiceupdatedParamsInfo(const ServiceupdatedParamsInfo&) = delete;
            ServiceupdatedParamsInfo& operator=(const ServiceupdatedParamsInfo&) = delete;

        public:
            Core::JSON::EnumType<EventtypeType> Eventtype;
            ServiceInfo Service;
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

            bool IsValid() const
            {
                return (true);
            }

            TransportInfo(const TransportInfo&) = delete;
            TransportInfo& operator=(const TransportInfo&) = delete;

        public:
            Core::JSON::EnumType<TunertypeType> Tunertype;
            Core::JSON::DecUInt16 Originalnetworkid;
            Core::JSON::DecUInt16 Transportid;
            Core::JSON::DecUInt8 Strength;
            Core::JSON::DecUInt8 Quality;
            DvbctuningparamsInfo Dvbctuningparams;
            DvbstuningparamsInfo Dvbstuningparams;
            DvbttuningparamsInfo Dvbttuningparams;
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

            CountryconfigData& operator=(const CountryconfigData& _rhs)
            {
                Name = _rhs.Name;
                Code = _rhs.Code;
                return (*this);
            }

            bool IsValid() const
            {
                return (true);
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

            bool IsValid() const
            {
                return (true);
            }

            EventchangedParamsData(const EventchangedParamsData&) = delete;
            EventchangedParamsData& operator=(const EventchangedParamsData&) = delete;

        public:
            Core::JSON::EnumType<EventtypeType> Eventtype;
            ServiceInfo Service;
            EiteventInfo Event;
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

                ExtendedeventitemData& operator=(const ExtendedeventitemData& _rhs)
                {
                    Description = _rhs.Description;
                    Item = _rhs.Item;
                    return (*this);
                }

                bool IsValid() const
                {
                    return (true);
                }

            private:
                void _Init()
                {
                    Add(_T("description"), &Description);
                    Add(_T("item"), &Item);
                }

            public:
                Core::JSON::String Description;
                Core::JSON::String Item;
            }; // class ExtendedeventitemData

            ExtendedeventinfoData()
                : Core::JSON::Container()
            {
                Add(_T("description"), &Description);
                Add(_T("items"), &Items);
            }

            bool IsValid() const
            {
                return (true);
            }

            ExtendedeventinfoData(const ExtendedeventinfoData&) = delete;
            ExtendedeventinfoData& operator=(const ExtendedeventinfoData&) = delete;

        public:
            Core::JSON::String Description;
            Core::JSON::ArrayType<ExtendedeventinfoData::ExtendedeventitemData> Items;
        }; // class ExtendedeventinfoData

        class FinishServiceSearchParamsData : public Core::JSON::Container {
        public:
            FinishServiceSearchParamsData()
                : Core::JSON::Container()
            {
                Add(_T("tunertype"), &Tunertype);
                Add(_T("savechanges"), &Savechanges);
            }

            bool IsValid() const
            {
                return (true);
            }

            FinishServiceSearchParamsData(const FinishServiceSearchParamsData&) = delete;
            FinishServiceSearchParamsData& operator=(const FinishServiceSearchParamsData&) = delete;

        public:
            Core::JSON::EnumType<TunertypeType> Tunertype;
            Core::JSON::Boolean Savechanges;
        }; // class FinishServiceSearchParamsData

        class NowNextEventsData : public Core::JSON::Container {
        public:
            NowNextEventsData()
                : Core::JSON::Container()
            {
                Add(_T("now"), &Now);
                Add(_T("next"), &Next);
            }

            bool IsValid() const
            {
                return (true);
            }

            NowNextEventsData(const NowNextEventsData&) = delete;
            NowNextEventsData& operator=(const NowNextEventsData&) = delete;

        public:
            EiteventInfo Now;
            EiteventInfo Next;
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

            bool IsValid() const
            {
                return (true);
            }

            SearchstatusParamsData(const SearchstatusParamsData&) = delete;
            SearchstatusParamsData& operator=(const SearchstatusParamsData&) = delete;

        public:
            Core::JSON::DecUInt32 Handle;
            Core::JSON::EnumType<EventtypeType> Eventtype;
            Core::JSON::Boolean Finished;
            Core::JSON::DecUInt8 Progress;
            TransportInfo Transport;
        }; // class SearchstatusParamsData

        class ComponentData : public Core::JSON::Container {
        public:
            enum class TypeType : uint8_t {
                VIDEO,
                AUDIO,
                SUBTITLES,
                TELETEXT,
                DATA
            };

            class AudioData : public Core::JSON::Container {
            public:
                enum class TypeType : uint8_t {
                    UNDEFINED,
                    CLEAN,
                    HEARINGIMPAIRED,
                    VISUALLYIMPAIRED,
                    UNKNOWN
                };

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

                AudioData& operator=(const AudioData& _rhs)
                {
                    Codec = _rhs.Codec;
                    Language = _rhs.Language;
                    Type = _rhs.Type;
                    Mode = _rhs.Mode;
                    return (*this);
                }

                bool IsValid() const
                {
                    return (true);
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
                Core::JSON::EnumType<CodecType> Codec;
                Core::JSON::String Language;
                Core::JSON::EnumType<ComponentData::AudioData::TypeType> Type;
                Core::JSON::EnumType<ComponentData::AudioData::ModeType> Mode;
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

                CodecData& operator=(const CodecData& _rhs)
                {
                    Codec = _rhs.Codec;
                    return (*this);
                }

                bool IsValid() const
                {
                    return (true);
                }

            private:
                void _Init()
                {
                    Add(_T("codec"), &Codec);
                }

            public:
                Core::JSON::EnumType<CodecType> Codec;
            }; // class CodecData

            class SubtitlesData : public Core::JSON::Container {
            public:
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

                SubtitlesData& operator=(const SubtitlesData& _rhs)
                {
                    Language = _rhs.Language;
                    Format = _rhs.Format;
                    Compositionpage = _rhs.Compositionpage;
                    Ancillarypage = _rhs.Ancillarypage;
                    return (*this);
                }

                bool IsValid() const
                {
                    return (true);
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
                Core::JSON::String Language;
                Core::JSON::EnumType<ComponentData::SubtitlesData::FormatType> Format;
                Core::JSON::DecUInt16 Compositionpage;
                Core::JSON::DecUInt16 Ancillarypage;
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

                TeletextData& operator=(const TeletextData& _rhs)
                {
                    Language = _rhs.Language;
                    Type = _rhs.Type;
                    Magazine = _rhs.Magazine;
                    Page = _rhs.Page;
                    return (*this);
                }

                bool IsValid() const
                {
                    return (true);
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
                Core::JSON::String Language;
                Core::JSON::DecUInt8 Type;
                Core::JSON::DecUInt8 Magazine;
                Core::JSON::DecUInt8 Page;
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

            bool IsValid() const
            {
                return (true);
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
            Core::JSON::EnumType<ComponentData::TypeType> Type;
            Core::JSON::ArrayType<Core::JSON::DecUInt8> Tags;
            Core::JSON::DecUInt16 Pid;
            ComponentData::CodecData Video;
            ComponentData::AudioData Audio;
            ComponentData::SubtitlesData Subtitles;
            ComponentData::TeletextData Teletext;
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

            bool IsValid() const
            {
                return (true);
            }

            SignalInfoData(const SignalInfoData&) = delete;
            SignalInfoData& operator=(const SignalInfoData&) = delete;

        public:
            Core::JSON::Boolean Locked;
            Core::JSON::DecUInt8 Strength;
            Core::JSON::DecUInt8 Quality;
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

            bool IsValid() const
            {
                return (true);
            }

            StartPlayingParamsData(const StartPlayingParamsData&) = delete;
            StartPlayingParamsData& operator=(const StartPlayingParamsData&) = delete;

        public:
            Core::JSON::String Dvburi;
            Core::JSON::DecUInt16 Lcn;
            Core::JSON::Boolean Monitoronly;
        }; // class StartPlayingParamsData

        class StartServiceSearchParamsData : public Core::JSON::Container {
        public:
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

            bool IsValid() const
            {
                return (true);
            }

            StartServiceSearchParamsData(const StartServiceSearchParamsData&) = delete;
            StartServiceSearchParamsData& operator=(const StartServiceSearchParamsData&) = delete;

        public:
            Core::JSON::EnumType<TunertypeType> Tunertype;
            Core::JSON::EnumType<StartServiceSearchParamsData::SearchtypeType> Searchtype;
            Core::JSON::Boolean Retune;
            Core::JSON::Boolean Usetuningparams;
            DvbstuningparamsInfo Dvbstuningparams;
            DvbctuningparamsInfo Dvbctuningparams;
            DvbttuningparamsInfo Dvbttuningparams;
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

            bool IsValid() const
            {
                return (true);
            }

            StatusData(const StatusData&) = delete;
            StatusData& operator=(const StatusData&) = delete;

        public:
            Core::JSON::DecUInt8 Tuner;
            Core::JSON::DecUInt8 Demux;
            Core::JSON::DecUInt16 Pmtpid;
            Core::JSON::String Dvburi;
            Core::JSON::DecUInt16 Lcn;
        }; // class StatusData

    } // namespace DTV

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

