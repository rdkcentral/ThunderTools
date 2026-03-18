// Generated automatically from 'ITestAutomation.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_Memory.h"
#include <qa_interfaces/ITestAutomation.h>

namespace Thunder {

namespace QualityAssurance {

    namespace JMemory {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IMemory* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JMemory"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'allocatememory' - Allocates Memory as given size of MB
            _module__.PluginHost::JSONRPC::template Register<JsonData::Memory::AllocateMemoryParamsData, void>(_T("allocatememory"),
                [_implementation__](const JsonData::Memory::AllocateMemoryParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _size_{params.Size};

                        _errorCode__ = _implementation__->AllocateMemory(_size_);

                    }

                    return (_errorCode__);
                });

            // Method: 'freeallocatedmemory' - Frees the allocated memory
            _module__.PluginHost::JSONRPC::template Register<void, void>(_T("freeallocatedmemory"),
                [_implementation__]() -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    _errorCode__ = _implementation__->FreeAllocatedMemory();

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("allocatememory"));
            _module__.PluginHost::JSONRPC::Unregister(_T("freeallocatedmemory"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JMemory

} // namespace QualityAssurance

} // namespace Thunder

