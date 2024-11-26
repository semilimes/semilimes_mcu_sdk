#include "provisioning.h"

/* Function: Provisioning.set

    create the json needed to Register and Claim the device

    Prototype:
        void Provisioning::set(const char* devId, const char* provKey);

    Parameters:
        devId - the device id, a unique ID that belongs to a specific device
        provKey - provisioning key, a one of the two keys needed to provision the device (the other key is the claim key and it is in form of a QR code to be scanned by the user to combine the device to a specific account)

    Returns:
        void
*/
void Provisioning::set(const char* devId, const char* provKey)
{
    int size = strlen("{\"deviceId\":\"\",\"provisioningKey\":\"\"}")+strlen(devId)+strlen(provKey)+1;
    json = new char[size];
    json_data.initJson(json);
    json_data.addPair2JsonStr(json, "deviceId", devId);
    json_data.addPair2JsonStr(json, "provisioningKey",provKey);

    size = strlen("{\"deviceId\":\"\"}")+strlen(devId)+1;
    json_reset = new char[size];
    json_data.initJson(json_reset);
    json_data.addPair2JsonStr(json_reset, "deviceId", devId);    
}

/* Function: Provisioning.get

    return the json script
    
    Prototype:
        void Provisioning::get();

    Parameters:

    Returns:
        char*
*/
char* Provisioning::get()
{
    return json;
}

/* Function: Provisioning.getRegisterDeviceURL

    provide the url to register the device

    Prototype:
        char* Provisioning::getRegisterDeviceURL();

    Parameters:

    Returns:
        char*
*/
char* Provisioning::getRegisterDeviceURL()
{
    return sme_httpsUrl sme_registerDevice;
}

/* Function: Provisioning.getDeviceClaimStatusURL

    provide the url to claim the device

    Prototype:
        char* Provisioning::getDeviceClaimStatusURL();

    Parameters:

    Returns:
        char*
*/
char* Provisioning::getDeviceClaimStatusURL()
{
    return sme_httpsUrl sme_deviceClaimStatus;
}

/* Function: Provisioning.getResetDeviceURL

    provide the url to reset the device

    Prototype:
        char* Provisioning::getResetDeviceURL();

    Parameters:

    Returns:
        char*
*/
char* Provisioning::getResetDeviceURL()
{
    return sme_httpsUrl sme_resetDevice;
}

/* Function: Provisioning.getReset

    return the json script to reset the device
    
    Prototype:
        void Provisioning::getReset();

    Parameters:

    Returns:
        char*
*/
char* Provisioning::getReset()
{
    return json_reset;
}
