// Enumeration code for AVSController API.
// Generated automatically from 'IAVSClient.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IAVSClient.h>
#include "JsonData_AVSController.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IAVSController::INotification::dialoguestate)
    { Exchange::IAVSController::INotification::dialoguestate::IDLE, _TXT("Idle") },
    { Exchange::IAVSController::INotification::dialoguestate::LISTENING, _TXT("Listening") },
    { Exchange::IAVSController::INotification::dialoguestate::EXPECTING, _TXT("Expecting") },
    { Exchange::IAVSController::INotification::dialoguestate::THINKING, _TXT("Thinking") },
    { Exchange::IAVSController::INotification::dialoguestate::SPEAKING, _TXT("Speaking") },
ENUM_CONVERSION_END(Exchange::IAVSController::INotification::dialoguestate)

}
