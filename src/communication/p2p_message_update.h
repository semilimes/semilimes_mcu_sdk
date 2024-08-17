#ifndef _p2p_message_update_
#define _p2p_message_update_

#include "../defines.h"

class P2pMessageUpdate
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: P2pMessageUpdate

//     This endpoint allows to update a specific message published in a p2p chat.

//     Prototype:
//         void P2pMessageUpdate(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    P2pMessageUpdate(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: P2pMessageUpdate.setObj

//     This endpoint allows to update a specific message published in a p2p chat.

//     Prototype:
//         void setObj(char* messageId, char* dataComponent);

//     Parameters:
///@param         messageId - is the unique Id to reference an existing p2p chat
///@param         dataComponent - the json description of the data component

//     Returns:
///@returns         void
    void setObj(char* messageId, char* dataComponent);

// Function: P2pMessageUpdate.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif