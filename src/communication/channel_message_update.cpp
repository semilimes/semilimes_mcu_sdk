#include "channel_message_update.h"

/* Function: ChannelMessageUpdate.setObj

    This endpoint allows to update a specific message published in a channel.

    Prototype:
        void setObj(char* messageId, char* dataComponent);

    Parameters:
        messageId - is the unique Id to reference an existing groupChat
        dataComponent - the json description of the data component

    Returns:
        void
*/
void ChannelMessageUpdate::setObj(char* messageId, char* dataComponent)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"messageId",messageId);
    json_data.addPair2Json(*pjson,"dataComponent",dataComponent);
}

/* Function: ChannelMessageUpdate.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* ChannelMessageUpdate::getEPurl()
{
    return httpsUrl communication_channel_update;
}