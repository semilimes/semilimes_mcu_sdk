#include "p2p_signal_typing.h"

/* Function: P2pSignalTyping.set

    This endpoint allows the calling user to let recipient know in advance that the user is going to publish a new message. 
    This is particularly useful when having automated bots which need some time to elaborate the message to be sent.

    Prototype:
        void set(char* recipientId);

    Parameters:
        recipientId -  is the unique Id to reference an existing p2p chat

    Returns:
        void
*/
void P2pSignalTyping::set(char* recipientId)
{
    int size = headerSize+strlen(recipientId)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"recipientId",recipientId);
}

/* Function: P2pSignalTyping.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* P2pSignalTyping::getEPurl()
{
    return httpsUrl communication_p2p_signal_typing;        
}

/* Function: P2pSignalTyping.get

    return the json script

    Prototype:
        void P2pSignalTyping::get();

    Parameters:

    Returns:
        char*
*/
char* P2pSignalTyping::get()
{
    return json;
}