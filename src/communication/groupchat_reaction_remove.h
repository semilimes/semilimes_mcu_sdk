#ifndef _groupchat_reaction_remove_
#define _groupchat_reaction_remove_

#include "../defines.h"

class GroupchatReactionRemove
{
private:
    SmeJson json_data;
    char* json = nullptr;

public:
// Function: ~GroupchatReactionRemove

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GroupchatReactionRemove()

//     Parameters:

//     Returns:
///@return         void
    ~GroupchatReactionRemove()
    {
        delete[] json;
        json = nullptr;
    }

// Function: GroupchatReactionRemove.set

//     This endpoint allows the account to remove a reaction from a specific message in a Group Chat.

//     Prototype:
//         void set(const char* messageId, const char* reaction);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing groupChat
///@param         reaction - 

//     Returns:
///@returns         void
    void set(const char* messageId, const char* reaction);

// Function: GroupchatReactionRemove.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* sme_httpsUrl + endpoint
    char* getEPurl();
    
// Function: GroupchatReactionRemove.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: GroupchatReactionRemove.get

//     return the json script

//     Prototype:
//         void GroupchatReactionRemove::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif