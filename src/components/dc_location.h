#ifndef _dc_location_
#define _dc_location_

#include "../defines.h"

class DcLocation
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: DcLocation

//    A location message containing coordinates

//     Prototype:
//         void DcLocation(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    DcLocation(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: DcLocation.setObj

//    A location message containing coordinates

//    Prototype:
//        void DcLocation::setObj(char* locationName,float latitude, float longitude);

//    Parameters:
///@param        locationName - the name of the location 
///@param        latitude - latitude in decimal degrees
///@param        longitude - longitude in decimal degrees

//    Returns:
///@return         void
    void setObj(char* locationName,float latitude, float longitude);
};

#endif