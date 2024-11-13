#ifndef _groupchat_invite_
#define _groupchat_invite_

#include "../defines.h"

class GroupchatInvite
{
private:
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
//         void set(const char* groupChatIds)

//     Parameters:
///@param         groupChatId - is the unique Id to reference an existing groupChat

//     Returns:
///@returns         void
    void set(const char* groupChatId);

// Function: GroupchatInvite.addRecipientId

//     Add the recipientId 

//     Prototype:
//         void addRecipientId(const char* recipientId);

//     Parameters:
///@param         recipientId - the json script of the dataComponent to invite

//     Returns:
///@returns         void
    void addRecipientId(const char* recipientId);

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
    
// Function: GetGroupchatMessage.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
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