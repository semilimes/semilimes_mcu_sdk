#ifndef _groupchat_reaction_remove_
#define _groupchat_reaction_remove_

#include "../defines.h"

class GroupchatReactionRemove
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: GroupchatReactionRemove

//     This endpoint allows the account to remove a reaction from a specific message in a Group Chat.

//     Prototype:
//         void GroupchatReactionRemove(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    GroupchatReactionRemove(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: GroupchatReactionRemove.setObj

//     This endpoint allows the account to remove a reaction from a specific message in a Group Chat.

//     Prototype:
//         void setObj(char* messageId, char* reaction);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing groupChat
///@param         reaction - 

//     Returns:
///@returns         void
    void setObj(char* messageId, char* reaction);

// Function: GroupchatReactionRemove.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif