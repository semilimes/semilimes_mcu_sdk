#ifndef _provisioning_
#define _provisioning_

#include "../defines.h"

class Provisioning
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: Provisioning

//     acquire the keys needed to provision the device

//     Prototype:
//         void Provisioning(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    Provisioning(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: Provisioning.setObj

//     create the json needed to Register and Claim the device

//     Prototype:
//         void Provisioning::setObj(char* devId, char* provKey);

//     Parameters:
///@param          devId - the device id, a unique ID that belongs to a specific device
///@param          provKey - provisioning key, a one of the two keys needed to provision the device (the other key is the claim key and it is in form of a QR code to be scanned by the user to combine the device to a specific account)

//     Returns:
///@returns         char*
    void setObj(char* devId, char* provKey);

// Function: Provisioning.getRegisterDeviceURL

//     provide the url to register the device

//     Prototype:
//         char* Provisioning::getRegisterDeviceURL();

//     Parameters:

//     Returns:
///@returns         char*
    char* getRegisterDeviceURL();

// Function: Provisioning.getDeviceClaimStatusURL

//     provide the url to claim the device

//     Prototype:
//         char* Provisioning::getDeviceClaimStatusURL();

//     Parameters:

//     Returns:
///@returns         char*
    char* getDeviceClaimStatusURL();
};

#endif