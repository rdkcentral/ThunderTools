/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2026 [PLEASE ADD COPYRIGHT NAME!]
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "Module.h"
#include <interfaces/IBrowser.h>

namespace Thunder {
namespace Plugin {

    class OutOfProcessImplementation : public Exchange::IBrowser, public Exchange::IWebBrowser, public Exchange::IWebBrowserExt, public Exchange::IBrowserResources, public Exchange::IBrowserSecurity, public Exchange::IBrowserScripting, public Exchange::IBrowserCookieJar {
    public:
        OutOfProcessImplementation(const OutOfProcessImplementation&) = delete;
        OutOfProcessImplementation& operator=(const OutOfProcessImplementation&) = delete;
        OutOfProcessImplementation(OutOfProcessImplementation&&) = delete;
        OutOfProcessImplementation& operator=(OutOfProcessImplementation&&) = delete;

        OutOfProcessImplementation()
            : Exchange::IBrowser()
            , Exchange::IWebBrowser()
            , Exchange::IWebBrowserExt()
            , Exchange::IBrowserResources()
            , Exchange::IBrowserSecurity()
            , Exchange::IBrowserScripting()
            , Exchange::IBrowserCookieJar()
            , _adminLock()
            , _browserNotification()
        {
        }
        ~OutOfProcessImplementation() override = default;

    public:

        BEGIN_INTERFACE_MAP(OutOfProcessImplementation)
            INTERFACE_ENTRY(Exchange::IBrowser)
            INTERFACE_ENTRY(Exchange::IWebBrowser)
            INTERFACE_ENTRY(Exchange::IWebBrowserExt)
            INTERFACE_ENTRY(Exchange::IBrowserResources)
            INTERFACE_ENTRY(Exchange::IBrowserSecurity)
            INTERFACE_ENTRY(Exchange::IBrowserScripting)
            INTERFACE_ENTRY(Exchange::IBrowserCookieJar)
        END_INTERFACE_MAP

        // IBrowser methods

        void Register(Exchange::IBrowser::INotification* notification) override {

            ASSERT(notification != nullptr);

            _adminLock.Lock();
            auto item = std::find(_browserNotification.begin(), _browserNotification.end(), notification);
            ASSERT(item == _browserNotification.end());

            if (item == _browserNotification.end()) {
                notification->AddRef();
                _browserNotification.push_back(notification);
            }

            _adminLock.Unlock();

        }

        void Unregister(const Exchange::IBrowser::INotification* notification) override {

            ASSERT(notification != nullptr);

            _adminLock.Lock();
            auto item = std::find(_browserNotification.begin(), _browserNotification.end(), notification);
            ASSERT(item != _browserNotification.end());

            if (item != _browserNotification.end()) {
                _browserNotification.erase(item);
                notification->Release();
            }
            _adminLock.Unlock();

        }

        void SetURL(const string& /* URL */) override {
            return Core::ERROR_NONE;
        }

        string GetURL() const override {
            return Core::ERROR_NONE;
        }

        uint32_t GetFPS() const override {
            return Core::ERROR_NONE;
        }

        void Hide(const bool /* hidden */) override {
            return Core::ERROR_NONE;
        }

        // IWebBrowser methods

        void LoadFinished(const string& /* URL */, const int32_t /* httpstatus */) override {
            return Core::ERROR_NONE;
        }

        void LoadFailed(const string& /* URL */) override {
            return Core::ERROR_NONE;
        }

        void URLChange(const string& /* URL */, const bool /* loaded */) override {
            return Core::ERROR_NONE;
        }

        void VisibilityChange(const bool /* hidden */) override {
            return Core::ERROR_NONE;
        }

        void PageClosure() override {
            return Core::ERROR_NONE;
        }

        void BridgeQuery(const string& /* message */) override {
            return Core::ERROR_NONE;
        }

        void Register(INotification* /* sink */) override {
            return Core::ERROR_NONE;
        }

        void Unregister(INotification* /* sink */) override {
            return Core::ERROR_NONE;
        }

        uint32_t URL(string& /* url */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t URL(const string& /* url */) override {
            return Core::ERROR_NONE;
        }

        uint32_t Visibility(VisibilityType& /* visible */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t Visibility(const VisibilityType /* visible */) override {
            return Core::ERROR_NONE;
        }

        uint32_t FPS(uint8_t& /* fps */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        Core::hresult HeaderList(string& /* headerlist */ /* @out @opaque */) const override {
            return Core::ERROR_NONE;
        }

        Core::hresult HeaderList(const string& /* headerlist */ /* @opaque */) override {
            return Core::ERROR_NONE;
        }

        uint32_t UserAgent(string& /* useragent */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t UserAgent(const string& /* useragent */) override {
            return Core::ERROR_NONE;
        }

        uint32_t LocalStorageEnabled(bool& /* enabled */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t LocalStorageEnabled(const bool /* enabled */) override {
            return Core::ERROR_NONE;
        }

        uint32_t HTTPCookieAcceptPolicy(HTTPCookieAcceptPolicyType& /* policy */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t HTTPCookieAcceptPolicy(const HTTPCookieAcceptPolicyType /* policy */) override {
            return Core::ERROR_NONE;
        }

        uint32_t BridgeReply(const string& /* payload */) override {
            return Core::ERROR_NONE;
        }

        uint32_t BridgeEvent(const string& /* payload */) override {
            return Core::ERROR_NONE;
        }

        uint32_t CollectGarbage() override {
            return Core::ERROR_NONE;
        }

        // IWebBrowserExt methods

        Core::hresult DeleteDir(const string& /* path */) override {
            return Core::ERROR_NONE;
        }

        Core::hresult Languages(IStringIterator*& /* languages */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        Core::hresult Languages(IStringIterator* const /* languages */) override {
            return Core::ERROR_NONE;
        }

        // IBrowserResources methods

        uint32_t Headers(IStringIterator*& /* header */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t Headers(IStringIterator* const /* header */) override {
            return Core::ERROR_NONE;
        }

        uint32_t UserScripts(IStringIterator*& /* uris */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t UserScripts(IStringIterator* const /* uris */) override {
            return Core::ERROR_NONE;
        }

        uint32_t UserStyleSheets(IStringIterator*& /* uris */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t UserStyleSheets(IStringIterator* const /* uris */) override {
            return Core::ERROR_NONE;
        }

        // IBrowserSecurity methods

        uint32_t SecurityProfile(string& /* profile */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t SecurityProfile(const string& /* profile */) override {
            return Core::ERROR_NONE;
        }

        uint32_t MixedContentPolicy(MixedContentPolicyType& /* policy */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t MixedContentPolicy(const MixedContentPolicyType /* policy */) override {
            return Core::ERROR_NONE;
        }

        // IBrowserScripting methods

        uint32_t RunJavaScript(const string& /* script */) override {
            return Core::ERROR_NONE;
        }

        uint32_t AddUserScript(const string& /* script */, const bool /* topFrameOnly */) override {
            return Core::ERROR_NONE;
        }

        uint32_t RemoveAllUserScripts() override {
            return Core::ERROR_NONE;
        }

        // IBrowserCookieJar methods

        void CookieJarChanged() override {
            return Core::ERROR_NONE;
        }

        void Register(INotification* /* sink */) override {
            return Core::ERROR_NONE;
        }

        void Unregister(INotification* /* sink */) override {
            return Core::ERROR_NONE;
        }

        uint32_t CookieJar(Config& /* cookieJarInfo */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t CookieJar(const Config& /* cookieJarInfo */) override {
            return Core::ERROR_NONE;
        }
    private:
        using BrowserNotificationContainer = std::vector<Exchange::IBrowser::INotification*>;

        void NotifyLoadFinished(const string& URL) const {
            _adminLock.Lock();
            for (auto* notification : _browserNotification) {
                notification->LoadFinished(URL);
            }
            _adminLock.Unlock();
        }

        void NotifyURLChanged(const string& URL) const {
            _adminLock.Lock();
            for (auto* notification : _browserNotification) {
                notification->URLChanged(URL);
            }
            _adminLock.Unlock();
        }

        void NotifyHidden(const bool hidden) const {
            _adminLock.Lock();
            for (auto* notification : _browserNotification) {
                notification->Hidden(hidden);
            }
            _adminLock.Unlock();
        }

        void NotifyClosure() const {
            _adminLock.Lock();
            for (auto* notification : _browserNotification) {
                notification->Closure();
            }
            _adminLock.Unlock();
        }

        mutable Core::CriticalSection _adminLock;
        BrowserNotificationContainer _browserNotification;
    };

    SERVICE_REGISTRATION(OutOfProcessImplementation, 1, 0)
} // Plugin
} // Thunder