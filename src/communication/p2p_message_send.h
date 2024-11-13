#ifndef _p2p_message_send_
#define _p2p_message_send_

#include "../defines.h"

class P2pMessageSend
{
private:
    SmeJson json_data;
    char* json = nullptr;

// Function: P2pMessageSend.addOptions

//     add an list of options

//     Prototype:
//         void P2pMessageSend::addOptions(bool silent);

//     Parameters:
///@param         silent - is a boolean to allow sending the message without any in-app notification
        
//    Returns:
///@return       void
    void addOptions(bool silent);

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
//         void set(const char* recipientId, const char* dataComponent, bool silent);

//     Parameters:
///@param         recipientId - is the unique Id to reference an existing p2p chat
///@param         dataComponent - the json description of the data component
///@param         silent - is a boolean to allow sending the message without any in-app notification

//     Returns:
///@returns         void
    void set(const char* recipientId, const char* dataComponent, bool silent);

// Function: P2pMessageSend.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: P2pMessageSend.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
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