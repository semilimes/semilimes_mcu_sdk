#include "dc_ch_reference.h"

/* Function: DcChReference.setObj

    A message referencing an existing channel

    Prototype:
        void DcChReference::setObj(char* channelId)

    Parameters:
        channelId - the Id of the channel

    Returns:
        void
*/
void DcChReference::setObj(char* channelId)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"dataComponentType","channel");
    json_data.addPair2JsonStr(*pjson,"channelId",channelId);
}