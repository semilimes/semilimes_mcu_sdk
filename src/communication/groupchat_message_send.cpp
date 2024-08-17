#include "groupchat_message_send.h"

/* Function: GroupchatMessageSend.setObj

    This endpoint allows to send a data component to a groupChat as a new message.

    Prototype:
        void setObj(char* groupChatId, char* dataComponent);

    Parameters:
        groupChatId - is the unique Id to reference an existing groupChat
        dataComponent - the json description of the data component

    Returns:
        void
*/
void GroupchatMessageSend::setObj(char* groupChatId, char* dataComponent)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"groupChatId",groupChatId);
    json_data.addPair2Json(*pjson,"dataComponent",dataComponent);
}

/* Function: GroupchatMessageSend.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* GroupchatMessageSend::getEPurl()
{
    return httpsUrl communication_groupchat_message_send;
}