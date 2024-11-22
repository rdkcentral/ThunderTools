#pragma once

#include "Module.h"

namespace Thunder {
namespace Exchange {

    // @json 1.0.0 @uncompliant:extended
    struct EXTERNAL IHello: virtual public Core::IUnknown {
        enum { ID = ID_VOLUMECONTROL };

        // @event @uncompliant:extended // NOTE: extended format is deprecated!! Do not just copy this line!
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_VOLUMECONTROL_NOTIFICATION };

            ~INotification() override = default;
            virtual void IHelloNotification() {};
        };

        ~IHello() override = default;

        virtual void Register(IHello::INotification* sink) {};
        virtual void Unregister(const IHello::INotification* sink) {};

        virtual uint32_t IHelloMethod1() = 0;
    };
}
}
