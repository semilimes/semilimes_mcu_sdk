#ifndef _p2p_message_send_
#define _p2p_message_send_

#include "../defines.h"

class P2pMessageSend
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: P2pMessageSend

//     This endpoint allows to send a data component to a Channel as a new message.

//     Prototype:
//         void P2pMessageSend(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    P2pMessageSend(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: P2pMessageSend.setObj

//     This endpoint allows to send a data component to a Channel as a new message.

//     Prototype:
//         void setObj(char* recipientId, char* dataComponent);

//     Parameters:
///@param         recipientId - is the unique Id to reference an existing p2p chat
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void setObj(char* recipientId, char* dataComponent);

// Function: P2pMessageSend.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif