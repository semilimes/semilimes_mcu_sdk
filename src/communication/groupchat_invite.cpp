#include "groupchat_invite.h"

/* Function: GroupchatInvite.set

   This endpoint allows to invite other recipients to the specified group chat.
    Prototype:
        void set(char* groupChatIds)

    Parameters:
        groupChatId - is the unique Id to reference an existing groupChat

    Returns:
        void
*/
void GroupchatInvite::set(char* groupChatId)
{
    int size = headerSize+strlen(groupChatId)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"groupChatId",groupChatId);
}

/* Function: GroupchatInvite.addRecipientIds

    Add the recipientId 

    Prototype:
        void addRecipientId(char* recipientId);

    Parameters:
        recipientId - the json script of the dataComponent to invite

    Returns:
        void
*/
void GroupchatInvite::addRecipientId(char* recipientId)
{    
    int size = headerArraySize+strlen(recipientId)+3; //add '\0' and \"\" 
    
    if(!jsonArray)
    {
        jsonArray = new char[size];
        json_data.initJsonArray(jsonArray);
    }
    else
    {
        size += strlen(jsonArray)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
        json_data.arrayResize(jsonArray,size+1); //add '\0' for null-termination
    }
    json_data.add2JsonStr(jsonArray,recipientId);
}

/* Function: GroupchatInvite.appendRecipientIds

    Append the selected recipientIds

    Prototype:
        void appendRecipientIds();

    Parameters:

    Returns:
        void
*/
void GroupchatInvite::appendRecipientIds()
{
    int size = strlen(json)+strlen(jsonArray)+17;   //add ',"recipientIds":' and '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"recipientIds",jsonArray);
}

/* Function: GroupchatInvite.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* GroupchatInvite::getEPurl()
{
    return httpsUrl communication_groupchat_invite;
}

/* Function: GroupchatInvite.get

    return the json script

    Prototype:
        void GroupchatInvite::get();

    Parameters:

    Returns:
        char*
*/
char* GroupchatInvite::get()
{
    return json;
}