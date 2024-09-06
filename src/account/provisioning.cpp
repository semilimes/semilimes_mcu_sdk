#include "provisioning.h"

/* Function: Provisioning.set

    create the json needed to Register and Claim the device

    Prototype:
        void Provisioning::set(char* devId, char* provKey);

    Parameters:
        devId - the device id, a unique ID that belongs to a specific device
        provKey - provisioning key, a one of the two keys needed to provision the device (the other key is the claim key and it is in form of a QR code to be scanned by the user to combine the device to a specific account)

    Returns:
        void
*/
void Provisioning::set(char* devId, char* provKey)
{
    int size = headerSize+strlen(devId)+strlen(provKey)+1;
    json = new char[size];
    json_data.initJson(json);
    json_data.addPair2JsonStr(json, "deviceId", devId);
    json_data.addPair2JsonStr(json, "provisioningKey",provKey);
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
    return httpsUrl registerDevice;
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
    return httpsUrl deviceClaimStatus;
}