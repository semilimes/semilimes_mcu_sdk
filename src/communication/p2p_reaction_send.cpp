#include "p2p_reaction_send.h"

/* Function: P2pReactionSend.set

    This endpoint allows the account to remove a reaction from a specific message in a p2p Chat.

    Prototype:
        void set(char* messageId, char* reaction);

    Parameters:
        messageId - is the unique Id to reference an existing p2p Chat
        reaction - 

    Returns:
        void
*/
void P2pReactionSend::set(char* messageId, char* reaction)
{
    int size = headerSize+strlen(messageId)+strlen(reaction)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2JsonStr(json,"reaction",reaction);
}

/* Function: P2pReactionSend.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* P2pReactionSend::getEPurl()
{
    return httpsUrl communication_p2p_message_reaction_send;
}

/* Function: P2pReactionSend.get

    return the json script

    Prototype:
        void P2pReactionSend::get();

    Parameters:

    Returns:
        char*
*/
char* P2pReactionSend::get()
{
    return json;
}