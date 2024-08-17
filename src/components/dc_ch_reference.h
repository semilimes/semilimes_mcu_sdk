#ifndef _dc_ch_reference_
#define _dc_ch_reference_

#include "../defines.h"

class DcChReference
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: DcChReference

//     A message referencing an existing Channel

//     Prototype:
//         void DcChReference(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    DcChReference(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: DcChReference.setObj

//     A message referencing an existing Channel

//     Prototype:
//         void DcChReference::setObj(char* channelId);

//     Parameters:
///@param         channelId - the id of the referenced channel
        
//     Returns:
///@return         void

    void setObj(char* channelId);
};

#endif