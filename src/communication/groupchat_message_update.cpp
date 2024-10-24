#include "groupchat_message_update.h"

/* Function: GroupchatMessageUpdate.set

    This endpoint allows to update a specific message published in a group Chat

    Prototype:
        void set(char* messageId, char* dataComponent);

    Parameters:
        channelId - is the unique Id to reference an existing channel
        dataComponent - the json description of the data component
        silent - is a boolean to allow sending the message without any in-app notification

    Returns:
        void
*/
void GroupchatMessageUpdate::set(char* messageId, char* dataComponent, bool silent)
{
    int size = headerSize+strlen(messageId)+strlen(dataComponent)+1;
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2Json(json,"dataComponent",dataComponent);
    this->addOptions(silent);
}

/* Function: GroupchatMessageUpdate.addOptions

    add a list of options 

    Prototype:
        void GroupchatMessageUpdate::addOptions(char* name,char* value);

    Parameters:
        silent - is a boolean to allow sending the message without any in-app notification

    Returns:
        void
*/
void GroupchatMessageUpdate::addOptions(bool silent)
{
    int size = optionsHeaderSize+json_data.boolStrSize(silent)+1;
    char* optTemp = new char[size];
    json_data.initJson(optTemp);
    json_data.addPair2JsonBool(optTemp, "silent", silent);
    size += strlen(json)+12;   //add bytes for ',"options":' and '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"options",optTemp);
}

/* Function: GroupchatMessageUpdate.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* GroupchatMessageUpdate::getEPurl()
{
    return httpsUrl communication_groupchat_message_update;
}

/* Function: GroupchatMessageUpdate.get

    return the json script

    Prototype:
        void GroupchatMessageUpdate::get();

    Parameters:

    Returns:
        char*
*/
char* GroupchatMessageUpdate::get()
{
    return json;
}

