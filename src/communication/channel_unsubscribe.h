#ifndef _channel_unsubscribe_
#define _channel_unsubscribe_

#include "../defines.h"

class ChannelUnsubscribe
{
private:
    SmeJson json_data;
    char* json = nullptr;
    
public:

// Function: ~ChannelUnsubscribe

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~ChannelUnsubscribe()

//     Parameters:

//     Returns:
///@return         void
    ~ChannelUnsubscribe()
    {
        delete[] json;
        json = nullptr;
    }

// Function: ChannelUnsubscribe.set

//     This endpoint makes the calling account to unsubscribe from an existing channel.

//     Prototype:
//         void set(const char* channelId);

//     Parameters:
///@param          channelId - is the unique Id to reference an existing channel

//     Returns:
///@returns         void
    void set(const char* channelId);

// Function: ChannelUnsubscribe.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: ChannelUnsubscribe.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: ChannelUnsubscribe.get

//     return the json script

//     Prototype:
//         void ChannelUnsubscribe::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif