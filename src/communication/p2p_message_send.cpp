#include "p2p_message_send.h"

/* Function: P2pMessageSend.set

    This endpoint allows to send a data component to a Channel as a new message.

    Prototype:
        void set(char* recipientId, char* dataComponent);

    Parameters:
        recipientId - is the unique Id to reference an existing p2p chat
        dataComponent - the json description of the data component
        silent - is a boolean to allow sending the message without any in-app notification

    Returns:
        void
*/
void P2pMessageSend::set(char* recipientId, char* dataComponent, bool silent)
{
    int size = headerSize+strlen(recipientId)+strlen(dataComponent)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"recipientId",recipientId);
    json_data.addPair2Json(json,"dataComponent",dataComponent);
    this->addOptions(silent);
}

/* Function: P2pMessageSend.addOptions

    add a list of options 

    Prototype:
        void P2pMessageSend::addOptions(char* name,char* value);

    Parameters:
        silent - is a boolean to allow sending the message without any in-app notification

    Returns:
        void
*/
void P2pMessageSend::addOptions(bool silent)
{
    int size = optionsHeaderSize+json_data.boolStrSize(silent)+1;
    char* optTemp = new char[size];
    json_data.initJson(optTemp);
    json_data.addPair2JsonBool(optTemp, "silent", silent);
    size += strlen(json)+12;   //add bytes for ',"options":' and '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"options",optTemp);
}

/* Function: P2pMessageSend.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* P2pMessageSend::getEPurl()
{
    return httpsUrl communication_p2p_message_send;
}

/* Function: P2pMessageSend.get

    return the json script

    Prototype:
        void P2pMessageSend::get();

    Parameters:

    Returns:
        char*
*/
char* P2pMessageSend::get()
{
    return json;
}