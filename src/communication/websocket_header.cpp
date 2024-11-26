#include "websocket_header.h"

/* Function: WebsocketHeader.setObj

    This endpoint create the websocket header json message on which the api call is to be embedded 

    Prototype:
        void getRequest(const char* requestId, const char* requestType, const char* body);

    Parameters:
        requestId - it is the unique Id to reference a specific call. It is responsability of the developer to generate an unique key that he can reuse to correlate the asynchronous response of the websocket
        requestType - it is the endpoint of the specific api call. Can be retrieved by means of the function: "xxx.getEPurl()"
        body - it is the json script of the API call to send

    Returns:
        void
*/
char* WebsocketHeader::getRequest(const char* requestId, const char* requestType, const char* body)
{
    int size = headerSize+strlen(requestId)+strlen(requestType)+strlen(body)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"requestId",requestId);
    json_data.addPair2JsonStr(json,"requestType",requestType);
    json_data.addPair2JsonStr(json,"version","2");
    json_data.addPair2Json(json,"body",body);
    return json;
}
