#include "channel_subscribe.h"

/* Function: ChannelSubscribe.set

    This endpoint makes the calling account to subscribe to an existing channel.

    Prototype:
        void set(const char* channelId);

    Parameters:
        channelId - is the unique Id to reference an existing channel

    Returns:
        void
*/
void ChannelSubscribe::set(const char* channelId)
{
    int size = strlen("{\"channelId\":\"\"}")+strlen(channelId)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"channelId",channelId);
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

/* Function: ChannelSubscribe.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* ChannelSubscribe::getWSEPurl()
{
    return communication_channel_subscribe;        
}

/* Function: ChannelSubscribe.get

    return the json script

    Prototype:
        void ChannelSubscribe::get();

    Parameters:

    Returns:
        char*
*/
char* ChannelSubscribe::get()
{
    return json;
}