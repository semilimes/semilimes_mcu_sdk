#include "groupchat_message_reply.h"

/* Function: GroupchatMessageReply.set

    This endpoint allows the account to reply to a specific message with a simple text.

    Prototype:
        void set(const char* messageId, const char* dataComponent);

    Parameters:
        messageId - is the unique Id to reference an existing groupChat
        dataComponent - the json description of the data component

    Returns:
        void
*/
void GroupchatMessageReply::set(const char* messageId, const char* dataComponent)
{
    int size = strlen("{\"messageId\":\"\",\"dataComponent\":}")+strlen(messageId)+strlen(dataComponent)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2Json(json,"dataComponent",dataComponent);
}

/* Function: GroupchatMessageReply.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* sme_httpsUrl + endpoint
*/
char* GroupchatMessageReply::getEPurl()
{
    return sme_httpsUrl sme_communication_groupchat_message_reply;
}

/* Function: GroupchatMessageReply.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* GroupchatMessageReply::getWSEPurl()
{
    return sme_communication_groupchat_message_reply;        
}

/* Function: GroupchatMessageReply.get

    return the json script

    Prototype:
        void GroupchatMessageReply::get();

    Parameters:

    Returns:
        char*
*/
char* GroupchatMessageReply::get()
{
    return json;
}