#ifndef _groupchat_signal_typing_
#define _groupchat_signal_typing_

#include "../defines.h"

class GroupchatSignalTyping
{
private:
    SmeJson json_data;
    char* json = nullptr;
    
public:

// Function: ~GroupchatSignalTyping

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GroupchatSignalTyping()

//     Parameters:

//     Returns:
///@return         void
    ~GroupchatSignalTyping()
    {
        delete[] json;
        json = nullptr;
    }

// Function: GroupchatSignalTyping.set

//    This endpoint allows the calling user to let all group chat members know in advance that the user is going to publish a new message. 
//    This is particularly useful when having automated bots which need some time to elaborate the message to be sent.

//     Prototype:
//         void set(const char* groupChatId);

//     Parameters:
///@param         groupChatId -  is the unique Id to reference an existing groupChat

//     Returns:
///@returns         void
    void set(const char* groupChatId);

// Function: GroupchatSignalTyping.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* sme_httpsUrl + endpoint
    char* getEPurl();
    
// Function: GroupchatSignalTyping.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();

// Function: GroupchatSignalTyping.get

//     return the json script

//     Prototype:
//         void GroupchatSignalTyping::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif