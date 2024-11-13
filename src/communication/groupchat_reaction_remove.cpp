#include "groupchat_reaction_remove.h"

/* Function: GroupchatReactionRemove.set

    This endpoint allows the account to remove a reaction from a specific message in a Group Chat.

    Prototype:
        void set(const char* messageId, const char* reaction);

    Parameters:
        messageId - is the unique Id to reference an existing groupChat
        reaction - 

    Returns:
        void
*/
void GroupchatReactionRemove::set(const char* messageId, const char* reaction)
{
    int size = strlen("{\"messageId\":\"\",\"reaction\":\"\"}")+strlen(messageId)+strlen(reaction)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2JsonStr(json,"reaction",reaction);
}

/* Function: GroupchatReactionRemove.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* GroupchatReactionRemove::getEPurl()
{
    return httpsUrl communication_groupchat_message_reaction_remove;
}

/* Function: GroupchatReactionRemove.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* GroupchatReactionRemove::getWSEPurl()
{
    return communication_groupchat_message_reaction_remove;        
}

/* Function: GroupchatReactionRemove.get

    return the json script

    Prototype:
        void GroupchatReactionRemove::get();

    Parameters:

    Returns:
        char*
*/
char* GroupchatReactionRemove::get()
{
    return json;
}