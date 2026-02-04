// Enumeration code for DNSServer API.
// Generated automatically from 'IDNSServer.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IDNSServer.h>
#include "JsonData_DNSServer.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IDNSServer::Record::type)
    { Exchange::IDNSServer::Record::type::INVALID, _TXT("INVALID") },
    { Exchange::IDNSServer::Record::type::RECORD_A, _TXT("RECORD_A") },
    { Exchange::IDNSServer::Record::type::RECORD_NS, _TXT("RECORD_NS") },
    { Exchange::IDNSServer::Record::type::RECORD_MD, _TXT("RECORD_MD") },
    { Exchange::IDNSServer::Record::type::RECORD_MF, _TXT("RECORD_MF") },
    { Exchange::IDNSServer::Record::type::RECORD_CNAME, _TXT("RECORD_CNAME") },
    { Exchange::IDNSServer::Record::type::RECORD_SOA, _TXT("RECORD_SOA") },
    { Exchange::IDNSServer::Record::type::RECORD_MB, _TXT("RECORD_MB") },
    { Exchange::IDNSServer::Record::type::RECORD_MG, _TXT("RECORD_MG") },
    { Exchange::IDNSServer::Record::type::RECORD_MR, _TXT("RECORD_MR") },
    { Exchange::IDNSServer::Record::type::RECORD_NULL, _TXT("RECORD_NULL") },
    { Exchange::IDNSServer::Record::type::RECORD_WKS, _TXT("RECORD_WKS") },
    { Exchange::IDNSServer::Record::type::RECORD_PTR, _TXT("RECORD_PTR") },
    { Exchange::IDNSServer::Record::type::RECORD_HINFO, _TXT("RECORD_HINFO") },
    { Exchange::IDNSServer::Record::type::RECORD_MINFO, _TXT("RECORD_MINFO") },
    { Exchange::IDNSServer::Record::type::RECORD_MX, _TXT("RECORD_MX") },
    { Exchange::IDNSServer::Record::type::RECORD_TXT, _TXT("RECORD_TXT") },
    { Exchange::IDNSServer::Record::type::RECORD_AAAA, _TXT("RECORD_AAAA") },
    { Exchange::IDNSServer::Record::type::REQUEST_AXFR, _TXT("REQUEST_AXFR") },
    { Exchange::IDNSServer::Record::type::REQUEST_MAILB, _TXT("REQUEST_MAILB") },
    { Exchange::IDNSServer::Record::type::REQUEST_MAILA, _TXT("REQUEST_MAILA") },
    { Exchange::IDNSServer::Record::type::REQUEST_ALL, _TXT("REQUEST_ALL") },
ENUM_CONVERSION_END(Exchange::IDNSServer::Record::type)

}
