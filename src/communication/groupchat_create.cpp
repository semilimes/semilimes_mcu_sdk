#include "groupchat_create.h"

/* Function: GroupchatCreate.set

    This endpoint creates a new group chat with a specified name. It's also possible to directly invite other accounts to the chat upon creation by specifying their accountIds in the recipientIds array.

    Prototype:
        void set(const char* title);

    Parameters:
        title - sets the group chat title

    Returns:
        void
*/
void GroupchatCreate::set(const char* title)
{
    int size = strlen("{\"title\":\"\"}")+strlen(title)+1; //add '\0' for null-termination
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"title",title);
}

/* Function: GroupchatCreate.addRecipientIds

    Add the recipientId (the account Id to be added in the groupchat)

    Prototype:
        void addRecipientIds(const char* recipientIds);

    Parameters:
        recipientIds - the json script of the dataComponent to add

    Returns:
        void
*/
void GroupchatCreate::addRecipientId(const char* recipientIds)
{   
    int size = strlen("[]")+strlen(recipientIds)+3; //add '\0' and \"\" 
    
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
    json_data.add2JsonStr(jsonArray,recipientIds);
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
    if(jsonArray!=nullptr)
    {
        int size =  strlen(",\"recipientIds\":")+strlen(json)+strlen(jsonArray)+17;   //add '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"recipientIds",jsonArray);
    }
}

/* Function: GroupchatCreate.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* sme_httpsUrl + endpoint
*/
char* GroupchatCreate::getEPurl()
{
    return sme_httpsUrl sme_communication_groupchat_create;
}

/* Function: GroupchatCreate.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* GroupchatCreate::getWSEPurl()
{
    return sme_communication_groupchat_create;        
}

/* Function: GroupchatCreate.get

    return the json script

    Prototype:
        void GroupchatCreate::get();

    Parameters:

    Returns:
        char*
*/
char* GroupchatCreate::get()
{
    return json;
}