#ifndef _p2p_reaction_remove_
#define _p2p_reaction_remove_

#include "../defines.h"

class P2pReactionRemove
{
private:
    SmeJson json_data;
    char* json = nullptr;

public:
// Function: ~P2pReactionRemove

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~P2pReactionRemove()

//     Parameters:

//     Returns:
///@return         void
    ~P2pReactionRemove()
    {
        delete[] json;
        json = nullptr;
    }

// Function: P2pReactionRemove.set

//     This endpoint allows the account to remove a reaction from a specific message in a p2p Chat.

//     Prototype:
//         void set(const char* messageId, const char* reaction);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing p2p chat
///@param         reaction - 

//     Returns:
///@returns         void
    void set(const char* messageId, const char* reaction);

// Function: P2pReactionRemove.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: P2pReactionRemove.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: P2pReactionRemove.get

//     return the json script

//     Prototype:
//         void P2pReactionRemove::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif