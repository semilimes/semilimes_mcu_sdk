#include "channel_message_get.h"

/* Function: ChannelMessageGet.setObj

    This endpoint returns a list of messages in the specified Channel.

    Prototype:
        void setObj(char* channelId,char* messageId,int limit);

    Parameters:
        channelId - is the unique Id to reference an existing channel
        messageId - is the unique Id to reference an existing message
        limit - sets the limit of the messages to receive

    Returns:
        void
*/
void ChannelMessageGet::setObj(char* channelId,char* messageId,int limit)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"channelId",channelId);
    json_data.addPair2JsonStr(*pjson,"messageId",messageId);
    json_data.addPair2JsonInt(*pjson,"limit",limit);
}

/* Function: ChannelMessageGet.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* ChannelMessageGet::getEPurl()
{
    return httpsUrl communication_channel_message;
}