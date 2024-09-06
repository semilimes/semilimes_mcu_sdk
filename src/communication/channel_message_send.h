#ifndef _send_channel_message_
#define _send_channel_message_

#include "../defines.h"

class ChannelMessageSend
{
private:
    #define headerSize 33
    SmeJson json_data;
    char* json = nullptr;

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
//         void set(char* messageId, char* dataComponent);

//     Parameters:
///@param         channelId - is the unique Id to reference an existing channel
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void set(char* channelId, char* dataComponent);

// Function: ChannelMessageSend.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
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