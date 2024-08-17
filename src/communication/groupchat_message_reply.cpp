#include "groupchat_message_reply.h"

/* Function: GroupchatMessageReply.setObj

    This endpoint allows the account to reply to a specific message with a simple text.

    Prototype:
        void setObj(char* messageId, char* dataComponent);

    Parameters:
        messageId - is the unique Id to reference an existing groupChat
        dataComponent - the json description of the data component

    Returns:
        void
*/
void GroupchatMessageReply::setObj(char* messageId, char* dataComponent)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"messageId",messageId);
    json_data.addPair2Json(*pjson,"dataComponent",dataComponent);
}

/* Function: GroupchatMessageReply.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* GroupchatMessageReply::getEPurl()
{
    return httpsUrl communication_groupchat_message_reply;
}