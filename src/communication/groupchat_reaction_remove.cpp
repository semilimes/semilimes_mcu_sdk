#include "groupchat_reaction_remove.h"

/* Function: GroupchatReactionRemove.setObj

    This endpoint allows the account to remove a reaction from a specific message in a Group Chat.

    Prototype:
        void setObj(char* messageId, char* reaction);

    Parameters:
        messageId - is the unique Id to reference an existing groupChat
        reaction - 

    Returns:
        void
*/
void GroupchatReactionRemove::setObj(char* messageId, char* reaction)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"messageId",messageId);
    json_data.addPair2Json(*pjson,"reaction",reaction);
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