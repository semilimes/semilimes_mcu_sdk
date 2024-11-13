#ifndef _groupchat_message_reply_
#define _groupchat_message_reply_

#include "../defines.h"

class GroupchatMessageReply
{
private:
    SmeJson json_data;
    char* json = nullptr;

public:
// Function: ~GroupchatMessageReply

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GroupchatMessageReply()

//     Parameters:

//     Returns:
///@return         void
    ~GroupchatMessageReply()
    {
        delete[] json;
        json = nullptr;
    }

// Function: GroupchatMessageReply.set

//     This endpoint allows the account to reply to a specific message with a simple text.

//     Prototype:
//         void set(const char* messageId, const char* dataComponent);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing groupChat
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void set(const char* messageId, const char* dataComponent);

// Function: GroupchatMessageReply.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: GroupchatMessageReply.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: GroupchatMessageReply.get

//     return the json script

//     Prototype:
//         void GroupchatMessageReply::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif