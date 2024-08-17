#ifndef _groupchat_reaction_send_
#define _groupchat_reaction_send_

#include "../defines.h"

class GroupchatReactionSend
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: GroupchatReactionSend

//     This endpoint allows the account to add a reaction from a specific message in a Group Chat.

//     Prototype:
//         void GroupchatReactionSend(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    GroupchatReactionSend(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: GroupchatReactionSend.setObj

//     This endpoint allows the account to add a reaction from a specific message in a Group Chat.

//     Prototype:
//         void setObj(char* messageId, char* reaction);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing groupChat
///@param         reaction - 

//     Returns:
///@returns         void
    void setObj(char* messageId, char* reaction);

// Function: GroupchatReactionSend.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif