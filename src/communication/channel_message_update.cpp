#include "channel_message_update.h"

/* Function: ChannelMessageUpdate.set

    This endpoint allows to update a specific message published in a channel.

    Prototype:
        void set(const char* messageId, const char* dataComponent, bool silent);

    Parameters:
        messageId - is the unique Id to reference an existing groupChat
        dataComponent - the json description of the data component
        silent - is a boolean to allow sending the message without any in-app notification

    Returns:
        void
*/
void ChannelMessageUpdate::set(const char* messageId, const char* dataComponent, bool silent)
{
    int size = strlen("{\"messageId\":\"\",\"dataComponent\":}")+strlen(messageId)+strlen(dataComponent)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2Json(json,"dataComponent",dataComponent);
    this->addOptions(silent);
}

/* Function: ChannelMessageUpdate.addOptions

    add a list of options 

    Prototype:
        void ChannelMessageUpdate::addOptions(char* name,char* value);

    Parameters:
        silent - is a boolean to allow sending the message without any in-app notification

    Returns:
        void
*/
void ChannelMessageUpdate::addOptions(bool silent)
{
    int size = strlen("\"silent\":")+json_data.boolStrSize(silent)+1;
    char* optTemp = new char[size];
    json_data.initJson(optTemp);
    json_data.addPair2JsonBool(optTemp, "silent", silent);
    size += strlen(",\"options\":")+strlen(optTemp)+strlen(json)+1;   //add '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"options",optTemp);
}

/* Function: ChannelMessageUpdate.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* sme_httpsUrl + endpoint
*/
char* ChannelMessageUpdate::getEPurl()
{
    return sme_httpsUrl sme_communication_channel_update;
}

/* Function: ChannelMessageUpdate.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* ChannelMessageUpdate::getWSEPurl()
{
    return sme_communication_channel_update;        
}

/* Function: ChannelMessageUpdate.get

    return the json script

    Prototype:
        void ChannelMessageUpdate::get();

    Parameters:

    Returns:
        char*
*/
char* ChannelMessageUpdate::get()
{
    return json;
}