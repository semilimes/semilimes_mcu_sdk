#include "p2p_message_send.h"

/* Function: P2pMessageSend.setObj

    This endpoint allows to send a data component to a Channel as a new message.

    Prototype:
        void setObj(char* recipientId, char* dataComponent);

    Parameters:
        recipientId - is the unique Id to reference an existing p2p chat
        dataComponent - the json description of the data component

    Returns:
        void
*/
void P2pMessageSend::setObj(char* recipientId, char* dataComponent)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"recipientId",recipientId);
    json_data.addPair2Json(*pjson,"dataComponent",dataComponent);
}

/* Function: P2pMessageSend.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* P2pMessageSend::getEPurl()
{
    return httpsUrl communication_p2p_message_send;
}