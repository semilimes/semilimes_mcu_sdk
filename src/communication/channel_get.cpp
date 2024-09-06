#include "channel_get.h"

/* Function: ChannelGet.set

    This endpoint finds channels based on specified parameters

    Prototype:
        void set(char* ownerId,char* editorId,char* channelId,char* title);

    Parameters:
    ownerId - Returns channels owned by the specified account Id
    editorId - Returns channels whose editor is this account Id
    channelId - Returns the channel with this id
    title - Returns channels with this title


    Returns:
        void
*/
void ChannelGet::set(char* ownerId,char* editorId,char* channelId,char* title)
{
    int size = headerSize+strlen(ownerId)+strlen(editorId)+strlen(channelId)+strlen(title)+1;
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
        char* httpsUrl + endpoint
*/
char* ChannelGet::getEPurl()
{
    return httpsUrl communication_channel;
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