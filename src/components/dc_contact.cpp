#include "dc_contact.h"

/* Function: DcContact.addContactIds

   Add a contact Id to the array

   Prototype:
      void DcContact::addContactIds(char* contactIds);

   Parameters:
      contactIds - the Contact Id to add

   Returns:
      void
*/
void DcContact::addContactIds(char* contactIds)
{       
    int size = headerArraySize+strlen(contactIds)+1;
    
    if(!jsonArray)
    {
        jsonArray = new char[size+1];
        json_data.initJsonArray(jsonArray);
    }
    else
    {
        size += strlen(jsonArray)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
        json_data.arrayResize(jsonArray,size+1); //add '\0' for null-termination
    }
    json_data.add2Json(jsonArray,contactIds);
}

/* Function: DcContact.appendContactIds

   Append the contact Id array to the json message 

   Prototype:
      void DcContact::appendContactIds();

   Parameters:

   Returns:
      void
*/
void DcContact::appendContactIds()
{    
    if(jsonArray!=nullptr)
    {
        int size = strlen(json)+strlen(jsonArray)+15;   //add ',"contactIds":' and '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"contactIds",jsonArray);
    }
}

/* Function: DcContact.get

    return the json script

    Prototype:
        void DcContact::get();

    Parameters:

    Returns:
        char*
*/
char* DcContact::get()
{
    return json;
}
