#ifndef _groupchat_message_update_
#define _groupchat_message_update_

#include "../defines.h"

class GroupchatMessageUpdate
{
private:
    #define headerSize 33
    SmeJson json_data;
    char* json = nullptr;

public:
// Function: ~GroupchatMessageUpdate

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GroupchatMessageUpdate()

//     Parameters:

//     Returns:
///@return         void
    ~GroupchatMessageUpdate()
    {
        delete[] json;
        json = nullptr;
    }

// Function: GroupchatMessageUpdate.set

//     This endpoint allows to update a specific message published in a group Chat

//     Prototype:
//         void set(char* messageId, char* dataComponent);

//     Parameters:
///@param         channelId - is the unique Id to reference an existing channel
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void set(char* messageId, char* dataComponent);

// Function: GroupchatMessageUpdate.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: GroupchatMessageUpdate.get

//     return the json script

//     Prototype:
//         void GroupchatMessageUpdate::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif