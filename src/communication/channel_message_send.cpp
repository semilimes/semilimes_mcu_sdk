#include "channel_message_send.h"

/* Function: ChannelMessageSend.setObj

    This endpoint allows to send a data component to a Channel as a new message.

    Prototype:
        void setObj(char* messageId, char* dataComponent);

    Parameters:
        channelId - is the unique Id to reference an existing channel
        dataComponent - the json description of the data component

    Returns:
        void
*/
void ChannelMessageSend::setObj(char* channelId, char* dataComponent)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"channelId",channelId);
    json_data.addPair2Json(*pjson,"dataComponent",dataComponent);
}

/* Function: ChannelMessageSend.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* ChannelMessageSend::getEPurl()
{
    return httpsUrl communication_channel_message_send;
}