#include "channel_message_send.h"

/* Function: ChannelMessageSend.set

    This endpoint allows to send a data component to a Channel as a new message.

    Prototype:
        void set(const char* messageId, const char* dataComponent);

    Parameters:
        channelId - is the unique Id to reference an existing channel
        dataComponent - the json description of the data component
        silent - is a boolean to allow sending the message without any in-app notification

    Returns:
        void
*/
void ChannelMessageSend::set(const char* channelId, const char* dataComponent, bool silent)
{
    int size = strlen("{\"channelId\":\"\",\"dataComponent\":}")+strlen(channelId)+strlen(dataComponent)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"channelId",channelId);
    json_data.addPair2Json(json,"dataComponent",dataComponent);
    this->addOptions(silent);
}

/* Function: ChannelMessageSend.addOptions

    add a list of options 

    Prototype:
        void ChannelMessageSend::addOptions(char* name,char* value);

    Parameters:
        silent - is a boolean to allow sending the message without any in-app notification

    Returns:
        void
*/
void ChannelMessageSend::addOptions(bool silent)
{
    int size = strlen("\"silent\":")+json_data.boolStrSize(silent)+1;
    char* optTemp = new char[size];
    json_data.initJson(optTemp);
    json_data.addPair2JsonBool(optTemp, "silent", silent);
    size += strlen(",\"options\":")+strlen(optTemp)+strlen(json)+1;   //add '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"options",optTemp);
}

/* Function: ChannelMessageSend.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* ChannelMessageSend::getEPurl()
{
    return httpsUrl communication_channel_message_send;
}

/* Function: ChannelMessageSend.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* ChannelMessageSend::getWSEPurl()
{
    return communication_channel_message_send;        
}

/* Function: ChannelMessageSend.get

    return the json script

    Prototype:
        void ChannelMessageSend::get();

    Parameters:

    Returns:
        char*
*/
char* ChannelMessageSend::get()
{
    return json;
}