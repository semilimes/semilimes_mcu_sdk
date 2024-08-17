#include "groupchat_message_get.h"

/* Function: GroupchatMessageGet.setObj

    This endpoint returns a list of messages in the specified Group chat.

    Prototype:
        void setObj(char* groupChatId,char* messageId,int limit);

    Parameters:
        groupChatId - is the unique Id to reference an existing groupChat
        messageId - is the unique Id to reference an existing groupChat
        limit - sets the limit of the messages to receive

    Returns:
        void
*/
void GroupchatMessageGet::setObj(char* groupChatId,char* messageId,int limit)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"groupChatId",groupChatId);
    json_data.addPair2JsonStr(*pjson,"messageId",messageId);
    json_data.addPair2JsonInt(*pjson,"limit",limit);
}

/* Function: GroupchatMessageGet.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* GroupchatMessageGet::getEPurl()
{
    return httpsUrl communication_groupchat_message;
}