#ifndef _channel_subscribe_
#define _channel_subscribe_

#include "../defines.h"

class ChannelSubscribe
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: ChannelSubscribe

//     This endpoint makes the calling account to subscribe to an existing channel.

//     Prototype:
//         void ChannelSubscribe(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    ChannelSubscribe(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: ChannelSubscribe.setObj

//     This endpoint makes the calling account to subscribe to an existing channel.

//     Prototype:
//         void setObj(char* channelId);

//     Parameters:
///@param          channelId - is the unique Id to reference an existing channel

//     Returns:
///@returns         void
    void setObj(char* channelId);

// Function: ChannelSubscribe.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif