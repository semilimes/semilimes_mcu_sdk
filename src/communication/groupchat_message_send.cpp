#include "groupchat_message_send.h"

/* Function: GroupchatMessageSend.set

    This endpoint allows to send a data component to a groupChat as a new message.

    Prototype:
        void set(char* groupChatId, char* dataComponent);

    Parameters:
        groupChatId - is the unique Id to reference an existing groupChat
        dataComponent - the json description of the data component

    Returns:
        void
*/
void GroupchatMessageSend::set(char* groupChatId, char* dataComponent)
{
    int size = headerSize+strlen(groupChatId)+strlen(dataComponent)+1;
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"groupChatId",groupChatId);
    json_data.addPair2Json(json,"dataComponent",dataComponent);
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

/* Function: GroupchatMessageSend.get

    return the json script

    Prototype:
        void GroupchatMessageSend::get();

    Parameters:

    Returns:
        char*
*/
char* GroupchatMessageSend::get()
{
    return json;
}

