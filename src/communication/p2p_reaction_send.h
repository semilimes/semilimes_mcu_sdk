#ifndef _send_p2p_reaction_
#define _send_p2p_reaction_

#include "../defines.h"

class P2pReactionSend
{
private:
    SmeJson json_data;
    char* json = nullptr;

public:
// Function: ~P2pReactionSend

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~P2pReactionSend()

//     Parameters:

//     Returns:
///@return         void
    ~P2pReactionSend()
    {
        delete[] json;
        json = nullptr;
    }

// Function: P2pReactionSend.set

//     This endpoint allows the account to remove a reaction from a specific message in a p2p Chat.

//     Prototype:
//         void set(const char* messageId, const char* reaction);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing p2p Chat
///@param         reaction - 

//     Returns:
///@returns         void
    void set(const char* messageId, const char* reaction);

// Function: P2pReactionSend.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* sme_httpsUrl + endpoint
    char* getEPurl();
    
// Function: P2pReactionSend.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: P2pReactionSend.get

//     return the json script

//     Prototype:
//         void P2pReactionSend::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif