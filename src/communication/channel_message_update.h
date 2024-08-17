#ifndef _update_to_channel_request_
#define _update_to_channel_request_

#include "../defines.h"

class ChannelMessageUpdate
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: ChannelMessageUpdate

//     This endpoint allows to update a specific message published in a channel.

//     Prototype:
//         void ChannelMessageUpdate(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    ChannelMessageUpdate(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: ChannelMessageUpdate.setObj

//     This endpoint allows to update a specific message published in a channel.

//     Prototype:
//         void setObj(char* messageId, char* dataComponent);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing groupChat
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void setObj(char* messageId, char* dataComponent);

// Function: ChannelMessageUpdate.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif