#ifndef _channels_message_get_
#define _channels_message_get_

#include "../defines.h"

class ChannelMessageGet
{
private:
    #define headerSize 40
    SmeJson json_data;
    char* json = nullptr;
    
public:

// Function: ~ChannelMessageGet

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~ChannelMessageGet()

//     Parameters:

//     Returns:
///@return         void
    ~ChannelMessageGet()
    {
        delete[] json;
        json = nullptr;
    }

// Function: ChannelMessageGet.set

//     This endpoint returns a list of messages in the specified Channel.

//     Prototype:
//         void set(char* channelId,char* messageId,int limit);

//     Parameters:
///@param         channelId - is the unique Id to reference an existing channel
///@param         messageId - is the unique Id to reference an existing message
///@param         limit - sets the limit of the messages to receive

//     Returns:
///@returns         void
    void set(char* channelId,char* messageId,int limit);

// Function: ChannelMessageGet.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: ChannelMessageGet.get

//     return the json script

//     Prototype:
//         void ChannelMessageGet::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif