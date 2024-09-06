#ifndef _p2p_message_get_
#define _p2p_message_get_

#include "../defines.h"

class P2pMessageGet
{
private:
    #define headerSize 42
    SmeJson json_data;
    char* json = nullptr;
    
public:
// Function: ~P2pMessageGet

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~P2pMessageGet()

//     Parameters:

//     Returns:
///@return         void
    ~P2pMessageGet()
    {
        delete[] json;
        json = nullptr;
    }

// Function: P2pMessageGet.set

//     This endpoint returns a list of messages in the specified P2P chat

//     Prototype:
//         void set(bool owner,bool editor,bool subscriber);

//     Parameters:
///@param         recipientId - Filters the p2p chats list by showing only the one occurring with the specified account id.
///@param         messageId - is the unique Id to reference an existing p2p chat
///@param         limit - sets the limit of the messages to receive

//     Returns:
///@returns         void
    void set(char* recipientId,char* messageId,int limit);

// Function: P2pMessageGet.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: P2pMessageGet.get

//     return the json script

//     Prototype:
//         void P2pMessageGet::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif