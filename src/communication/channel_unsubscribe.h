#ifndef _channel_unsubscribe_
#define _channel_unsubscribe_

#include "../defines.h"

class ChannelUnsubscribe
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: ChannelUnsubscribe

//     This endpoint makes the calling account to unsubscribe from an existing channel.

//     Prototype:
//         void ChannelUnsubscribe(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    ChannelUnsubscribe(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: ChannelUnsubscribe.setObj

//     This endpoint makes the calling account to unsubscribe from an existing channel.

//     Prototype:
//         void setObj(char* channelId);

//     Parameters:
///@param          channelId - is the unique Id to reference an existing channel

//     Returns:
///@returns         void
    void setObj(char* channelId);

// Function: ChannelUnsubscribe.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif