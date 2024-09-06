#ifndef _dc_location_
#define _dc_location_

#include "../defines.h"

class DcLocation
{
private:
    #define headerSize 75
    SmeJson json_data;
    char* json = nullptr;

public:
// Function: ~DcLocation

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~DcLocation()

//     Parameters:

//     Returns:
///@return         void
    ~DcLocation()
    {
        delete[] json;
        json = nullptr;
    }

// Function: DcLocation.set

//    A location message containing coordinates

//    Prototype:
//        void DcLocation::set(char* locationName,float latitude, float longitude);

//    Parameters:
///@param        locationName - the name of the location 
///@param        latitude - latitude in decimal degrees
///@param        longitude - longitude in decimal degrees

//    Returns:
///@return         void
    void set(char* locationName,float latitude, float longitude);

// Function: DcLocation.get

//     return the json script

//     Prototype:
//         void DcLocation::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif