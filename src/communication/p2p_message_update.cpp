#include "p2p_message_update.h"

/* Function: P2pMessageUpdate.set

    This endpoint allows to update a specific message published in a p2p chat.

    Prototype:
        void set(char* messageId, char* dataComponent);

    Parameters:
        messageId - is the unique Id to reference an existing p2p chat
        dataComponent - the json description of the data component

    Returns:
        void
*/
void P2pMessageUpdate::set(char* messageId, char* dataComponent)
{
    int size = headerSize+strlen(messageId)+strlen(dataComponent)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2Json(json,"dataComponent",dataComponent);
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

/* Function: P2pMessageUpdate.get

    return the json script

    Prototype:
        void P2pMessageUpdate::get();

    Parameters:

    Returns:
        char*
*/
char* P2pMessageUpdate::get()
{
    return json;
}