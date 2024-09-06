#include "p2p_message_reply.h"

/* Function: P2pMessageReply.set

    This endpoint allows the account to reply to a specific message with a simple text.

    Prototype:
        void set(char* messageId, char* dataComponent);

    Parameters:
        messageId - is the unique Id to reference an existing p2p chat
        dataComponent - the json description of the data component

    Returns:
        void
*/
void P2pMessageReply::set(char* messageId, char* dataComponent)
{
    int size = headerSize+strlen(messageId)+strlen(dataComponent)+1;
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
        char* httpsUrl + endpoint
*/
char* P2pMessageReply::getEPurl()
{
    return httpsUrl communication_p2p_message_reply;
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