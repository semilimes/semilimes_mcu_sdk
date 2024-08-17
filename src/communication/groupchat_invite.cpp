#include "groupchat_invite.h"

/* Function: GroupchatInvite.setObj

   This endpoint allows to invite other recipients to the specified group chat.
    Prototype:
        void setObj(char* groupChatIds)

    Parameters:
        groupChatId - is the unique Id to reference an existing groupChat

    Returns:
        void
*/
void GroupchatInvite::setObj(char* groupChatIds)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"groupChatIds",groupChatIds);
}

/* Function: GroupchatInvite.addRecipientIds

    Add the recipientId 

    Prototype:
        void addRecipientIds(char* recipientIds);

    Parameters:
        recipientIds - the json script of the dataComponent to invite

    Returns:
        void
*/
void GroupchatInvite::addRecipientIds(char* recipientIds)
{    
    json_data.add2JsonStr(*pjsonArray,recipientIds);
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
	json_data.add2JsonArray(*pjson,"recipientIds",*pjsonArray);
}

/* Function: GetGroupchatMessage.getEPurl

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