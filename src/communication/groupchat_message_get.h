#ifndef _groupchat_message_get_
#define _groupchat_message_get_

#include "../defines.h"

class GroupchatMessageGet
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: GroupchatMessageGet

//     This endpoint returns a list of messages in the specified Group chat.

//     Prototype:
//         void GroupchatMessageGet(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    GroupchatMessageGet(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: GroupchatMessageGet.setObj

//     This endpoint returns a list of messages in the specified Group chat.

//     Prototype:
//         void setObj(char* groupChatId,char* messageId,int limit);

//     Parameters:
///@param         groupChatId - is the unique Id to reference an existing groupChat
///@param         messageId - is the unique Id to reference an existing groupChat
///@param         limit - sets the limit of the messages to receive

//     Returns:
///@returns         void
    void setObj(char* groupChatId,char* messageId,int limit);

// Function: GroupchatMessageGet.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif