#include "p2p_message_update.h"

/* Function: P2pMessageUpdate.setObj

    This endpoint allows to update a specific message published in a p2p chat.

    Prototype:
        void setObj(char* messageId, char* dataComponent);

    Parameters:
        messageId - is the unique Id to reference an existing p2p chat
        dataComponent - the json description of the data component

    Returns:
        void
*/
void P2pMessageUpdate::setObj(char* messageId, char* dataComponent)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"messageId",messageId);
    json_data.addPair2Json(*pjson,"dataComponent",dataComponent);
}

/* Function: P2pMessageUpdate.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* P2pMessageUpdate::getEPurl()
{
    return httpsUrl communication_p2p_message_update;
}