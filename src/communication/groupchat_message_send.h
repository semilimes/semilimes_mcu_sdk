#ifndef _groupchat_message_send_
#define _groupchat_message_send_

#include "../defines.h"

class GroupchatMessageSend
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: GroupchatMessageSend

//     This endpoint allows to send a data component to a groupChat as a new message.

//     Prototype:
//         void GroupchatMessageSend(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    GroupchatMessageSend(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: GroupchatMessageSend.setObj

//     This endpoint allows to send a data component to a groupChat as a new message.

//     Prototype:
//         void setObj(char* groupChatId, char* dataComponent);

//     Parameters:
///@param         groupChatId - is the unique Id to reference an existing groupChat
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void setObj(char* groupChatId, char* dataComponent);

// Function: GroupchatMessageSend.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif