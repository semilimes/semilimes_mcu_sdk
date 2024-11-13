#ifndef _dc_contact_
#define _dc_contact_

#include "../defines.h"

class DcContact
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;

public:
/* Function: DcContact

   A message that references one or more account Ids to be added as contacts

   Prototype:
      void DcContact::set();

   Parameters:

   Returns:
      void
*/
    DcContact()
    {        
        int size = strlen("{\"dataComponentType\":\"contact\"}")+1;//add '\0' for null-termination
        json = new char[size]; 

        json_data.initJson(json);
        json_data.addPair2JsonStr(json,"dataComponentType","contact");
    }

// Function: ~DcContact

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~DcContact()

//     Parameters:

//     Returns:
///@return         void
    ~DcContact()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: DcContact.addContactIds

//    Add a contact Id to the array

//    Prototype:
//       void DcContact::addContactIds(const char* contactIds);

//    Parameters:
///@param       contactIds - the Contact Id to add

//    Returns:
///@return       void
    void addContactIds(const char* data);

// Function: DcContact.appendContactIds

//    Append the contact Id array to the json message 

//    Prototype:
//       void DcContact::appendContactIds();

//    Parameters:

//    Returns:
///@return       void
    void appendContactIds();
    
// Function: DcContact.get

//     return the json script

//     Prototype:
//         void DcContact::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif