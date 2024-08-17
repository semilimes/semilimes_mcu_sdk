#ifndef _groupchat_invite_
#define _groupchat_invite_

#include "../defines.h"

class GroupchatInvite
{
private:
    SmeJson json_data;
    char** pjson;
    char** pjsonArray;
    
public:
// Function: GroupchatInvite

//    This endpoint allows to invite other recipients to the specified group chat.

//     Prototype:
//         void GroupchatInvite(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 
///@param         jsonArray - it is a temporary char array that will contain the data recipientsIds 

//     Returns:
///@return         void
    GroupchatInvite(char* json, char* jsonArray)
    {
        pjson = &json;
        pjsonArray = &jsonArray;
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
    }

// Function: GroupchatInvite.setObj

//    This endpoint allows to invite other recipients to the specified group chat.

//     Prototype:
//         void setObj(char* groupChatIds)

//     Parameters:
///@param         groupChatId - is the unique Id to reference an existing groupChat

//     Returns:
///@returns         void
    void setObj(char* groupChatIds);

// Function: GroupchatInvite.addRecipientIds

//     Add the recipientId 

//     Prototype:
//         void addRecipientIds(char* recipientIds);

//     Parameters:
///@param         recipientIds - the json script of the dataComponent to invite

//     Returns:
///@returns         void
    void addRecipientIds(char* recipientIds);

// Function: GroupchatInvite.appendRecipientIds

//     Append the selected recipientIds

//     Prototype:
//         void appendRecipientIds();

//     Parameters:

//     Returns:
///@returns         void
    void appendRecipientIds();

// Function: GetGroupchatMessage.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif