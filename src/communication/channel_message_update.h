#ifndef _update_to_channel_request_
#define _update_to_channel_request_

#include "../defines.h"

class ChannelMessageUpdate
{
private:
    #define headerSize 33
    SmeJson json_data;
    char* json = nullptr;

public:

// Function: ~ChannelMessageUpdate

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~ChannelMessageUpdate()

//     Parameters:

//     Returns:
///@return         void
    ~ChannelMessageUpdate()
    {
        delete[] json;
        json = nullptr;
    }

// Function: ChannelMessageUpdate.set

//     This endpoint allows to update a specific message published in a channel.

//     Prototype:
//         void set(char* messageId, char* dataComponent);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing groupChat
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void set(char* messageId, char* dataComponent);

// Function: ChannelMessageUpdate.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: ChannelMessageUpdate.get

//     return the json script

//     Prototype:
//         void ChannelMessageUpdate::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif