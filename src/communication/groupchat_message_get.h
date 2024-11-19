#ifndef _groupchat_message_get_
#define _groupchat_message_get_

#include "../defines.h"

class GroupchatMessageGet
{
private:
    SmeJson json_data;
    char* json = nullptr;
    
public:
// Function: ~GroupchatMessageGet

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GroupchatMessageGet()

//     Parameters:

//     Returns:
///@return         void
    ~GroupchatMessageGet()
    {
        delete[] json;
        json = nullptr;
    }

// Function: GroupchatMessageGet.set

//     This endpoint returns a list of messages in the specified Group chat.

//     Prototype:
//         void set(const char* groupChatId,const char* messageId,int limit);

//     Parameters:
///@param         groupChatId - is the unique Id to reference an existing groupChat
///@param         messageId - is the unique Id to reference an existing groupChat
///@param         limit - sets the limit of the messages to receive

//     Returns:
///@returns         void
    void set(const char* groupChatId,const char* messageId,int limit);

// Function: GroupchatMessageGet.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* sme_httpsUrl + endpoint
    char* getEPurl();
    
// Function: GroupchatMessageGet.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: GroupchatMessageGet.get

//     return the json script

//     Prototype:
//         void GroupchatMessageGet::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif