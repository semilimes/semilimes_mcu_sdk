#include "p2p_message_get.h"

/* Function: P2pMessageGet.setObj

    This endpoint returns a list of messages in the specified P2P chat

    Prototype:
        void setObj(bool owner,bool editor,bool subscriber);

    Parameters:
        recipientId - Filters the p2p chats list by showing only the one occurring with the specified account id.
        messageId - is the unique Id to reference an existing p2p chat
        limit - sets the limit of the messages to receive

    Returns:
        void
*/
void P2pMessageGet::setObj(char* recipientId,char* messageId,int limit)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"recipientId",recipientId);
    json_data.addPair2JsonStr(*pjson,"messageId",messageId);
    json_data.addPair2JsonInt(*pjson,"limit",limit);
}

/* Function: P2pMessageGet.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* P2pMessageGet::getEPurl()
{
    return httpsUrl communication_p2p_message;
}