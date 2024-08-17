#include "channel_get.h"

/* Function: ChannelGet.setObj

    This endpoint finds channels based on specified parameters

    Prototype:
        void setObj(char* ownerId,char* editorId,char* channelId,char* title);

    Parameters:
    ownerId - Returns channels owned by the specified account Id
    editorId - Returns channels whose editor is this account Id
    channelId - Returns the channel with this id
    title - Returns channels with this title


    Returns:
        void
*/
void ChannelGet::setObj(char* ownerId,char* editorId,char* channelId,char* title)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"ownerId",ownerId);
    json_data.addPair2JsonStr(*pjson,"editorId",editorId);
    json_data.addPair2JsonStr(*pjson,"channelId",channelId);
    json_data.addPair2JsonStr(*pjson,"title",title);
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