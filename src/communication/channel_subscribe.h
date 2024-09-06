#ifndef _channel_subscribe_
#define _channel_subscribe_

#include "../defines.h"

class ChannelSubscribe
{
private:
    #define headerSize 16
    SmeJson json_data;
    char* json = nullptr;
    
public:

// Function: ~ChannelSubscribe

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~ChannelSubscribe()

//     Parameters:

//     Returns:
///@return         void
    ~ChannelSubscribe()
    {
        delete[] json;
        json = nullptr;
    }

// Function: ChannelSubscribe.set

//     This endpoint makes the calling account to subscribe to an existing channel.

//     Prototype:
//         void set(char* channelId);

//     Parameters:
///@param          channelId - is the unique Id to reference an existing channel

//     Returns:
///@returns         void
    void set(char* channelId);

// Function: ChannelSubscribe.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: ChannelSubscribe.get

//     return the json script

//     Prototype:
//         void ChannelSubscribe::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif