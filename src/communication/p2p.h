#ifndef _p2p_
#define _p2p_

#include "../defines.h"

class P2p
{    
public:

// Function: P2p.setObj

//     This endpoint retrieves the p2p chats of the calling user account.

//     Prototype:
//         void setObj();

//     Parameters:

//     Returns:
///@returns         void

    char* getEPurl();
    
// Function: P2p.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
};

#endif