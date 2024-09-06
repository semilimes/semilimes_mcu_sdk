#include "channel_message_send.h"

/* Function: ChannelMessageSend.set

    This endpoint allows to send a data component to a Channel as a new message.

    Prototype:
        void set(char* messageId, char* dataComponent);

    Parameters:
        channelId - is the unique Id to reference an existing channel
        dataComponent - the json description of the data component

    Returns:
        void
*/
void ChannelMessageSend::set(char* channelId, char* dataComponent)
{
    int size = headerSize+strlen(channelId)+strlen(dataComponent)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"channelId",channelId);
    json_data.addPair2Json(json,"dataComponent",dataComponent);
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

/* Function: ChannelMessageSend.get

    return the json script

    Prototype:
        void ChannelMessageSend::get();

    Parameters:

    Returns:
        char*
*/
char* ChannelMessageSend::get()
{
    return json;
}