#ifndef _groupchat_create_
#define _groupchat_create_

#include "../defines.h"

class GroupchatCreate
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;
    
public:
// Function: ~GroupchatCreate

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GroupchatCreate()

//     Parameters:

//     Returns:
///@return         void
    ~GroupchatCreate()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }
    
// Function: GroupchatCreate.set

//     This endpoint creates a new group chat with a specified name. It's also possible to directly invite other accounts to the chat upon creation by specifying their accountIds in the recipientIds array.

//     Prototype:
//         void set(const char* title);

//     Parameters:
///@param         title - sets the group chat title

//     Returns:
///@returns         void
    void set(const char* title);

// Function: GroupchatCreate.addRecipientIds

//     Add the recipientId (the account Id to be added in the groupchat)

//     Prototype:
//         void addRecipientIds(const char* recipientIds);

//     Parameters:
///@param         recipientIds - the json script of the dataComponent to add

//     Returns:
///@returns         void
    void addRecipientId(const char* recipientIds);

// Function: GroupchatCreate.appendRecipientIds

//     Append the selected recipientIds

//     Prototype:
//         void appendRecipientIds();

//     Parameters:

//     Returns:
///@returns        void
    void appendRecipientIds();

// Function: GroupchatCreate.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: GroupchatCreate.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: GroupchatCreate.get

//     return the json script

//     Prototype:
//         void GroupchatCreate::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif