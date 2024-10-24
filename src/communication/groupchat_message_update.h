#ifndef _groupchat_message_update_
#define _groupchat_message_update_

#include "../defines.h"

class GroupchatMessageUpdate
{
private:
    #define headerSize 33
    #define optionsHeaderSize 11
    SmeJson json_data;
    char* json = nullptr;

// Function: P2pMessageSend.addOptions

//     add an list of options

//     Prototype:
//         void P2pMessageSend::addOptions(bool silent);

//     Parameters:
///@param         silent - is a boolean to allow sending the message without any in-app notification
        
//    Returns:
///@return       void
    void addOptions(bool silent);

public:
// Function: ~GroupchatMessageUpdate

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GroupchatMessageUpdate()

//     Parameters:

//     Returns:
///@return         void
    ~GroupchatMessageUpdate()
    {
        delete[] json;
        json = nullptr;
    }

// Function: GroupchatMessageUpdate.set

//     This endpoint allows to update a specific message published in a group Chat

//     Prototype:
//         void set(char* messageId, char* dataComponent);

//     Parameters:
///@param         channelId - is the unique Id to reference an existing channel
///@param         dataComponent - the json description of the data component
///@param         silent - is a boolean to allow sending the message without any in-app notification

//     Returns:
///@returns         void
    void set(char* recipientId, char* dataComponent, bool silent);

// Function: GroupchatMessageUpdate.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: GroupchatMessageUpdate.get

//     return the json script

//     Prototype:
//         void GroupchatMessageUpdate::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif