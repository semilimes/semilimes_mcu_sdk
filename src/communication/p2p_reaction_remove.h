#ifndef _p2p_reaction_remove_
#define _p2p_reaction_remove_

#include "../defines.h"

class P2pReactionRemove
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: P2pReactionRemove

//     This endpoint allows the account to remove a reaction from a specific message in a p2p Chat.

//     Prototype:
//         void P2pReactionRemove(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    P2pReactionRemove(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: P2pReactionRemove.setObj

//     This endpoint allows the account to remove a reaction from a specific message in a p2p Chat.

//     Prototype:
//         void setObj(char* messageId, char* reaction);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing p2p chat
///@param         reaction - 

//     Returns:
///@returns         void
    void setObj(char* messageId, char* reaction);

// Function: P2pReactionRemove.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif