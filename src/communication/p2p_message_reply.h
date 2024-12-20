#ifndef _p2p_message_reply_
#define _p2p_message_reply_

#include "../defines.h"

class P2pMessageReply
{
private:
    SmeJson json_data;
    char* json = nullptr;

public:
// Function: ~P2pMessageReply

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~P2pMessageReply()

//     Parameters:

//     Returns:
///@return         void
    ~P2pMessageReply()
    {
        delete[] json;
        json = nullptr;
    }

// Function: P2pMessageReply.set

//     This endpoint allows the account to reply to a specific message with a simple text.

//     Prototype:
//         void set(const char* messageId, const char* dataComponent);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing p2p chat
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void set(const char* messageId, const char* dataComponent);

// Function: P2pMessageReply.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* sme_httpsUrl + endpoint
    char* getEPurl();
    
// Function: P2pMessageReply.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: P2pMessageReply.get

//     return the json script

//     Prototype:
//         void P2pMessageReply::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif