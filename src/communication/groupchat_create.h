#ifndef _groupchat_create_
#define _groupchat_create_

#include "../defines.h"

class GroupchatCreate
{
private:
    #define headerSize 28
    #define headerArraySize 2
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
//         void set(char* title);

//     Parameters:
///@param         title - sets the group chat title

//     Returns:
///@returns         void
    void set(char* title);

// Function: GroupchatCreate.addRecipientIds

//     Add the recipientId (the account Id to be added in the groupchat)

//     Prototype:
//         void addRecipientIds(char* recipientIds);

//     Parameters:
///@param         recipientIds - the json script of the dataComponent to add

//     Returns:
///@returns         void
    void addRecipientId(char* recipientIds);

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