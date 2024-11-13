#ifndef _p2p_message_update_
#define _p2p_message_update_

#include "../defines.h"

class P2pMessageUpdate
{
private:
    SmeJson json_data;
    char* json = nullptr;

// Function: P2pMessageUpdate.addOptions

//     add an list of options

//     Prototype:
//         void P2pMessageUpdate::addOptions(bool silent);

//     Parameters:
///@param         silent - is a boolean to allow sending the message without any in-app notification
        
//    Returns:
///@return       void
    void addOptions(bool silent);

public:
// Function: ~P2pMessageUpdate

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~P2pMessageUpdate()

//     Parameters:

//     Returns:
///@return         void
    ~P2pMessageUpdate()
    {
        delete[] json;
        json = nullptr;
    }

// Function: P2pMessageUpdate.set

//     This endpoint allows to update a specific message published in a p2p chat.

//     Prototype:
//         void set(const char* messageId, const char* dataComponent, bool silent);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing p2p chat
///@param         dataComponent - the json description of the data component
///@param         silent - is a boolean to allow sending the message without any in-app notification

//     Returns:
///@returns         void
    void set(const char* messageId, const char* dataComponent, bool silent);

// Function: P2pMessageUpdate.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: P2pMessageUpdate.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: P2pMessageUpdate.get

//     return the json script

//     Prototype:
//         void P2pMessageUpdate::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif