#include "groupchat_reaction_send.h"

/* Function: GroupchatReactionSend.set

    This endpoint allows the account to add a reaction from a specific message in a Group Chat.

    Prototype:
        void set(char* messageId, char* reaction);

    Parameters:
        messageId - is the unique Id to reference an existing groupChat
        reaction - 

    Returns:
        void
*/
void GroupchatReactionSend::set(char* messageId, char* reaction)
{
    int size = headerSize+strlen(messageId)+strlen(reaction)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2JsonStr(json,"reaction",reaction);
}

/* Function: GroupchatReactionSend.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* GroupchatReactionSend::getEPurl()
{
    return httpsUrl communication_groupchat_message_reaction_send;
}

/* Function: GroupchatReactionSend.get

    return the json script

    Prototype:
        void GroupchatReactionSend::get();

    Parameters:

    Returns:
        char*
*/
char* GroupchatReactionSend::get()
{
    return json;
}