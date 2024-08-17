#ifndef _send_channel_message_
#define _send_channel_message_

#include "../defines.h"

class ChannelMessageSend
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: ChannelMessageSend

//     This endpoint allows to send a data component to a Channel as a new message.

//     Prototype:
//         void ChannelMessageSend(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    ChannelMessageSend(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: ChannelMessageSend.setObj

//     This endpoint allows to send a data component to a Channel as a new message.

//     Prototype:
//         void setObj(char* messageId, char* dataComponent);

//     Parameters:
///@param         channelId - is the unique Id to reference an existing channel
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void setObj(char* channelId, char* dataComponent);

// Function: ChannelMessageSend.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif