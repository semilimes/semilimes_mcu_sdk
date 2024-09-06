#ifndef _groupchat_invite_
#define _groupchat_invite_

#include "../defines.h"

class GroupchatInvite
{
private:
    #define headerSize 34
    #define headerArraySize 2
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;
    
public:
// Function: ~GroupchatInvite

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GroupchatInvite()

//     Parameters:

//     Returns:
///@return         void
    ~GroupchatInvite()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: GroupchatInvite.set

//    This endpoint allows to invite other recipients to the specified group chat.

//     Prototype:
//         void set(char* groupChatIds)

//     Parameters:
///@param         groupChatId - is the unique Id to reference an existing groupChat

//     Returns:
///@returns         void
    void set(char* groupChatId);

// Function: GroupchatInvite.addRecipientId

//     Add the recipientId 

//     Prototype:
//         void addRecipientId(char* recipientId);

//     Parameters:
///@param         recipientId - the json script of the dataComponent to invite

//     Returns:
///@returns         void
    void addRecipientId(char* recipientId);

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
    
// Function: GroupchatInvite.get

//     return the json script

//     Prototype:
//         void GroupchatInvite::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif