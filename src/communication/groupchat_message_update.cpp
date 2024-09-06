#include "groupchat_message_update.h"

/* Function: GroupchatMessageUpdate.set

    This endpoint allows to update a specific message published in a group Chat

    Prototype:
        void set(char* messageId, char* dataComponent);

    Parameters:
        channelId - is the unique Id to reference an existing channel
        dataComponent - the json description of the data component

    Returns:
        void
*/
void GroupchatMessageUpdate::set(char* messageId, char* dataComponent)
{
    int size = headerSize+strlen(messageId)+strlen(dataComponent)+1;
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"messageId",messageId);
    json_data.addPair2Json(json,"dataComponent",dataComponent);
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

