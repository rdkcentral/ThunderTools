// C++ classes for Device Info API JSON-RPC API.
// Generated automatically from 'DeviceInfo.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    namespace DeviceInfo {

        // Common enums
        //

        // Audio capability
        enum class AudiocapabilityType : uint8_t {
            NONE,
            ATMOS,
            DD,
            DDPLUS,
            DAD,
            DAPV2,
            MS12
        };

        // Audio output supported by the device
        enum class AudioportType : uint8_t {
            OTHER,
            RF_MODULATOR,
            ANALOG,
            SPDIF0,
            HDMI0,
            HDMI1,
            DISPLAYPORT
        };

        // HDCP support
        enum class CopyprotectionType : uint8_t {
            HDCP_UNAVAILABLE,
            HDCP_14,
            HDCP_20,
            HDCP_21,
            HDCP_22
        };

        // MS12 audio capability
        enum class Ms12capabilityType : uint8_t {
            NONE,
            DOLBYVOLUME,
            INTELIGENTEQUALIZER,
            DIALOGUEENHANCER
        };

        // MS12 Profile
        enum class Ms12profileType : uint8_t {
            NONE,
            MUSIC,
            MOVIE,
            VOICE
        };

        // Resolution supported by the device
        enum class Output_resolutionType : uint8_t {
            UNKNOWN,
            E480I,
            E480P,
            E576I,
            E576P,
            E576P50,
            E720P,
            E720P24,
            E720P25,
            E720P30,
            E720P50,
            E720P60,
            E1080I,
            E1080I25,
            E1080I50,
            E1080I60,
            E1080P,
            E1080P24,
            E1080P25,
            E1080P30,
            E1080P50,
            E1080P60,
            E2160P24,
            E2160P25,
            E2160P30,
            E2160P50,
            E2160P60,
            E4320P30,
            E4320P60
        };

        // Video output supported by the device
        enum class VideodisplayType : uint8_t {
            OTHER,
            RF_MODULATOR,
            COMPOSITE,
            SVIDEO,
            COMPONET,
            SCART_RGB,
            HDMI0,
            HDMI1,
            DISPLAYPORT
        };

        // Common classes
        //

        class AudiocapabilitiesParamsInfo : public Core::JSON::Container {
        public:
            AudiocapabilitiesParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("audioPort"), &AudioPort);
            }

            bool IsValid() const
            {
                return (true);
            }

            AudiocapabilitiesParamsInfo(const AudiocapabilitiesParamsInfo&) = delete;
            AudiocapabilitiesParamsInfo& operator=(const AudiocapabilitiesParamsInfo&) = delete;

        public:
            Core::JSON::EnumType<AudioportType> AudioPort; // Audio output supported by the device
        }; // class AudiocapabilitiesParamsInfo

        class FriendlynameInfo : public Core::JSON::Container {
        public:
            FriendlynameInfo()
                : Core::JSON::Container()
            {
                Add(_T("name"), &Name);
            }

            bool IsValid() const
            {
                return (true);
            }

            FriendlynameInfo(const FriendlynameInfo&) = delete;
            FriendlynameInfo& operator=(const FriendlynameInfo&) = delete;

        public:
            Core::JSON::String Name;
        }; // class FriendlynameInfo

        class SupportedresolutionsParamsInfo : public Core::JSON::Container {
        public:
            SupportedresolutionsParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("videoDisplay"), &VideoDisplay);
            }

            bool IsValid() const
            {
                return (true);
            }

            SupportedresolutionsParamsInfo(const SupportedresolutionsParamsInfo&) = delete;
            SupportedresolutionsParamsInfo& operator=(const SupportedresolutionsParamsInfo&) = delete;

        public:
            Core::JSON::EnumType<VideodisplayType> VideoDisplay; // Video output supported by the device
        }; // class SupportedresolutionsParamsInfo

        // Method params/result classes
        //

        class AddressesData : public Core::JSON::Container {
        public:
            AddressesData()
                : Core::JSON::Container()
            {
                _Init();
            }

            AddressesData(const AddressesData& _other)
                : Core::JSON::Container()
                , Name(_other.Name)
                , Mac(_other.Mac)
                , Ip(_other.Ip)
            {
                _Init();
            }

            AddressesData& operator=(const AddressesData& _rhs)
            {
                Name = _rhs.Name;
                Mac = _rhs.Mac;
                Ip = _rhs.Ip;
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
                Add(_T("mac"), &Mac);
                Add(_T("ip"), &Ip);
            }

        public:
            Core::JSON::String Name; // Interface name
            Core::JSON::String Mac; // Interface MAC address
            Core::JSON::ArrayType<Core::JSON::String> Ip;
        }; // class AddressesData

        class AudiocapabilitiesResultData : public Core::JSON::Container {
        public:
            AudiocapabilitiesResultData()
                : Core::JSON::Container()
            {
                Add(_T("AudioCapabilities"), &AudioCapabilities);
            }

            bool IsValid() const
            {
                return (true);
            }

            AudiocapabilitiesResultData(const AudiocapabilitiesResultData&) = delete;
            AudiocapabilitiesResultData& operator=(const AudiocapabilitiesResultData&) = delete;

        public:
            Core::JSON::ArrayType<Core::JSON::EnumType<AudiocapabilityType>> AudioCapabilities;
        }; // class AudiocapabilitiesResultData

        class DefaultresolutionResultData : public Core::JSON::Container {
        public:
            DefaultresolutionResultData()
                : Core::JSON::Container()
            {
                Add(_T("defaultResolution"), &DefaultResolution);
            }

            bool IsValid() const
            {
                return (true);
            }

            DefaultresolutionResultData(const DefaultresolutionResultData&) = delete;
            DefaultresolutionResultData& operator=(const DefaultresolutionResultData&) = delete;

        public:
            Core::JSON::EnumType<Output_resolutionType> DefaultResolution; // Resolution supported by the device
        }; // class DefaultresolutionResultData

        class DeviceaudiocapabilitiesData : public Core::JSON::Container {
        public:
            class AudiooutputcapabilitiesData : public Core::JSON::Container {
            public:
                AudiooutputcapabilitiesData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                AudiooutputcapabilitiesData(const AudiooutputcapabilitiesData& _other)
                    : Core::JSON::Container()
                    , AudioPort(_other.AudioPort)
                    , Audiocapabilities(_other.Audiocapabilities)
                    , Ms12capabilities(_other.Ms12capabilities)
                    , Ms12profiles(_other.Ms12profiles)
                {
                    _Init();
                }

                AudiooutputcapabilitiesData& operator=(const AudiooutputcapabilitiesData& _rhs)
                {
                    AudioPort = _rhs.AudioPort;
                    Audiocapabilities = _rhs.Audiocapabilities;
                    Ms12capabilities = _rhs.Ms12capabilities;
                    Ms12profiles = _rhs.Ms12profiles;
                    return (*this);
                }

                bool IsValid() const
                {
                    return (true);
                }

            private:
                void _Init()
                {
                    Add(_T("audioPort"), &AudioPort);
                    Add(_T("audiocapabilities"), &Audiocapabilities);
                    Add(_T("ms12capabilities"), &Ms12capabilities);
                    Add(_T("ms12profiles"), &Ms12profiles);
                }

            public:
                Core::JSON::EnumType<AudioportType> AudioPort; // Audio Output support
                Core::JSON::ArrayType<Core::JSON::EnumType<AudiocapabilityType>> Audiocapabilities; // Audio capabilities for the specified audio port
                Core::JSON::ArrayType<Core::JSON::EnumType<Ms12capabilityType>> Ms12capabilities; // Audio ms12 capabilities for the specified audio port
                Core::JSON::ArrayType<Core::JSON::EnumType<Ms12profileType>> Ms12profiles; // Audio ms12 profiles for the specified audio port
            }; // class AudiooutputcapabilitiesData

            DeviceaudiocapabilitiesData()
                : Core::JSON::Container()
            {
                Add(_T("audiooutputcapabilities"), &Audiooutputcapabilities);
            }

            bool IsValid() const
            {
                return (true);
            }

            DeviceaudiocapabilitiesData(const DeviceaudiocapabilitiesData&) = delete;
            DeviceaudiocapabilitiesData& operator=(const DeviceaudiocapabilitiesData&) = delete;

        public:
            Core::JSON::ArrayType<DeviceaudiocapabilitiesData::AudiooutputcapabilitiesData> Audiooutputcapabilities;
        }; // class DeviceaudiocapabilitiesData

        class DeviceinfoData : public Core::JSON::Container {
        public:
            DeviceinfoData()
                : Core::JSON::Container()
            {
                Add(_T("devicetype"), &Devicetype);
                Add(_T("friendlyname"), &Friendlyname);
                Add(_T("distributorid"), &Distributorid);
                Add(_T("make"), &Make);
                Add(_T("modelname"), &Modelname);
                Add(_T("modelyear"), &Modelyear);
                Add(_T("platformname"), &Platformname);
                Add(_T("serialnumber"), &Serialnumber);
                Add(_T("sku"), &Sku);
            }

            bool IsValid() const
            {
                return (true);
            }

            DeviceinfoData(const DeviceinfoData&) = delete;
            DeviceinfoData& operator=(const DeviceinfoData&) = delete;

        public:
            Core::JSON::String Devicetype; // Device type
            Core::JSON::String Friendlyname; // Friendly name
            Core::JSON::String Distributorid; // Partner ID or distributor ID for device
            Core::JSON::String Make; // Device manufacturer
            Core::JSON::String Modelname; // Model Name
            Core::JSON::DecUInt16 Modelyear; // Model Year
            Core::JSON::String Platformname; // Platform name
            Core::JSON::String Serialnumber; // Device serial number
            Core::JSON::String Sku; // Device model number or SKU
        }; // class DeviceinfoData

        class DevicetypeData : public Core::JSON::Container {
        public:
            // Device type
            enum class DevicetypeType : uint8_t {
                TV,
                IPSTB,
                QAMIPSTB,
                HYBRID,
                MEDIACLIENT
            };

            DevicetypeData()
                : Core::JSON::Container()
            {
                Add(_T("devicetype"), &Devicetype);
            }

            bool IsValid() const
            {
                return (true);
            }

            DevicetypeData(const DevicetypeData&) = delete;
            DevicetypeData& operator=(const DevicetypeData&) = delete;

        public:
            Core::JSON::EnumType<DevicetypeData::DevicetypeType> Devicetype; // Device type
        }; // class DevicetypeData

        class DevicevideocapabilitiesData : public Core::JSON::Container {
        public:
            class VideooutputcapabilitiesData : public Core::JSON::Container {
            public:
                VideooutputcapabilitiesData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                VideooutputcapabilitiesData(const VideooutputcapabilitiesData& _other)
                    : Core::JSON::Container()
                    , Hdcp(_other.Hdcp)
                    , VideoDisplay(_other.VideoDisplay)
                    , Output_resolutions(_other.Output_resolutions)
                    , Defaultresolution(_other.Defaultresolution)
                {
                    _Init();
                }

                VideooutputcapabilitiesData& operator=(const VideooutputcapabilitiesData& _rhs)
                {
                    Hdcp = _rhs.Hdcp;
                    VideoDisplay = _rhs.VideoDisplay;
                    Output_resolutions = _rhs.Output_resolutions;
                    Defaultresolution = _rhs.Defaultresolution;
                    return (*this);
                }

                bool IsValid() const
                {
                    return (true);
                }

            private:
                void _Init()
                {
                    Add(_T("hdcp"), &Hdcp);
                    Add(_T("videoDisplay"), &VideoDisplay);
                    Add(_T("output_resolutions"), &Output_resolutions);
                    Add(_T("defaultresolution"), &Defaultresolution);
                }

            public:
                Core::JSON::EnumType<CopyprotectionType> Hdcp; // HDCP support
                Core::JSON::EnumType<VideodisplayType> VideoDisplay; // Video Output support
                Core::JSON::ArrayType<Core::JSON::EnumType<Output_resolutionType>> Output_resolutions; // Supported resolutions
                Core::JSON::EnumType<Output_resolutionType> Defaultresolution; // Default resolution
            }; // class VideooutputcapabilitiesData

            DevicevideocapabilitiesData()
                : Core::JSON::Container()
            {
                Add(_T("hostedid"), &Hostedid);
                Add(_T("hdr"), &Hdr);
                Add(_T("atmos"), &Atmos);
                Add(_T("cec"), &Cec);
                Add(_T("videooutputcapabilities"), &Videooutputcapabilities);
            }

            bool IsValid() const
            {
                return (true);
            }

            DevicevideocapabilitiesData(const DevicevideocapabilitiesData&) = delete;
            DevicevideocapabilitiesData& operator=(const DevicevideocapabilitiesData&) = delete;

        public:
            Core::JSON::String Hostedid; // EDID of the host
            Core::JSON::Boolean Hdr; // Is HDR supported by this device
            Core::JSON::Boolean Atmos; // Is Atmos supported by this device
            Core::JSON::Boolean Cec; // Is CEC supported by this device
            Core::JSON::ArrayType<DevicevideocapabilitiesData::VideooutputcapabilitiesData> Videooutputcapabilities;
        }; // class DevicevideocapabilitiesData

        class DistributoridData : public Core::JSON::Container {
        public:
            // Partner ID or distributor ID for device
            enum class DistributoridType : uint8_t {
                COMCAST,
                XGLOBAL,
                SKY_DE,
                SKY_ITALIA,
                SKY_UK,
                SKY_UK_DEV,
                SKY_DEU,
                SKY_DEU_DEV,
                SKY_IT,
                SKY_IT_DEV,
                COX,
                COX_HOSPITALITY,
                COX_DEV,
                COX_QA,
                MIT,
                SHAW,
                SHAW_DEV,
                ROGERS,
                ROGERS_DEV,
                VIDEOTRON,
                CHARTER,
                CHARTER_DEV
            };

            DistributoridData()
                : Core::JSON::Container()
            {
                Add(_T("distributorid"), &Distributorid);
            }

            bool IsValid() const
            {
                return (true);
            }

            DistributoridData(const DistributoridData&) = delete;
            DistributoridData& operator=(const DistributoridData&) = delete;

        public:
            Core::JSON::EnumType<DistributoridData::DistributoridType> Distributorid; // Partner ID or distributor ID for device
        }; // class DistributoridData

        class FirmwareversionData : public Core::JSON::Container {
        public:
            // Yocto version
            enum class YoctoType : uint8_t {
                DUNFELL,
                MORTY,
                DAISY,
                KIRKSTONE
            };

            FirmwareversionData()
                : Core::JSON::Container()
            {
                Add(_T("imagename"), &Imagename);
                Add(_T("sdk"), &Sdk);
                Add(_T("mediarite"), &Mediarite);
                Add(_T("yocto"), &Yocto);
            }

            bool IsValid() const
            {
                return (true);
            }

            FirmwareversionData(const FirmwareversionData&) = delete;
            FirmwareversionData& operator=(const FirmwareversionData&) = delete;

        public:
            Core::JSON::String Imagename;
            Core::JSON::String Sdk;
            Core::JSON::String Mediarite;
            Core::JSON::EnumType<FirmwareversionData::YoctoType> Yocto; // Yocto version
        }; // class FirmwareversionData

        class HostedidData : public Core::JSON::Container {
        public:
            HostedidData()
                : Core::JSON::Container()
            {
                Add(_T("EDID"), &EDID);
            }

            bool IsValid() const
            {
                return (true);
            }

            HostedidData(const HostedidData&) = delete;
            HostedidData& operator=(const HostedidData&) = delete;

        public:
            Core::JSON::String EDID;
        }; // class HostedidData

        class MakeData : public Core::JSON::Container {
        public:
            // Device manufacturer
            enum class MakeType : uint8_t {
                PLATCO,
                LLAMA,
                HISENSE,
                ELEMENT,
                SKY_CP,
                SKY,
                SERCOMM,
                COMMSCOPE,
                ARRIS,
                CISCO,
                PACE,
                SAMSUNG,
                TECHNICOLOR,
                AMLOGIC_INC,
                RASPBERRYPI_ORG,
                PIONEER,
                TPV
            };

            MakeData()
                : Core::JSON::Container()
            {
                Add(_T("make"), &Make);
            }

            bool IsValid() const
            {
                return (true);
            }

            MakeData(const MakeData&) = delete;
            MakeData& operator=(const MakeData&) = delete;

        public:
            Core::JSON::EnumType<MakeData::MakeType> Make; // Device manufacturer
        }; // class MakeData

        class ModelidData : public Core::JSON::Container {
        public:
            // Device model number or SKU
            enum class SkuType : uint8_t {
                PLTL11AEI,
                ZWCN11MWI,
                SKTL11AEI,
                LS301,
                HSTP11MWR,
                HSTP11MWRFX50,
                ELTE11MWR,
                SKXI11ADS,
                SKXI11AIS,
                SKXI11ANS,
                SCXI11AIC,
                SCXI11BEI,
                CMXI11BEI,
                AX013AN,
                AX014AN,
                AX061AEI,
                MX011AN,
                CS011AN,
                CXD01ANI,
                PX001AN,
                PX013AN,
                PX022AN,
                PX032ANI,
                PX051AEI,
                PXD01ANI,
                SX022AN,
                TX061AEI,
                PI,
                XUSHTC11MWR,
                XUSPTC11MWR,
                XUSHTB11MWR,
                PITU11MWR
            };

            ModelidData()
                : Core::JSON::Container()
            {
                Add(_T("sku"), &Sku);
            }

            bool IsValid() const
            {
                return (true);
            }

            ModelidData(const ModelidData&) = delete;
            ModelidData& operator=(const ModelidData&) = delete;

        public:
            Core::JSON::EnumType<ModelidData::SkuType> Sku; // Device model number or SKU
        }; // class ModelidData

        class ModelnameData : public Core::JSON::Container {
        public:
            ModelnameData()
                : Core::JSON::Container()
            {
                Add(_T("model"), &Model);
            }

            bool IsValid() const
            {
                return (true);
            }

            ModelnameData(const ModelnameData&) = delete;
            ModelnameData& operator=(const ModelnameData&) = delete;

        public:
            Core::JSON::String Model;
        }; // class ModelnameData

        class ModelyearData : public Core::JSON::Container {
        public:
            ModelyearData()
                : Core::JSON::Container()
            {
                Add(_T("year"), &Year);
            }

            bool IsValid() const
            {
                return (true);
            }

            ModelyearData(const ModelyearData&) = delete;
            ModelyearData& operator=(const ModelyearData&) = delete;

        public:
            Core::JSON::DecUInt16 Year;
        }; // class ModelyearData

        class Ms12capabilitiesResultData : public Core::JSON::Container {
        public:
            Ms12capabilitiesResultData()
                : Core::JSON::Container()
            {
                Add(_T("MS12Capabilities"), &MS12Capabilities);
            }

            bool IsValid() const
            {
                return (true);
            }

            Ms12capabilitiesResultData(const Ms12capabilitiesResultData&) = delete;
            Ms12capabilitiesResultData& operator=(const Ms12capabilitiesResultData&) = delete;

        public:
            Core::JSON::ArrayType<Core::JSON::EnumType<Ms12capabilityType>> MS12Capabilities;
        }; // class Ms12capabilitiesResultData

        class SerialnumberData : public Core::JSON::Container {
        public:
            SerialnumberData()
                : Core::JSON::Container()
            {
                Add(_T("serialnumber"), &Serialnumber);
            }

            bool IsValid() const
            {
                return (true);
            }

            SerialnumberData(const SerialnumberData&) = delete;
            SerialnumberData& operator=(const SerialnumberData&) = delete;

        public:
            Core::JSON::String Serialnumber;
        }; // class SerialnumberData

        class SocketinfoData : public Core::JSON::Container {
        public:
            SocketinfoData()
                : Core::JSON::Container()
            {
                Add(_T("total"), &Total);
                Add(_T("open"), &Open);
                Add(_T("link"), &Link);
                Add(_T("exception"), &Exception);
                Add(_T("shutdown"), &Shutdown);
                Add(_T("runs"), &Runs);
            }

            bool IsValid() const
            {
                return (true);
            }

            SocketinfoData(const SocketinfoData&) = delete;
            SocketinfoData& operator=(const SocketinfoData&) = delete;

        public:
            Core::JSON::DecUInt32 Total;
            Core::JSON::DecUInt32 Open;
            Core::JSON::DecUInt32 Link;
            Core::JSON::DecUInt32 Exception;
            Core::JSON::DecUInt32 Shutdown;
            Core::JSON::DecUInt32 Runs; // Number of runs
        }; // class SocketinfoData

        class SupportedaudioportsData : public Core::JSON::Container {
        public:
            SupportedaudioportsData()
                : Core::JSON::Container()
            {
                Add(_T("supportedAudioPorts"), &SupportedAudioPorts);
            }

            bool IsValid() const
            {
                return (true);
            }

            SupportedaudioportsData(const SupportedaudioportsData&) = delete;
            SupportedaudioportsData& operator=(const SupportedaudioportsData&) = delete;

        public:
            Core::JSON::ArrayType<Core::JSON::EnumType<AudioportType>> SupportedAudioPorts; // Audio Output support
        }; // class SupportedaudioportsData

        class SupportedhdcpResultData : public Core::JSON::Container {
        public:
            SupportedhdcpResultData()
                : Core::JSON::Container()
            {
                Add(_T("supportedHDCPVersion"), &SupportedHDCPVersion);
            }

            bool IsValid() const
            {
                return (true);
            }

            SupportedhdcpResultData(const SupportedhdcpResultData&) = delete;
            SupportedhdcpResultData& operator=(const SupportedhdcpResultData&) = delete;

        public:
            Core::JSON::EnumType<CopyprotectionType> SupportedHDCPVersion; // HDCP support
        }; // class SupportedhdcpResultData

        class Supportedms12audioprofilesResultData : public Core::JSON::Container {
        public:
            Supportedms12audioprofilesResultData()
                : Core::JSON::Container()
            {
                Add(_T("supportedMS12AudioProfiles"), &SupportedMS12AudioProfiles);
            }

            bool IsValid() const
            {
                return (true);
            }

            Supportedms12audioprofilesResultData(const Supportedms12audioprofilesResultData&) = delete;
            Supportedms12audioprofilesResultData& operator=(const Supportedms12audioprofilesResultData&) = delete;

        public:
            Core::JSON::ArrayType<Core::JSON::EnumType<Ms12profileType>> SupportedMS12AudioProfiles; // An array of ms12 audio profiles
        }; // class Supportedms12audioprofilesResultData

        class SupportedresolutionsResultData : public Core::JSON::Container {
        public:
            SupportedresolutionsResultData()
                : Core::JSON::Container()
            {
                Add(_T("supportedResolutions"), &SupportedResolutions);
            }

            bool IsValid() const
            {
                return (true);
            }

            SupportedresolutionsResultData(const SupportedresolutionsResultData&) = delete;
            SupportedresolutionsResultData& operator=(const SupportedresolutionsResultData&) = delete;

        public:
            Core::JSON::ArrayType<Core::JSON::EnumType<Output_resolutionType>> SupportedResolutions;
        }; // class SupportedresolutionsResultData

        class SupportedvideodisplaysData : public Core::JSON::Container {
        public:
            SupportedvideodisplaysData()
                : Core::JSON::Container()
            {
                Add(_T("supportedVideoDisplays"), &SupportedVideoDisplays);
            }

            bool IsValid() const
            {
                return (true);
            }

            SupportedvideodisplaysData(const SupportedvideodisplaysData&) = delete;
            SupportedvideodisplaysData& operator=(const SupportedvideodisplaysData&) = delete;

        public:
            Core::JSON::ArrayType<Core::JSON::EnumType<VideodisplayType>> SupportedVideoDisplays; // Video Output support
        }; // class SupportedvideodisplaysData

        class SysteminfoData : public Core::JSON::Container {
        public:
            class CpuloadavgsData : public Core::JSON::Container {
            public:
                CpuloadavgsData()
                    : Core::JSON::Container()
                {
                    Add(_T("avg1min"), &Avg1min);
                    Add(_T("avg5min"), &Avg5min);
                    Add(_T("avg15min"), &Avg15min);
                }

                bool IsValid() const
                {
                    return (true);
                }

                CpuloadavgsData(const CpuloadavgsData&) = delete;
                CpuloadavgsData& operator=(const CpuloadavgsData&) = delete;

            public:
                Core::JSON::DecUInt64 Avg1min; // 1min cpuload average
                Core::JSON::DecUInt64 Avg5min; // 5min cpuload average
                Core::JSON::DecUInt64 Avg15min; // 15min cpuload average
            }; // class CpuloadavgsData

            SysteminfoData()
                : Core::JSON::Container()
            {
                Add(_T("version"), &Version);
                Add(_T("uptime"), &Uptime);
                Add(_T("totalram"), &Totalram);
                Add(_T("freeram"), &Freeram);
                Add(_T("totalswap"), &Totalswap);
                Add(_T("freeswap"), &Freeswap);
                Add(_T("devicename"), &Devicename);
                Add(_T("cpuload"), &Cpuload);
                Add(_T("cpuloadavg"), &Cpuloadavg);
                Add(_T("serialnumber"), &Serialnumber);
                Add(_T("time"), &Time);
            }

            bool IsValid() const
            {
                return (true);
            }

            SysteminfoData(const SysteminfoData&) = delete;
            SysteminfoData& operator=(const SysteminfoData&) = delete;

        public:
            Core::JSON::String Version; // Software version (in form *version#hashtag*)
            Core::JSON::DecUInt64 Uptime; // System uptime (in seconds)
            Core::JSON::DecUInt64 Totalram; // Total installed system RAM memory (in bytes)
            Core::JSON::DecUInt64 Freeram; // Free system RAM memory (in bytes)
            Core::JSON::DecUInt64 Totalswap; // Total swap space (in bytes)
            Core::JSON::DecUInt64 Freeswap; // Swap space still available (in bytes)
            Core::JSON::String Devicename; // Host name
            Core::JSON::String Cpuload; // Current CPU load (percentage)
            SysteminfoData::CpuloadavgsData Cpuloadavg; // CPU load average
            Core::JSON::String Serialnumber; // Device serial number
            Core::JSON::String Time; // Current system date and time
        }; // class SysteminfoData

    } // namespace DeviceInfo

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::DeviceInfo::VideodisplayType)
ENUM_CONVERSION_HANDLER(JsonData::DeviceInfo::Output_resolutionType)
ENUM_CONVERSION_HANDLER(JsonData::DeviceInfo::CopyprotectionType)
ENUM_CONVERSION_HANDLER(JsonData::DeviceInfo::AudioportType)
ENUM_CONVERSION_HANDLER(JsonData::DeviceInfo::AudiocapabilityType)
ENUM_CONVERSION_HANDLER(JsonData::DeviceInfo::Ms12capabilityType)
ENUM_CONVERSION_HANDLER(JsonData::DeviceInfo::Ms12profileType)
ENUM_CONVERSION_HANDLER(JsonData::DeviceInfo::FirmwareversionData::YoctoType)
ENUM_CONVERSION_HANDLER(JsonData::DeviceInfo::MakeData::MakeType)
ENUM_CONVERSION_HANDLER(JsonData::DeviceInfo::ModelidData::SkuType)
ENUM_CONVERSION_HANDLER(JsonData::DeviceInfo::DevicetypeData::DevicetypeType)
ENUM_CONVERSION_HANDLER(JsonData::DeviceInfo::DistributoridData::DistributoridType)

}

