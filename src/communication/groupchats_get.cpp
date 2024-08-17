#include "groupchats_get.h"

/* Function: GroupchatsGet.setObj

    This endpoint retrieves the group chats of the calling user account.

    Prototype:
        void setObj();

    Parameters:

    Returns:
        void
*/
void GroupchatsGet::setObj()
{
    json_data.initJson(*pjson);
}

/* Function: GroupchatsGet.addRecipientIds

    Add the recipientId 

    Prototype:
        void addRecipientIds(char* recipientIds);

    Parameters:
        recipientIds - the json script of the dataComponent to add

    Returns:
        void
*/
void GroupchatsGet::addRecipientIds(char* recipientIds)
{    
    json_data.add2JsonStr(*pjsonArray,recipientIds);
}

/* Function: GroupchatsGet.appendRecipientIds

    Append the selected recipientIds

    Prototype:
        void appendRecipientIds();

    Parameters:

    Returns:
        void
*/
void GroupchatsGet::appendRecipientIds()
{
	json_data.add2JsonArray(*pjson,"recipientIds",*pjsonArray);
}

/* Function: GroupchatsGet.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* GroupchatsGet::getEPurl()
{
    return httpsUrl communication_groupchat;
}