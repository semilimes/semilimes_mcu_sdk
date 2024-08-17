#include "groupchat_message_update.h"

/* Function: GroupchatMessageUpdate.setObj

    This endpoint allows to update a specific message published in a group Chat

    Prototype:
        void setObj(char* messageId, char* dataComponent);

    Parameters:
        channelId - is the unique Id to reference an existing channel
        dataComponent - the json description of the data component

    Returns:
        void
*/
void GroupchatMessageUpdate::setObj(char* messageId, char* dataComponent)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"messageId",messageId);
    json_data.addPair2Json(*pjson,"dataComponent",dataComponent);
}

/* Function: GroupchatMessageUpdate.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* GroupchatMessageUpdate::getEPurl()
{
    return httpsUrl communication_groupchat_message_update;
}