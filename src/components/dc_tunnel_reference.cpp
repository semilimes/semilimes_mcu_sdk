#include "dc_tunnel_reference.h"

/* Function: DcTunnelReference.setObj

    A message referencing an existing Tunnel

    Prototype:
        void DcTunnelReference::setObj(char* tunnelId);

    Parameters:
        tunnelId - the id of the referenced tunnel
        
    Returns:
        void
*/
void DcTunnelReference::setObj(char* tunnelId)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"dataComponentType","tunnel");
    json_data.addPair2JsonStr(*pjson,"tunnelId",tunnelId);
}