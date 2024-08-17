#ifndef _send_p2p_reaction_
#define _send_p2p_reaction_

#include "../defines.h"

class P2pReactionSend
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: P2pReactionSend

//     This endpoint allows the account to remove a reaction from a specific message in a p2p Chat.

//     Prototype:
//         void P2pReactionSend(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    P2pReactionSend(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: P2pReactionSend.setObj

//     This endpoint allows the account to remove a reaction from a specific message in a p2p Chat.

//     Prototype:
//         void setObj(char* messageId, char* reaction);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing p2p Chat
///@param         reaction - 

//     Returns:
///@returns         void
    void setObj(char* messageId, char* reaction);

// Function: P2pReactionSend.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif