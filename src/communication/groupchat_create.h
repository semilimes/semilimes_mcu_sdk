#ifndef _groupchat_create_
#define _groupchat_create_

#include "../defines.h"

class GroupchatCreate
{
private:
    SmeJson json_data;
    char** pjson;
    char** pjsonArray;
    
public:
// Function: GroupchatCreate

//     This endpoint creates a new group chat with a specified name. It's also possible to directly invite other accounts to the chat upon creation by specifying their accountIds in the recipientIds array.

//     Prototype:
//         void GroupchatCreate(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 
///@param         jsonArray - it is a temporary char array that will contain the RecipentIds 

//     Returns:
///@return         void
    GroupchatCreate(char* json, char* jsonArray)
    {
        pjson = &json;
        pjsonArray = &jsonArray;
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
    }
    
// Function: GroupchatCreate.setObj

//     This endpoint creates a new group chat with a specified name. It's also possible to directly invite other accounts to the chat upon creation by specifying their accountIds in the recipientIds array.

//     Prototype:
//         void setObj(char* title);

//     Parameters:
///@param         title - sets the group chat title

//     Returns:
///@returns         void
    void setObj(char* title);

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
};

#endif