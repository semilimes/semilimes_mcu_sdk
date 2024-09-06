#ifndef _p2p_message_update_
#define _p2p_message_update_

#include "../defines.h"

class P2pMessageUpdate
{
private:
    #define headerSize 33
    SmeJson json_data;
    char* json = nullptr;

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
//         void set(char* messageId, char* dataComponent);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing p2p chat
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void set(char* messageId, char* dataComponent);

// Function: P2pMessageUpdate.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
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