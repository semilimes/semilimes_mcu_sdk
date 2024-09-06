#include "p2p_message_get.h"

/* Function: P2pMessageGet.set

    This endpoint returns a list of messages in the specified P2P chat

    Prototype:
        void set(bool owner,bool editor,bool subscriber);

    Parameters:
        recipientId - Filters the p2p chats list by showing only the one occurring with the specified account id.
        messageId - is the unique Id to reference an existing p2p chat
        limit - sets the limit of the messages to receive

    Returns:
        void
*/
void P2pMessageGet::set(char* recipientId,char* messageId,int limit)
{
    int size = headerSize+strlen(recipientId)+strlen(messageId)+json_data.intStrSize(limit)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"recipientId",recipientId);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2JsonInt(json,"limit",limit);
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

/* Function: P2pMessageGet.get

    return the json script

    Prototype:
        void P2pMessageGet::get();

    Parameters:

    Returns:
        char*
*/
char* P2pMessageGet::get()
{
    return json;
}