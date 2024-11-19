#include "groupchat_invite.h"

/* Function: GroupchatInvite.set

   This endpoint allows to invite other recipients to the specified group chat.
    Prototype:
        void set(const char* groupChatIds)

    Parameters:
        groupChatId - is the unique Id to reference an existing groupChat

    Returns:
        void
*/
void GroupchatInvite::set(const char* groupChatId)
{
    int size = strlen("{\"groupChatId\":\"\"}")+strlen(groupChatId)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"groupChatId",groupChatId);
}

/* Function: GroupchatInvite.addRecipientIds

    Add the recipientId 

    Prototype:
        void addRecipientId(const char* recipientId);

    Parameters:
        recipientId - the json script of the dataComponent to invite

    Returns:
        void
*/
void GroupchatInvite::addRecipientId(const char* recipientId)
{    
    int size = strlen("[]")+strlen(recipientId)+3; //add '\0' and \"\" 
    
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
    if(jsonArray!=nullptr)
    {
        int size = strlen(",\"recipientIds\":")+strlen(json)+strlen(jsonArray)+1;   //add  '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"recipientIds",jsonArray);
    }
}

/* Function: GroupchatInvite.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* sme_httpsUrl + endpoint
*/
char* GroupchatInvite::getEPurl()
{
    return sme_httpsUrl sme_communication_groupchat_invite;
}

/* Function: GroupchatInvite.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* GroupchatInvite::getWSEPurl()
{
    return sme_communication_groupchat_invite;        
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