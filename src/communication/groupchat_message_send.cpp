#include "groupchat_message_send.h"

/* Function: GroupchatMessageSend.set

    This endpoint allows to send a data component to a groupChat as a new message.

    Prototype:
        void set(char* groupChatId, char* dataComponent);

    Parameters:
        groupChatId - is the unique Id to reference an existing groupChat
        dataComponent - the json description of the data component
        silent - is a boolean to allow sending the message without any in-app notification

    Returns:
        void
*/
void GroupchatMessageSend::set(char* groupChatId, char* dataComponent, bool silent)
{
    int size = headerSize+strlen(groupChatId)+strlen(dataComponent)+1;
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"groupChatId",groupChatId);
    json_data.addPair2Json(json,"dataComponent",dataComponent);
    this->addOptions(silent);
}

/* Function: GroupchatMessageSend.addOptions

    add a list of options 

    Prototype:
        void GroupchatMessageSend::addOptions(char* name,char* value);

    Parameters:
        silent - is a boolean to allow sending the message without any in-app notification

    Returns:
        void
*/
void GroupchatMessageSend::addOptions(bool silent)
{
    int size = optionsHeaderSize+json_data.boolStrSize(silent)+1;
    char* optTemp = new char[size];
    json_data.initJson(optTemp);
    json_data.addPair2JsonBool(optTemp, "silent", silent);
    size += strlen(json)+12;   //add bytes for ',"options":' and '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"options",optTemp);
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

