#ifndef _p2p_message_send_
#define _p2p_message_send_

#include "../defines.h"

class P2pMessageSend
{
private:
    #define headerSize 35
    SmeJson json_data;
    char* json = nullptr;

public:
// Function: ~P2pMessageSend

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~P2pMessageSend()

//     Parameters:

//     Returns:
///@return         void
    ~P2pMessageSend()
    {
        delete[] json;
        json = nullptr;
    }

// Function: P2pMessageSend.set

//     This endpoint allows to send a data component to a Channel as a new message.

//     Prototype:
//         void set(char* recipientId, char* dataComponent);

//     Parameters:
///@param         recipientId - is the unique Id to reference an existing p2p chat
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void set(char* recipientId, char* dataComponent);

// Function: P2pMessageSend.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: P2pMessageSend.get

//     return the json script

//     Prototype:
//         void P2pMessageSend::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif