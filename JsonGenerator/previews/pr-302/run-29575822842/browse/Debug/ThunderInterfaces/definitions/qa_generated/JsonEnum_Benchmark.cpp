// Enumeration code for Benchmark API.
// Generated automatically from 'IBenchmark.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <qa_interfaces/IBenchmark.h>
#include "JsonData_Benchmark.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(QualityAssurance::IBenchmark::FailureReason)
    { QualityAssurance::IBenchmark::FailureReason::LATENCY_THRESHOLD_EXCEEDED, _TXT("LATENCY_THRESHOLD_EXCEEDED") },
    { QualityAssurance::IBenchmark::FailureReason::MEMORY_THRESHOLD_EXCEEDED, _TXT("MEMORY_THRESHOLD_EXCEEDED") },
    { QualityAssurance::IBenchmark::FailureReason::LATENCY_AND_MEMORY_THRESHOLD_EXCEEDED, _TXT("LATENCY_AND_MEMORY_THRESHOLD_EXCEEDED") },
ENUM_CONVERSION_END(QualityAssurance::IBenchmark::FailureReason)

}
