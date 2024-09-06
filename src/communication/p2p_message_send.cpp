#include "p2p_message_send.h"

/* Function: P2pMessageSend.set

    This endpoint allows to send a data component to a Channel as a new message.

    Prototype:
        void set(char* recipientId, char* dataComponent);

    Parameters:
        recipientId - is the unique Id to reference an existing p2p chat
        dataComponent - the json description of the data component

    Returns:
        void
*/
void P2pMessageSend::set(char* recipientId, char* dataComponent)
{
    int size = headerSize+strlen(recipientId)+strlen(dataComponent)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"recipientId",recipientId);
    json_data.addPair2Json(json,"dataComponent",dataComponent);
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

/* Function: P2pMessageSend.get

    return the json script

    Prototype:
        void P2pMessageSend::get();

    Parameters:

    Returns:
        char*
*/
char* P2pMessageSend::get()
{
    return json;
}