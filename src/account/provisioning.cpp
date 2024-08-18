#include "provisioning.h"

/* Function: Provisioning.setObj

    create the json needed to Register and Claim the device

    Prototype:
        void Provisioning::setObj(char* devId, char* provKey);

    Parameters:
        devId - the device id, a unique ID that belongs to a specific device
        provKey - provisioning key, a one of the two keys needed to provision the device (the other key is the claim key and it is in form of a QR code to be scanned by the user to combine the device to a specific account)

    Returns:
        void
*/
void Provisioning::setObj(char* devId, char* provKey)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson, "deviceId", devId);
    json_data.addPair2JsonStr(*pjson, "provisioningKey",provKey);
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