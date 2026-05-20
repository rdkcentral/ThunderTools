// Generated automatically from 'IMessageControl.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_MessageControl.h"
#include <interfaces/IMessageControl.h>

namespace WPEFramework {

namespace Exchange {

    namespace JMessageControl {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IMessageControl* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JMessageControl"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'enable' - Enables/disables a message control
            _module_.Register<JsonData::MessageControl::ControlInfo, void>(_T("enable"), 
                [_impl_](const JsonData::MessageControl::ControlInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Exchange::IMessageControl::messagetype _type{params.Type};
                    const string _category{params.Category};
                    const string _module{params.Module};
                    const bool _enabled{params.Enabled};

                    _errorCode = _impl_->Enable(_type, _category, _module, _enabled);

                    return (_errorCode);
                });

            // Property: 'controls' - Retrieves a list of current message controls (r/o)
            _module_.Register<void, Core::JSON::ArrayType<JsonData::MessageControl::ControlInfo>>(_T("controls"), 
                [_impl_](Core::JSON::ArrayType<JsonData::MessageControl::ControlInfo>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    ::WPEFramework::RPC::IIteratorType<IMessageControl::Control, ID_MESSAGE_CONTROL_ITERATOR>* _result{};

                    _errorCode = _impl_->Controls(_result);

                    if (_errorCode == Core::ERROR_NONE) {

                        if (_result != nullptr) {
                            Exchange::IMessageControl::Control _resultItem_{};
                            while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                            _result->Release();
                        }
                    }

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("enable"));
            _module_.Unregister(_T("controls"));
        }

        POP_WARNING()

    } // namespace JMessageControl

} // namespace Exchange

} // namespace WPEFramework

