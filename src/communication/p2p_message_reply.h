#ifndef _p2p_message_reply_
#define _p2p_message_reply_

#include "../defines.h"

class P2pMessageReply
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: P2pMessageReply

//     This endpoint allows the account to reply to a specific message with a simple text.

//     Prototype:
//         void P2pMessageReply(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    P2pMessageReply(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: P2pMessageReply.setObj

//     This endpoint allows the account to reply to a specific message with a simple text.

//     Prototype:
//         void setObj(char* messageId, char* dataComponent);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing p2p chat
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void setObj(char* messageId, char* dataComponent);

// Function: P2pMessageReply.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif