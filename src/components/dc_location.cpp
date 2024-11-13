#include "dc_location.h"

// Function: DcLocation.set

//     A location message containing coordinates

//     Prototype:
//         void DcLocation::set(const char* locationName,float latitude, float longitude);

//     Parameters:
///@param         locationName - the name of the location 
///@param         latitude - latitude in decimal degrees
///@param         longitude - longitude in decimal degrees

//     Returns:
///@return         void
void DcLocation::set(const char* locationName,float latitude, float longitude)
{
    int ndigits = 6;
    int size = strlen("{\"dataComponentType\":\"location\",\"locationName\":\"\",\"latitude\":,\"longitude\":}")+strlen(locationName)+json_data.floatStrSize(longitude, ndigits)+json_data.floatStrSize(latitude, ndigits)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"dataComponentType","location");
    json_data.addPair2JsonStr(json,"locationName",locationName);
    json_data.addPair2JsonFloat(json,"latitude",latitude,ndigits);
    json_data.addPair2JsonFloat(json,"longitude",longitude,ndigits);
}

/* Function: DcLocation.get

    return the json script

    Prototype:
        void DcLocation::get();

    Parameters:

    Returns:
        char*
*/
char* DcLocation::get()
{
    return json;
}