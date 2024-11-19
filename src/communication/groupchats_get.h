#ifndef _groupchats_get_
#define _groupchats_get_

#include "../defines.h"

class GroupchatsGet
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;
    
public:
// Function: GroupchatsGet

//     constructor of the class, init the json

//     Prototype:
//         GroupchatsGet()

//     Parameters:

//     Returns:
///@return         void
    GroupchatsGet()
    {
        json = new char[3];
        json_data.initJson(json);
    }

// Function: ~GroupchatsGet

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GroupchatsGet()

//     Parameters:

//     Returns:
///@return         void
    ~GroupchatsGet()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: GroupchatsGet.addRecipientId

//     Add the recipientId 

//     Prototype:
//         void addRecipientId(const char* recipientIds);

//     Parameters:
///@param         recipientId - the json script of the dataComponent to add

//     Returns:
///@returns         void
    void addRecipientId(const char* recipientId);

// Function: GroupchatsGet.appendRecipientIds

//     Append the selected recipientIds

//     Prototype:
//         void appendRecipientIds();

//     Parameters:

//     Returns:
///@returns         void
    void appendRecipientIds();

// Function: GroupchatsGet.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* sme_httpsUrl + endpoint
    char* getEPurl();
    
// Function: GroupchatsGet.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: GroupchatsGet.get

//     return the json script

//     Prototype:
//         void GroupchatsGet::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif