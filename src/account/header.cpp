#include "Header.h"

/* Function: Header.setAuthorization

    set the api-key

    Prototype:
        void Header::setAuthorization(char* apikey);

    Parameters:
        apikey - the api key received during the provisioning phase 

    Returns:
        void
*/
void Header::setAuthorization(const char* apikey)
{
    strcpy(auth,sme_authType);
    strncat(auth,apikey,strlen(apikey));
}

/* Function: Header.getHttpsUrl

    return the https server url

    Prototype:
        char* Header::getHttpsUrl();

    Parameters:

    Returns:
        char* sme_httpsUrl
*/
char* Header::getHttpsUrl()
{
    return sme_httpsUrl;
}

/* Function: Header.getWsEP

    return the web socket endpoint

    Prototype:
        char* Header::getwsEP();

    Parameters:

    Returns:
        char* sme_wsEP
*/
char* Header::getWsEP()
{
    return sme_wsEP;
}

/* Function: Header.getwsClientEP

    return the web socket client endpoint

    Prototype:
        char* Header::getwsClientEP();

    Parameters:

    Returns:
        char* sme_wsClientEP
*/
char* Header::getWsClientEP()
{
    return sme_wsClientEP;
}

/* Function: Header.getWsHost

    return the web socket host

    Prototype:
        char* Header::getwsHost();

    Parameters:

    Returns:
        char* sme_wsHost
*/
char* Header::getWsHost()
{
    return sme_wsHost;
}

/* Function: Header.getWsPort

    return the web socket port

    Prototype:
        int Header::getwsPort();

    Parameters:

    Returns:
        int  sme_wsPort
*/
int Header::getWsPort()
{
    return sme_wsPort;
}

/* Function: Header.getWsHeader

    return the formatted websocket header 

    Prototype:
        char* Header::getWsHeader();

    Parameters:

    Returns:
        *pwsheader - a char* containing the ws header
*/
char* Header::getWsHeader()
{	
	strncpy(wsheader, "Authorization: " , 16);
	strncat(wsheader, auth, strlen(auth));
	strncat(wsheader, " \r\n accept: " sme_accept, 12+sizeof(sme_accept));
	strncat(wsheader, " \r\n Content-Type: " sme_contentType, 19+sizeof(sme_contentType));	
	strncat(wsheader, " \r\n", 3);
    return wsheader;
}

/* Function: Header.getContentType

    return the contentType 

    Prototype:
        char* Header::getContentType();

    Parameters:

    Returns:
        contentType
*/
char* Header::getContentType()
{
    return sme_contentType;
}

/* Function: Header.getAuthorization

    return the authorization 

    Prototype:
        char* Header::getAuthorization();

    Parameters:

    Returns:
        *pauth
*/
char* Header::getAuthorization()
{
    return auth;
}

/* Function: Header.getAuthorization

    return the accept 

    Prototype:
        char* Header::getAccept();

    Parameters:

    Returns:
        accept
*/
char* Header::getAccept()
{
    return sme_accept;
}