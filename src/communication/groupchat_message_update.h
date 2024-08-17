#ifndef _groupchat_message_update_
#define _groupchat_message_update_

#include "../defines.h"

class GroupchatMessageUpdate
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: GroupchatMessageUpdate

//     This endpoint allows to update a specific message published in a group Chat

//     Prototype:
//         void GroupchatMessageUpdate(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    GroupchatMessageUpdate(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: GroupchatMessageUpdate.setObj

//     This endpoint allows to update a specific message published in a group Chat

//     Prototype:
//         void setObj(char* messageId, char* dataComponent);

//     Parameters:
///@param         channelId - is the unique Id to reference an existing channel
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void setObj(char* messageId, char* dataComponent);

// Function: GroupchatMessageUpdate.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif