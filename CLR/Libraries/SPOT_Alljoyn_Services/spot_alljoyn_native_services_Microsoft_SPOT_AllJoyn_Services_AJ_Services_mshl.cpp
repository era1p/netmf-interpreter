//-----------------------------------------------------------------------------
//
//    ** DO NOT EDIT THIS FILE! **
//    This file was generated by a tool
//    re-running the tool will overwrite this file.
//
//-----------------------------------------------------------------------------

#define _XKEYCHECK_H

#include <alljoyn.h>
#include <aj_guid.h>    // for AJ_CreateNewGUID
#include <aj_crypto.h>  // for AJ_RandBytes
#include <aj_helper.h>
#include <aj_link_timeout.h>

#include <alljoyn/services_common/ServicesCommon.h>
#include <alljoyn/notification/NotificationCommon.h>
#include <alljoyn/notification/NotificationProducer.h>

#include <TinyCLR_Runtime.h>
#include <TinyCLR_Checks.h>
#include <TinyCLR_Diagnostics.h>
#include <TinyCLR_Version.h>


#include "spot_alljoyn_native_services.h"
#include "spot_alljoyn_native_services_Microsoft_SPOT_AllJoyn_Services_AJ_Services.h"

#define AJSVC_PROPERTY_STORE_NUMBER_OF_KEYS 13

typedef struct _PropertyStoreRuntimeEntry {
    char** value;
    uint8_t size;
} PropertyStoreConfigEntry;

// externs required to compile base_tcl. However, they are not used,
// so OK to make them NULL

const char*** propertyStoreDefaultValues = NULL;
const char* const* propertyStoreDefaultLanguages = NULL;
const char* deviceProductName = NULL;
const char* deviceManufactureName = NULL;
PropertyStoreConfigEntry* propertyStoreRuntimeValues = NULL;

AJ_Status AJNS_Producer_SendNotifySignal(AJ_BusAttachment* busAttachment, AJNS_Notification* notification, uint32_t ttl, uint32_t* messageSerialNumber);
AJ_Status InitNotificationContent();

const static char* lang1  = "en";
const static char* hello1 = "Toast is done!";

#define AJ_InfoPrintf(_msg)
#define NUM_TEXTS   1

using namespace Microsoft::SPOT::AllJoyn;

static AJNS_DictionaryEntry textToSend[NUM_TEXTS];
static AJNS_NotificationContent notificationContent;


AJ_Status InitNotificationContent()
{
    notificationContent.numTexts = NUM_TEXTS;
    textToSend[0].key   = lang1;
    textToSend[0].value = hello1;
    notificationContent.texts = textToSend;

    return AJNS_Producer_Start();    
}

using namespace Microsoft::SPOT::AllJoyn::Services;

HRESULT Library_spot_alljoyn_native_services_Microsoft_SPOT_AllJoyn_Services_AJ_Services::Initialize_NotificationService___MicrosoftSPOTAlljoynMicrosoftSPOTAllJoynAJStatus( CLR_RT_StackFrame& stack )
{
    TINYCLR_HEADER(); hr = S_OK;
    {
        AJ_Status status =InitNotificationContent();
        TINYCLR_CHECK_HRESULT( hr );
        SetResult_INT32( stack, status );
    }
    TINYCLR_NOCLEANUP();
}

HRESULT Library_spot_alljoyn_native_services_Microsoft_SPOT_AllJoyn_Services_AJ_Services::SendNotifySignal___MicrosoftSPOTAlljoynMicrosoftSPOTAllJoynAJStatus__U4__MicrosoftSPOTAllJoynServicesAJServicesAJNSNotification__U4__STRING__BYREF_U4( CLR_RT_StackFrame& stack )
{
    TINYCLR_HEADER(); hr = S_OK;
    {
        typedef Library_spot_alljoyn_native_services_Microsoft_SPOT_AllJoyn_Services_AJ_Services__AJNS_Notification Managed_AJNS_Notification;
        
        AJ_BusAttachment * bus =  (AJ_BusAttachment *)stack.Arg1().NumericByRef().u4;
        
        CLR_RT_HeapBlock * managedObj = stack.Arg2().Dereference();
        FAULT_ON_NULL(managedObj);
        
        AJNS_Notification ntf = {0};
        ntf.version             = managedObj[Managed_AJNS_Notification::FIELD__version].NumericByRef().u2;
        ntf.messageType         = managedObj[Managed_AJNS_Notification::FIELD__messageType].NumericByRef().u2;
        ntf.notificationId      = managedObj[Managed_AJNS_Notification::FIELD__notificationId].NumericByRef().s4;
        ntf.originalSenderName  = managedObj[Managed_AJNS_Notification::FIELD__originalSenderName].DereferenceString()->StringText();
        ntf.deviceId            = managedObj[Managed_AJNS_Notification::FIELD__deviceId].DereferenceString()->StringText();
        ntf.deviceName          = managedObj[Managed_AJNS_Notification::FIELD__deviceName].DereferenceString()->StringText();
        ntf.appId               = managedObj[Managed_AJNS_Notification::FIELD__appId].DereferenceString()->StringText();
        ntf.appName             = managedObj[Managed_AJNS_Notification::FIELD__appName].DereferenceString()->StringText();
        ntf.content             = &notificationContent;

        
        UINT32 ttl = stack.Arg3().NumericByRef().u4;
        CLR_RT_HeapBlock_String * message = stack.Arg4().DereferenceString();
        
        UINT32 * param4;
        UINT8 heapblock2[CLR_RT_HEAP_BLOCK_SIZE];
        TINYCLR_CHECK_HRESULT( Interop_Marshal_UINT32_ByRef( stack, heapblock2, 5, param4 ) );

        textToSend[0].key   = lang1;
        textToSend[0].value = message->StringText();

        AJ_Status status = AJNS_Producer_SendNotifySignal(bus, &ntf, ttl, param4);
        
        TINYCLR_CHECK_HRESULT( hr );
        SetResult_INT32( stack, status );

        TINYCLR_CHECK_HRESULT( Interop_Marshal_StoreRef( stack, heapblock2, 5 ) );

        
    }
    TINYCLR_NOCLEANUP();
}
