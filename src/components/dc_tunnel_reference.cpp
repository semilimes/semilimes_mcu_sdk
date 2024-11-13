#include "dc_tunnel_reference.h"

/* Function: DcTunnelReference.set

    A message referencing an existing Tunnel

    Prototype:
        void DcTunnelReference::set(const char* tunnelId);

    Parameters:
        tunnelId - the id of the referenced tunnel
        
    Returns:
        void
*/
void DcTunnelReference::set(const char* tunnelId)
{
    int size = strlen("{\"dataComponentType\":\"tunnel\",\"tunnelId\":\"\"}")+strlen(tunnelId)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"dataComponentType","tunnel");
    json_data.addPair2JsonStr(json,"tunnelId",tunnelId);
}

/* Function: DcTunnelReference.get

    return the json script

    Prototype:
        void DcTunnelReference::get();

    Parameters:

    Returns:
        char*
*/
char* DcTunnelReference::get()
{
    return json;
}