#ifndef _dc_tunnel_reference_
#define _dc_tunnel_reference_

#include "../defines.h"

class DcTunnelReference
{
private:
    #define headerSize 44
    SmeJson json_data;
    char* json = nullptr;

public:
// Function: ~DcTunnelReference

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~DcTunnelReference()

//     Parameters:

//     Returns:
///@return         void
    ~DcTunnelReference()
    {
        delete[] json;
        json = nullptr;
    }

// Function: DcTunnelReference.set

//     A message referencing an existing Tunnel

//     Prototype:
//         void DcTunnelReference::set(char* tunnelId);

//     Parameters:
///@param         tunnelId - the id of the referenced tunnel
        
//     Returns:
///@return         void
    void set(char* tunnelId);
    
// Function: DcTunnelReference.get

//     return the json script

//     Prototype:
//         void DcTunnelReference::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif