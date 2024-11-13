#ifndef _p2p_signal_typing_
#define _p2p_signal_typing_

#include "../defines.h"

class P2pSignalTyping
{
private:
    SmeJson json_data;
    char* json = nullptr;
    
public:

// Function: ~P2pSignalTyping

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~P2pSignalTyping()

//     Parameters:

//     Returns:
///@return         void
    ~P2pSignalTyping()
    {
        delete[] json;
        json = nullptr;
    }

// Function: P2pSignalTyping.set

//     This endpoint allows the calling user to let recipient know in advance that the user is going to publish a new message. 
//     This is particularly useful when having automated bots which need some time to elaborate the message to be sent.

//     Prototype:
//         void set(const char* recipientId);

//     Parameters:
///@param         recipientId -  is the unique Id to reference an existing p2p chat

//     Returns:
///@returns         void
    void set(const char* recipientId);

// Function: P2pSignalTyping.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: P2pSignalTyping.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();

// Function: P2pSignalTyping.get

//     return the json script

//     Prototype:
//         void P2pSignalTyping::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif