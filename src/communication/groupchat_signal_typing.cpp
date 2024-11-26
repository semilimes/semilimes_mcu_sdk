#include "groupchat_signal_typing.h"

/* Function: GroupchatSignalTyping.set

    This endpoint allows the calling user to let all group chat members know in advance that the user is going to publish a new message. 
    This is particularly useful when having automated bots which need some time to elaborate the message to be sent.

    Prototype:
        void set(const char* groupChatId);

    Parameters:
        groupChatId -  is the unique Id to reference an existing groupChat

    Returns:
        void
*/
void GroupchatSignalTyping::set(const char* groupChatId)
{
    int size = headerSize+strlen(groupChatId)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"groupChatId",groupChatId);
}

/* Function: GroupchatSignalTyping.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* sme_httpsUrl + endpoint
*/
char* GroupchatSignalTyping::getEPurl()
{
    return sme_httpsUrl sme_communication_groupchat_signal_typing;        
}

/* Function: GroupchatSignalTyping.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* GroupchatSignalTyping::getWSEPurl()
{
    return sme_communication_groupchat_signal_typing;        
}

/* Function: GroupchatSignalTyping.get

    return the json script

    Prototype:
        void GroupchatSignalTyping::get();

    Parameters:

    Returns:
        char*
*/
char* GroupchatSignalTyping::get()
{
    return json;
}