#include "p2p_reaction_remove.h"

/* Function: P2pReactionRemove.setObj

    This endpoint allows the account to remove a reaction from a specific message in a p2p Chat.

    Prototype:
        void setObj(char* messageId, char* reaction);

    Parameters:
        messageId - is the unique Id to reference an existing p2p chat
        reaction - 

    Returns:
        void
*/
void P2pReactionRemove::setObj(char* messageId, char* reaction)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"messageId",messageId);
    json_data.addPair2Json(*pjson,"reaction",reaction);
}

/* Function: P2pReactionRemove.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* P2pReactionRemove::getEPurl()
{
    return httpsUrl communication_p2p_message_reaction_remove;
}