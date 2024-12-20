#include "channel_get.h"

/* Function: ChannelGet.set

    This endpoint finds channels based on specified parameters

    Prototype:
        void set(const char* ownerId,const char* editorId,const char* channelId,const char* title);

    Parameters:
    ownerId - Returns channels owned by the specified account Id
    editorId - Returns channels whose editor is this account Id
    channelId - Returns the channel with this id
    title - Returns channels with this title


    Returns:
        void
*/
void ChannelGet::set(const char* ownerId,const char* editorId,const char* channelId,const char* title)
{
    int size = strlen("{\"ownerId\":\"\",\"editorId\":\"\",\"channelId\":\"\",\"title\":\"\"}")+strlen(ownerId)+strlen(editorId)+strlen(channelId)+strlen(title)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"ownerId",ownerId);
    json_data.addPair2JsonStr(json,"editorId",editorId);
    json_data.addPair2JsonStr(json,"channelId",channelId);
    json_data.addPair2JsonStr(json,"title",title);
}

/* Function: ChannelGet.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* sme_httpsUrl + endpoint
*/
char* ChannelGet::getEPurl()
{
    return sme_httpsUrl sme_communication_channel;
}

/* Function: ChannelGet.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* ChannelGet::getWSEPurl()
{
    return sme_communication_channel;        
}

/* Function: ChannelGet.get

    return the json script

    Prototype:
        void ChannelGet::get();

    Parameters:

    Returns:
        char*
*/
char* ChannelGet::get()
{
    return json;
}