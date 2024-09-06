#include "groupchat_message_get.h"

/* Function: GroupchatMessageGet.set

    This endpoint returns a list of messages in the specified Group chat.

    Prototype:
        void set(char* groupChatId,char* messageId,int limit);

    Parameters:
        groupChatId - is the unique Id to reference an existing groupChat
        messageId - is the unique Id to reference an existing groupChat
        limit - sets the limit of the messages to receive

    Returns:
        void
*/
void GroupchatMessageGet::set(char* groupChatId,char* messageId,int limit)
{
    int size = headerSize+strlen(groupChatId)+strlen(messageId)+json_data.intStrSize(limit)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"groupChatId",groupChatId);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2JsonInt(json,"limit",limit);
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

/* Function: GroupchatMessageGet.get

    return the json script

    Prototype:
        void GroupchatMessageGet::get();

    Parameters:

    Returns:
        char*
*/
char* GroupchatMessageGet::get()
{
    return json;
}