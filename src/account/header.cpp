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
    strcpy(auth,authType);
    strncat(auth,apikey,strlen(apikey));
}

/* Function: Header.getHttpsUrl

    return the https server url

    Prototype:
        char* Header::getHttpsUrl();

    Parameters:

    Returns:
        char* httpsUrl
*/
char* Header::getHttpsUrl()
{
    return httpsUrl;
}

/* Function: Header.getWsEP

    return the web socket endpoint

    Prototype:
        char* Header::getwsEP();

    Parameters:

    Returns:
        char* wsEP
*/
char* Header::getWsEP()
{
    return wsEP;
}

/* Function: Header.getwsClientEP

    return the web socket client endpoint

    Prototype:
        char* Header::getwsClientEP();

    Parameters:

    Returns:
        char* wsClientEP
*/
char* Header::getWsClientEP()
{
    return wsClientEP;
}

/* Function: Header.getWsHost

    return the web socket host

    Prototype:
        char* Header::getwsHost();

    Parameters:

    Returns:
        char* wsHost
*/
char* Header::getWsHost()
{
    return wsHost;
}

/* Function: Header.getWsPort

    return the web socket port

    Prototype:
        int Header::getwsPort();

    Parameters:

    Returns:
        int  wsPort
*/
int Header::getWsPort()
{
    return wsPort;
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
	strncat(wsheader, " \r\n accept: " accept, 12+sizeof(accept));
	strncat(wsheader, " \r\n Content-Type: " contentType, 19+sizeof(contentType));	
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
    return contentType;
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
    return accept;
}