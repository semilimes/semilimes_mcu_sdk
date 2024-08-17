#ifndef _groupchats_get_
#define _groupchats_get_

#include "../defines.h"

class GroupchatsGet
{
private:
    SmeJson json_data;
    char** pjson;
    char** pjsonArray;
    
public:
// Function: GroupchatsGet

//     This endpoint retrieves the group chats of the calling user account.

//     Prototype:
//         void GroupchatsGet(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 
///@param         jsonArray - it is a temporary char array that will contain the data recipientsIds 

//     Returns:
///@return         void
    GroupchatsGet(char* json, char* jsonArray)
    {
        pjson = &json;
        pjsonArray = &jsonArray;
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
    }

// Function: GroupchatsGet.setObj

//     This endpoint retrieves the group chats of the calling user account.

//     Prototype:
//         void setObj();

//     Parameters:

//     Returns:
///@returns         void
    void setObj();

// Function: GroupchatsGet.addRecipientIds

//     Add the recipientId 

//     Prototype:
//         void addRecipientIds(char* recipientIds);

//     Parameters:
///@param         recipientIds - the json script of the dataComponent to add

//     Returns:
///@returns         void
    void addRecipientIds(char* recipientIds);

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
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif