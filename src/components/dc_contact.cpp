#include "dc_contact.h"

/* Function: DcContact.setObj

   A message that references one or more account Ids to be added as contacts

   Prototype:
      void DcContact::setObj();

   Parameters:

   Returns:
      void
*/
void DcContact::setObj()
{
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
        json_data.addPair2JsonStr(*pjson,"dataComponentType","contact");
}

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
   json_data.add2JsonStr(*pjsonArray,contactIds);
}

/* Function: DcContact.appendDataContactIds

   Append the contact Id array to the json message 

   Prototype:
      void DcContact::appendDataContactIds();

   Parameters:

   Returns:
      void
*/
void DcContact::appendDataContactIds()
{
	json_data.add2JsonArray(*pjson,"contactIds",*pjsonArray);
}
