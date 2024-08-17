#ifndef _dc_tunnel_reference_
#define _dc_tunnel_reference_

#include "../defines.h"

class DcTunnelReference
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: DcTunnelReference

//     A message referencing an existing Tunnel

//     Prototype:
//         void DcTunnelReference(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    DcTunnelReference(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: DcTunnelReference.setObj

//     A message referencing an existing Tunnel

//     Prototype:
//         void DcTunnelReference::setObj(char* tunnelId);

//     Parameters:
///@param         tunnelId - the id of the referenced tunnel
        
//     Returns:
///@return         void
    void setObj(char* tunnelId);
};

#endif