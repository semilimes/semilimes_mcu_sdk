#include "groupchat_signal_typing.h"

/* Function: GroupchatSignalTyping.set

    This endpoint allows the calling user to let all group chat members know in advance that the user is going to publish a new message. 
    This is particularly useful when having automated bots which need some time to elaborate the message to be sent.

    Prototype:
        void set(char* groupChatId);

    Parameters:
        groupChatId -  is the unique Id to reference an existing groupChat

    Returns:
        void
*/
void GroupchatSignalTyping::set(char* groupChatId)
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
        char* httpsUrl + endpoint
*/
char* GroupchatSignalTyping::getEPurl()
{
    return httpsUrl communication_groupchat_signal_typing;        
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
    return communication_groupchat_signal_typing;        
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