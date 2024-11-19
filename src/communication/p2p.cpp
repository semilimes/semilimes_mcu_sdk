#include "p2p.h"

/* Function: P2p.setObj

    This endpoint retrieves the p2p chats of the calling user account.

    Prototype:
        void setObj();

    Parameters:

    Returns:
        void
*/
char* P2p::getEPurl()
{
    return sme_httpsUrl sme_communication_p2p;        
}

/* Function: P2p.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* P2p::getWSEPurl()
{
    return sme_communication_p2p;        
}