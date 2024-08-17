#include "channel_subscribe.h"

/* Function: ChannelSubscribe.setObj

    This endpoint makes the calling account to subscribe to an existing channel.

    Prototype:
        void setObj(char* channelId);

    Parameters:
        channelId - is the unique Id to reference an existing channel

    Returns:
        void
*/
void ChannelSubscribe::setObj(char* channelId)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"channelId",channelId);
}

/* Function: ChannelSubscribe.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* ChannelSubscribe::getEPurl()
{
    return httpsUrl communication_channel_subscribe;
}