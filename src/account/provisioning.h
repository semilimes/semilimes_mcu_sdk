#ifndef _provisioning_
#define _provisioning_

#include "../defines.h"

class Provisioning
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    char* json_reset = nullptr; 

public:
// Function: ~Provisioning

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~Provisioning()

//     Parameters:

//     Returns:
///@return         void
    ~Provisioning()
    {
        delete[] json;
        json = nullptr;
        delete[] json_reset;
        json_reset = nullptr;
    }

// Function: Provisioning.set

//     create the json needed to Register and Claim the device

//     Prototype:
//         void Provisioning::set(const char* devId, const char* provKey);

//     Parameters:
///@param          devId - the device id, a unique ID that belongs to a specific device
///@param          provKey - provisioning key, a one of the two keys needed to provision the device (the other key is the claim key and it is in form of a QR code to be scanned by the user to combine the device to a specific account)

//     Returns:
///@returns         char*
    void set(const char* devId, const char* provKey);

// Function: Provisioning.get

//     return the json script

//     Prototype:
//         void Provisioning::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();

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

// Function: Provisioning.getResetDeviceURL

//     provide the url to reset the device

//     Prototype:
//         char* Provisioning::getResetDeviceURL();

//     Parameters:

//     Returns:
///@returns         char*
    char* getResetDeviceURL();

// Function: Provisioning.getReset

//     return the json script to reset the device

//     Prototype:
//         void Provisioning::getReset();

//     Parameters:

//     Returns:
///@return         char*
    char* getReset();
};

#endif