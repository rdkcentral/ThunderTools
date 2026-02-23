// Generated automatically from 'IPackager.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_Packager.h"
#include <interfaces/IPackager.h>

namespace Thunder {

namespace Exchange {

    namespace JPackager {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IPackager* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JPackager"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'install' - Install a package given by a name, an URL or a file path
            _module__.PluginHost::JSONRPC::template Register<JsonData::Packager::InstallParamsData, void>(_T("install"),
                [_implementation__](const JsonData::Packager::InstallParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _name_{params.Name};
                        const string _version_{params.Version};
                        const string _arch_{params.Arch};

                        _errorCode__ = _implementation__->Install(_name_, _version_, _arch_);

                    }

                    return (_errorCode__);
                });

            // Method: 'synchronizerepository' - Synchronize repository manifest with a repository
            _module__.PluginHost::JSONRPC::template Register<void, void>(_T("synchronizerepository"),
                [_implementation__]() -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    _errorCode__ = _implementation__->SynchronizeRepository();

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("synchronize"), _T("synchronizerepository"));

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("install"));
            _module__.PluginHost::JSONRPC::Unregister(_T("synchronizerepository"));
            _module__.PluginHost::JSONRPC::Unregister(_T("synchronize"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JPackager

} // namespace Exchange

} // namespace Thunder

