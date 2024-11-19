#ifndef _groupchat_message_send_
#define _groupchat_message_send_

#include "../defines.h"

class GroupchatMessageSend
{
private:
    SmeJson json_data;
    char* json = nullptr;

// Function: GroupchatMessageSend.addOptions

//     add an list of options

//     Prototype:
//         void GroupchatMessageSend::addOptions(bool silent);

//     Parameters:
///@param         silent - is a boolean to allow sending the message without any in-app notification
        
//    Returns:
///@return       void
    void addOptions(bool silent);

public:
// Function: ~GroupchatMessageSend

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GroupchatMessageSend()

//     Parameters:

//     Returns:
///@return         void
    ~GroupchatMessageSend()
    {
        delete[] json;
        json = nullptr;
    }

// Function: GroupchatMessageSend.set

//     This endpoint allows to send a data component to a groupChat as a new message.

//     Prototype:
//         void set(const char* groupChatId, const char* dataComponent, bool silent);

//     Parameters:
///@param         groupChatId - is the unique Id to reference an existing groupChat
///@param         dataComponent - the json description of the data component
///@param         silent - is a boolean to allow sending the message without any in-app notification

//     Returns:
///@returns         void
    void set(const char* groupChatId, const char* dataComponent, bool silent);

// Function: GroupchatMessageSend.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* sme_httpsUrl + endpoint
    char* getEPurl();
    
// Function: GroupchatMessageSend.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: GroupchatMessageSend.get

//     return the json script

//     Prototype:
//         void GroupchatMessageSend::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif