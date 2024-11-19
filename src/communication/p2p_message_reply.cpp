#include "p2p_message_reply.h"

/* Function: P2pMessageReply.set

    This endpoint allows the account to reply to a specific message with a simple text.

    Prototype:
        void set(const char* messageId, const char* dataComponent);

    Parameters:
        messageId - is the unique Id to reference an existing p2p chat
        dataComponent - the json description of the data component

    Returns:
        void
*/
void P2pMessageReply::set(const char* messageId, const char* dataComponent)
{
    int size = strlen("{\"messageId\":\"\",\"dataComponent\":}")+strlen(messageId)+strlen(dataComponent)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2Json(json,"dataComponent",dataComponent);
}

/* Function: P2pMessageReply.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* sme_httpsUrl + endpoint
*/
char* P2pMessageReply::getEPurl()
{
    return sme_httpsUrl sme_communication_p2p_message_reply;
}

/* Function: P2pMessageReply.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* P2pMessageReply::getWSEPurl()
{
    return sme_communication_p2p_message_reply;        
}

/* Function: P2pMessageReply.get

    return the json script

    Prototype:
        void P2pMessageReply::get();

    Parameters:

    Returns:
        char*
*/
char* P2pMessageReply::get()
{
    return json;
}