#ifndef _update_to_channel_request_
#define _update_to_channel_request_

#include "../defines.h"

class ChannelMessageUpdate
{
private:
    SmeJson json_data;
    char* json = nullptr;

// Function: ChannelMessageUpdate.addOptions

//     add an list of options

//     Prototype:
//         void ChannelMessageUpdate::addOptions(bool silent);

//     Parameters:
///@param         silent - is a boolean to allow sending the message without any in-app notification
        
//    Returns:
///@return       void
    void addOptions(bool silent);

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
//         void set(const char* messageId, const char* dataComponent, bool silent);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing groupChat
///@param         dataComponent - the json description of the data component
///@param         silent - is a boolean to allow sending the message without any in-app notification

//     Returns:
///@returns         void
    void set(const char* messageId, const char* dataComponent, bool silent);

// Function: ChannelMessageUpdate.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* sme_httpsUrl + endpoint
    char* getEPurl();
    
// Function: ChannelMessageUpdate.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
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