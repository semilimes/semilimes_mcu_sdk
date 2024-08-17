#include "groupchat_create.h"

/* Function: GroupchatCreate.setObj

    This endpoint creates a new group chat with a specified name. It's also possible to directly invite other accounts to the chat upon creation by specifying their accountIds in the recipientIds array.

    Prototype:
        void setObj(char* title);

    Parameters:
        title - sets the group chat title

    Returns:
        void
*/
void GroupchatCreate::setObj(char* title)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"title",title);
}

/* Function: GroupchatCreate.addRecipientIds

    Add the recipientId (the account Id to be added in the groupchat)

    Prototype:
        void addRecipientIds(char* recipientIds);

    Parameters:
        recipientIds - the json script of the dataComponent to add

    Returns:
        void
*/
void GroupchatCreate::addRecipientId(char* recipientIds)
{    
    json_data.add2JsonStr(*pjsonArray,recipientIds);
}

/* Function: GroupchatCreate.appendRecipientIds

    Append the selected recipientIds

    Prototype:
        void appendRecipientIds();

    Parameters:

    Returns:
        void
*/
void GroupchatCreate::appendRecipientIds()
{
	json_data.add2JsonArray(*pjson,"recipientIds",*pjsonArray);
}

/* Function: GroupchatCreate.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* GroupchatCreate::getEPurl()
{
    return httpsUrl communication_groupchat_create;
}