#ifndef _groupchat_reaction_send_
#define _groupchat_reaction_send_

#include "../defines.h"

class GroupchatReactionSend
{
private:
    SmeJson json_data;
    char* json = nullptr;

public:
// Function: ~GroupchatReactionSend

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GroupchatReactionSend()

//     Parameters:

//     Returns:
///@return         void
    ~GroupchatReactionSend()
    {
        delete[] json;
        json = nullptr;
    }

// Function: GroupchatReactionSend.set

//     This endpoint allows the account to add a reaction from a specific message in a Group Chat.

//     Prototype:
//         void set(const char* messageId, const char* reaction);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing groupChat
///@param         reaction - 

//     Returns:
///@returns         void
    void set(const char* messageId, const char* reaction);

// Function: GroupchatReactionSend.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* sme_httpsUrl + endpoint
    char* getEPurl();
    
// Function: GroupchatReactionSend.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: GroupchatReactionSend.get

//     return the json script

//     Prototype:
//         void GroupchatReactionSend::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif