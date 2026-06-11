// Generated automatically from 'IDolby.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_DolbyOutput.h"
#include <interfaces/IDolby.h>

namespace WPEFramework {

namespace Exchange {

    namespace Dolby {

        namespace JOutput {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, Dolby::IOutput* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JOutput"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Property: 'dolbyatmossupported' - Atmos capabilities of Sink (r/o)
                _module__.PluginHost::JSONRPC::Register<void, Core::JSON::Boolean>(_T("dolbyatmossupported"),
                    [_implementation__](Core::JSON::Boolean& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        bool _result_{};

                        _errorCode__ = _implementation__->AtmosMetadata(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'dolby_atmosmetadata' - Atmos capabilities of Sink (DEPRECATED) (r/o)
                _module__.PluginHost::JSONRPC::Register<void, Core::JSON::Boolean>(_T("dolby_atmosmetadata"),
                    [_implementation__](Core::JSON::Boolean& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        bool _result_{};

                        _errorCode__ = _implementation__->AtmosMetadata(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'dolbysoundmode' - Sound Mode - Mono/Stereo/Surround (r/o)
                _module__.PluginHost::JSONRPC::Register<void, Core::JSON::EnumType<Exchange::Dolby::IOutput::SoundModes>>(_T("dolbysoundmode"),
                    [_implementation__](Core::JSON::EnumType<Exchange::Dolby::IOutput::SoundModes>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::Dolby::IOutput::SoundModes _result_{};

                        _errorCode__ = _implementation__->SoundMode(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'dolby_soundmode' - Sound Mode - Mono/Stereo/Surround (DEPRECATED) (r/o)
                _module__.PluginHost::JSONRPC::Register<void, Core::JSON::EnumType<Exchange::Dolby::IOutput::SoundModes>>(_T("dolby_soundmode"),
                    [_implementation__](Core::JSON::EnumType<Exchange::Dolby::IOutput::SoundModes>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::Dolby::IOutput::SoundModes _result_{};

                        _errorCode__ = _implementation__->SoundMode(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'dolbyatmosoutput' - Enable Atmos Audio Output (w/o)
                _module__.PluginHost::JSONRPC::Register<Core::JSON::Boolean, void>(_T("dolbyatmosoutput"),
                    [_implementation__](const Core::JSON::Boolean& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (params.IsSet() == false) {
                            TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JOutput"), _T("dolbyatmosoutput")));
                        }

                        const bool _params_{params};

                        _errorCode__ = _implementation__->EnableAtmosOutput(_params_);

                        return (_errorCode__);
                    });

                // Property: 'dolby_enableatmosoutput' - Enable Atmos Audio Output (DEPRECATED) (w/o)
                _module__.PluginHost::JSONRPC::Register<Core::JSON::Boolean, void>(_T("dolby_enableatmosoutput"),
                    [_implementation__](const Core::JSON::Boolean& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (params.IsSet() == false) {
                            TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JOutput"), _T("dolby_enableatmosoutput")));
                        }

                        const bool _params_{params};

                        _errorCode__ = _implementation__->EnableAtmosOutput(_params_);

                        return (_errorCode__);
                    });

                // Property: 'dolbymode' - Dolby Mode
                _module__.PluginHost::JSONRPC::Register<Core::JSON::EnumType<Exchange::Dolby::IOutput::Type>, Core::JSON::EnumType<Exchange::Dolby::IOutput::Type>>(_T("dolbymode"),
                    [_implementation__](const Core::JSON::EnumType<Exchange::Dolby::IOutput::Type>& params, Core::JSON::EnumType<Exchange::Dolby::IOutput::Type>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (params.IsSet() == false) {
                            Exchange::Dolby::IOutput::Type _result_{};

                            _errorCode__ = (static_cast<const Dolby::IOutput*>(_implementation__))->Mode(_result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {
                            const Exchange::Dolby::IOutput::Type _params_{params};

                            _errorCode__ = _implementation__->Mode(_params_);

                            result.Null(true);
                        }

                        return (_errorCode__);
                    });

                // Property: 'dolby_mode' - Dolby Mode
                _module__.PluginHost::JSONRPC::Register<Core::JSON::EnumType<Exchange::Dolby::IOutput::Type>, Core::JSON::EnumType<Exchange::Dolby::IOutput::Type>>(_T("dolby_mode"),
                    [_implementation__](const Core::JSON::EnumType<Exchange::Dolby::IOutput::Type>& params, Core::JSON::EnumType<Exchange::Dolby::IOutput::Type>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (params.IsSet() == false) {
                            Exchange::Dolby::IOutput::Type _result_{};

                            _errorCode__ = (static_cast<const Dolby::IOutput*>(_implementation__))->Mode(_result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {
                            const Exchange::Dolby::IOutput::Type _params_{params};

                            _errorCode__ = _implementation__->Mode(_params_);

                            result.Null(true);
                        }

                        return (_errorCode__);
                    });

            }

            template<typename MODULE>
            static void Unregister(MODULE& _module__)
            {
                // Unregister methods and properties...
                _module__.PluginHost::JSONRPC::Unregister(_T("dolbyatmossupported"));
                _module__.PluginHost::JSONRPC::Unregister(_T("dolby_atmosmetadata"));
                _module__.PluginHost::JSONRPC::Unregister(_T("dolbysoundmode"));
                _module__.PluginHost::JSONRPC::Unregister(_T("dolby_soundmode"));
                _module__.PluginHost::JSONRPC::Unregister(_T("dolbyatmosoutput"));
                _module__.PluginHost::JSONRPC::Unregister(_T("dolby_enableatmosoutput"));
                _module__.PluginHost::JSONRPC::Unregister(_T("dolbymode"));
                _module__.PluginHost::JSONRPC::Unregister(_T("dolby_mode"));
            }

            namespace Event {

                // Event: 'soundmodechanged' - Signal audio mode change
                template<typename MODULE>
                static void AudioModeChanged(const MODULE& module_, const JsonData::Dolby::Output::AudioModeChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("soundmodechanged"), params, sendIfMethod_);
                    module_.Notify(_T("dolby_audiomodechanged"), params, sendIfMethod_);
                }

                // Event: 'soundmodechanged' - Signal audio mode change
                template<typename MODULE>
                static void AudioModeChanged(const MODULE& module_, const Core::JSON::EnumType<Exchange::Dolby::IOutput::SoundModes>& mode, const Core::JSON::Boolean& enabled, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::Dolby::Output::AudioModeChangedParamsData params_;
                    params_.Mode = mode;
                    params_.Enabled = enabled;

                    AudioModeChanged(module_, params_, sendIfMethod_);
                }

                // Event: 'soundmodechanged' - Signal audio mode change
                template<typename MODULE>
                static void AudioModeChanged(const MODULE& module_, const Dolby::IOutput::SoundModes mode, const bool enabled, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::Dolby::Output::AudioModeChangedParamsData params_;
                    params_.Mode = mode;
                    params_.Enabled = enabled;

                    AudioModeChanged(module_, params_, sendIfMethod_);
                }

            } // namespace Event

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JOutput

    } // namespace Dolby

} // namespace Exchange

} // namespace WPEFramework

