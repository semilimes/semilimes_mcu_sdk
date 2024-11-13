#include "channel_unsubscribe.h"

/* Function: ChannelUnsubscribe.set

    This endpoint makes the calling account to unsubscribe from an existing channel.

    Prototype:
        void set(const char* channelId);

    Parameters:
        channelId - is the unique Id to reference an existing channel

    Returns:
        void
*/
void ChannelUnsubscribe::set(const char* channelId)
{
    int size = strlen("{\"channelId\":\"\"}")+strlen(channelId)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"channelId",channelId);
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

/* Function: ChannelUnsubscribe.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* ChannelUnsubscribe::getWSEPurl()
{
    return communication_channel_unsubscribe;        
}

/* Function: ChannelUnsubscribe.get

    return the json script

    Prototype:
        void ChannelUnsubscribe::get();

    Parameters:

    Returns:
        char*
*/
char* ChannelUnsubscribe::get()
{
    return json;
}