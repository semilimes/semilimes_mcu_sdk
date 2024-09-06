#include "dc_ch_reference.h"

/* Function: DcChReference.set

    A message referencing an existing channel

    Prototype:
        void DcChReference::set(char* channelId)

    Parameters:
        channelId - the Id of the channel

    Returns:
        void
*/
void DcChReference::set(char* channelId)
{
    int size = headerSize+strlen(channelId)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"dataComponentType","channel");
    json_data.addPair2JsonStr(json,"channelId",channelId);
}

/* Function: DcChReference.get

    return the json script

    Prototype:
        void DcChReference::get();

    Parameters:

    Returns:
        char*
*/
char* DcChReference::get()
{
    return json;
}