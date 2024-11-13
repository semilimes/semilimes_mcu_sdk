#include "channel_message_get.h"

/* Function: ChannelMessageGet.set

    This endpoint returns a list of messages in the specified Channel.

    Prototype:
        void set(const char* channelId,const char* messageId,int limit);

    Parameters:
        channelId - is the unique Id to reference an existing channel
        messageId - is the unique Id to reference an existing message
        limit - sets the limit of the messages to receive

    Returns:
        void
*/
void ChannelMessageGet::set(const char* channelId,const char* messageId,int limit)
{
    int size = strlen("{\"channelId\":\"\",\"messageId\":\"\",\"limit\":}")+strlen(channelId)+strlen(messageId)+json_data.intStrSize(limit)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"channelId",channelId);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2JsonInt(json,"limit",limit);
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

/* Function: ChannelMessageGet.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* ChannelMessageGet::getWSEPurl()
{
    return communication_channel_message;        
}

/* Function: ChannelMessageGet.get

    return the json script

    Prototype:
        void ChannelMessageGet::get();

    Parameters:

    Returns:
        char*
*/
char* ChannelMessageGet::get()
{
    return json;
}