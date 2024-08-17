#include "p2p_message_reply.h"

/* Function: P2pMessageReply.setObj

    This endpoint allows the account to reply to a specific message with a simple text.

    Prototype:
        void setObj(char* messageId, char* dataComponent);

    Parameters:
        messageId - is the unique Id to reference an existing p2p chat
        dataComponent - the json description of the data component

    Returns:
        void
*/
void P2pMessageReply::setObj(char* messageId, char* dataComponent)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"messageId",messageId);
    json_data.addPair2Json(*pjson,"dataComponent",dataComponent);
}

/* Function: P2pMessageReply.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* P2pMessageReply::getEPurl()
{
    return httpsUrl communication_p2p_message_reply;
}