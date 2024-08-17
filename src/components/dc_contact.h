#ifndef _dc_contact_
#define _dc_contact_

#include "../defines.h"

class DcContact
{
private:
    SmeJson json_data;
    char** pjson;
    char** pjsonArray;

public:
// Function: DcContact

//    A message that references one or more account Ids to be added as contacts

//     Prototype:
//         void DcContact(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    DcContact(char* json, char* jsonArray)
    {
        pjson = &json;
        pjsonArray = &jsonArray;
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
        json_data.addPair2JsonStr(*pjson,"dataComponentType","contact");
    }

// Function: DcContact.setObj

//    A message that references one or more account Ids to be added as contacts

//    Prototype:
//       void DcContact::setObj();

//    Parameters:

//    Returns:
///@return       void
    void setObj();

// Function: DcContact.addContactIds

//    Add a contact Id to the array

//    Prototype:
//       void DcContact::addContactIds(char* contactIds);

//    Parameters:
///@param       contactIds - the Contact Id to add

//    Returns:
///@return       void
    void addContactIds(char* data);

// Function: DcContact.appendDataContactIds

//    Append the contact Id array to the json message 

//    Prototype:
//       void DcContact::appendDataContactIds();

//    Parameters:

//    Returns:
///@return       void
    void appendDataContactIds();
};

#endif