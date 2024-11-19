#include "groupchats_get.h"

/* Function: GroupchatsGet.addRecipientId

    Add the recipientId 

    Prototype:
        void addRecipientId(const char* recipientIds);

    Parameters:
        recipientIds - the json script of the dataComponent to add

    Returns:
        void
*/
void GroupchatsGet::addRecipientId(const char* recipientId)
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
    if(jsonArray!=nullptr)
    {
        int size = strlen(json)+strlen(jsonArray)+17;   //add ',"recipientIds":' and '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"recipientIds",jsonArray);
    }
}

/* Function: GroupchatsGet.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* sme_httpsUrl + endpoint
*/
char* GroupchatsGet::getEPurl()
{
    return sme_httpsUrl sme_communication_groupchat;
}

/* Function: GroupchatsGet.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* GroupchatsGet::getWSEPurl()
{
    return sme_communication_groupchat;        
}

/* Function: GroupchatsGet.get

    return the json script

    Prototype:
        void GroupchatsGet::get();

    Parameters:

    Returns:
        char*
*/
char* GroupchatsGet::get()
{
    return json;
}