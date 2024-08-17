#include "websocket_header.h"

/* Function: WebsocketHeader.setObj

    This endpoint create the websocket header json message on which the api call is to be embedded 

    Prototype:
        void getRequest(char* requestId, char* requestType, char* body);

    Parameters:
        requestId - it is the unique Id to reference a specific call. It is responsability of the developer to generate an unique key that he can reuse to correlate the asynchronous response of the websocket
        requestType - it is the endpoint of the specific api call. Can be retrieved by means of the function: "xxx.getEPurl()"
        body - it is the json script of the API call to send

    Returns:
        void
*/
char* WebsocketHeader::getRequest(char* requestId, char* requestType, char* body)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"requestId",requestId);
    json_data.addPair2JsonStr(*pjson,"requestType",requestType);
    json_data.addPair2JsonStr(*pjson,"version","2");
    json_data.addPair2Json(*pjson,"body",body);
    return *pjson;
}
