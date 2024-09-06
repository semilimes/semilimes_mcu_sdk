#include "channel_message_update.h"

/* Function: ChannelMessageUpdate.set

    This endpoint allows to update a specific message published in a channel.

    Prototype:
        void set(char* messageId, char* dataComponent);

    Parameters:
        messageId - is the unique Id to reference an existing groupChat
        dataComponent - the json description of the data component

    Returns:
        void
*/
void ChannelMessageUpdate::set(char* messageId, char* dataComponent)
{
    int size = headerSize+strlen(messageId)+strlen(dataComponent)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2Json(json,"dataComponent",dataComponent);
}

/* Function: ChannelMessageUpdate.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* ChannelMessageUpdate::getEPurl()
{
    return httpsUrl communication_channel_update;
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