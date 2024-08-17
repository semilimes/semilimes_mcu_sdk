#include "channel_unsubscribe.h"

/* Function: ChannelUnsubscribe.setObj

    This endpoint makes the calling account to unsubscribe from an existing channel.

    Prototype:
        void setObj(char* channelId);

    Parameters:
        channelId - is the unique Id to reference an existing channel

    Returns:
        void
*/
void ChannelUnsubscribe::setObj(char* channelId)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"channelId",channelId);
}

/* Function: ChannelUnsubscribe.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* ChannelUnsubscribe::getEPurl()
{
    return httpsUrl communication_channel_unsubscribe;
}