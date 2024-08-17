#ifndef _groupchat_message_reply_
#define _groupchat_message_reply_

#include "../defines.h"

class GroupchatMessageReply
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: GroupchatMessageReply

//     This endpoint allows the account to reply to a specific message with a simple text.

//     Prototype:
//         void GroupchatMessageReply(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    GroupchatMessageReply(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: GroupchatMessageReply.setObj

//     This endpoint allows the account to reply to a specific message with a simple text.

//     Prototype:
//         void setObj(char* messageId, char* dataComponent);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing groupChat
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void setObj(char* messageId, char* dataComponent);

// Function: GroupchatMessageReply.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif