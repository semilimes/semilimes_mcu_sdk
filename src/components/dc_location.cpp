#include "dc_location.h"

// Function: DcLocation.setObj

//     A location message containing coordinates

//     Prototype:
//         void DcLocation::setObj(char* locationName,float latitude, float longitude);

//     Parameters:
///@param         locationName - the name of the location 
///@param         latitude - latitude in decimal degrees
///@param         longitude - longitude in decimal degrees

//     Returns:
///@return         void
void DcLocation::setObj(char* locationName,float latitude, float longitude)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"dataComponentType","location");
    json_data.addPair2JsonStr(*pjson,"locationName",locationName);
    json_data.addPair2JsonFloat(*pjson,"latitude",latitude,6);
    json_data.addPair2JsonFloat(*pjson,"longitude",longitude,6);
}