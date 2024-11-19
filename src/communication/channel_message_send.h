#ifndef _send_channel_message_
#define _send_channel_message_

#include "../defines.h"

class ChannelMessageSend
{
private:
    SmeJson json_data;
    char* json = nullptr;

// Function: ChannelMessageSend.addOptions

//     add an list of options

//     Prototype:
//         void ChannelMessageSend::addOptions(bool silent);

//     Parameters:
///@param         silent - is a boolean to allow sending the message without any in-app notification
        
//    Returns:
///@return       void
    void addOptions(bool silent);


public:
// Function: ChannelMessageSend

// Function: ~ChannelMessageSend

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~ChannelMessageSend()

//     Parameters:

//     Returns:
///@return         void
    ~ChannelMessageSend()
    {
        delete[] json;
        json = nullptr;
    }

// Function: ChannelMessageSend.set

//     This endpoint allows to send a data component to a Channel as a new message.

//     Prototype:
//         void set(const char* channelId, const char* dataComponent, bool silent);

//     Parameters:
///@param         channelId - is the unique Id to reference an existing channel
///@param         dataComponent - the json description of the data component
///@param         silent - is a boolean to allow sending the message without any in-app notification

//     Returns:
///@returns         void
    void set(const char* channelId, const char* dataComponent, bool silent);

// Function: ChannelMessageSend.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* sme_httpsUrl + endpoint
    char* getEPurl();
    
// Function: ChannelMessageSend.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: ChannelMessageSend.get

//     return the json script

//     Prototype:
//         void ChannelMessageSend::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif