#include "p2p_reaction_remove.h"

/* Function: P2pReactionRemove.set

    This endpoint allows the account to remove a reaction from a specific message in a p2p Chat.

    Prototype:
        void set(const char* messageId, const char* reaction);

    Parameters:
        messageId - is the unique Id to reference an existing p2p chat
        reaction - 

    Returns:
        void
*/
void P2pReactionRemove::set(const char* messageId, const char* reaction)
{
    int size = strlen("{\"messageId\":\"\",\"reaction\":\"\"}")+strlen(messageId)+strlen(reaction)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2JsonStr(json,"reaction",reaction);
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

/* Function: P2pReactionRemove.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* P2pReactionRemove::getWSEPurl()
{
    return communication_p2p_message_reaction_remove;        
}

/* Function: P2pReactionRemove.get

    return the json script

    Prototype:
        void P2pReactionRemove::get();

    Parameters:

    Returns:
        char*
*/
char* P2pReactionRemove::get()
{
    return json;
}