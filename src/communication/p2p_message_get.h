#ifndef _p2p_message_get_
#define _p2p_message_get_

#include "../defines.h"

class P2pMessageGet
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: P2pMessageGet

//     This endpoint returns a list of messages in the specified P2P chat

//     Prototype:
//         void P2pMessageGet(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    P2pMessageGet(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: P2pMessageGet.setObj

//     This endpoint returns a list of messages in the specified P2P chat

//     Prototype:
//         void setObj(bool owner,bool editor,bool subscriber);

//     Parameters:
///@param         recipientId - Filters the p2p chats list by showing only the one occurring with the specified account id.
///@param         messageId - is the unique Id to reference an existing p2p chat
///@param         limit - sets the limit of the messages to receive

//     Returns:
///@returns         void
    void setObj(char* recipientId,char* messageId,int limit);

// Function: P2pMessageGet.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif