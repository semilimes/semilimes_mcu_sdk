#ifndef _channels_message_get_
#define _channels_message_get_

#include "../defines.h"

class ChannelMessageGet
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: ChannelMessageGet

//     This endpoint returns a list of messages in the specified Channel.

//     Prototype:
//         void ChannelMessageGet(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    ChannelMessageGet(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: ChannelMessageGet.setObj

//     This endpoint returns a list of messages in the specified Channel.

//     Prototype:
//         void setObj(char* channelId,char* messageId,int limit);

//     Parameters:
///@param         channelId - is the unique Id to reference an existing channel
///@param         messageId - is the unique Id to reference an existing message
///@param         limit - sets the limit of the messages to receive

//     Returns:
///@returns         void
    void setObj(char* channelId,char* messageId,int limit);

// Function: ChannelMessageGet.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif