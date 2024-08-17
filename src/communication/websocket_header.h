#ifndef _websocket_header_
#define _websocket_header_

#include "../defines.h"

class WebsocketHeader
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: WebsocketHeader

//     This endpoint create the websocket header json message on which the api call is to be embedded

//     Prototype:
//         void WebsocketHeader(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    WebsocketHeader(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: WebsocketHeader.setObj

//     This endpoint create the websocket header json message on which the api call is to be embedded 

//     Prototype:
//         void getRequest(char* requestId, char* requestType, char* body);

//     Parameters:
///@param         requestId - it is the unique Id to reference a specific call. It is responsability of the developer to generate an unique key that he can reuse to correlate the asynchronous response of the websocket
///@param         requestType - it is the endpoint of the specific api call. Can be retrieved by means of the function: "xxx.getEPurl()"
///@param         body - it is the json script of the API call to send

//     Returns:
///@returns         void
    char* getRequest(char* requestId, char* requestType, char* body);
};

#endif