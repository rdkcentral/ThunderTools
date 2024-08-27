ADD_THUNDER_LICENSE

#pragma once

#include <interfaces/json/JSONRPC1.h>
#include <interfaces/json/JSONRPC2.h>
#include <interfaces/COMRPC1>
#include <interfaces/COMRPC2>

{{FORWARD DECLARATIONS}}

namespace Thunder {
namespace Plugin {

    class HelloWorld : public COMRPC1,public COMRPC2 {
        public:
        HelloWorld(const HelloWorld&) = delete;
        HelloWorld &operator=(const HelloWorld&) = delete;

        HelloWorld() :
        {{CONSTRUCTOR_VALUES}}
        {

        }

        ~HelloWorld override 
        {

        }

        {{NESTED_CLASS}}

        // Inherited Methods
        void COMRPC1Method1() override;
void COMRPC1Method2() override;
void COMRPC2Method1() override;
void COMRPC2Method2() override;

        // Plugin Methods
        void HelloWorldMethod(1);

        BEGIN_INTERFACE_MAP(HelloWorld)
        INTERFACE_ENTRY(COMRPC1)
INTERFACE_ENTRY(COMRPC2)
         
        END_INTERFACE_MAP

        private:
        
        DATA_MEMBER
    };
}
}
