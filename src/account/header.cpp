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
void Header::setAuthorization(char* apikey)
{
    strcpy(*pauth,authType);
    strncat(*pauth,apikey,strlen(apikey));
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

/* Function: Header.setAuthorization

    create the Autorization json 

    Prototype:
        void Header::setJSON();

    Parameters:

    Returns:
        void
*/
void Header::setJSON()
{	
	json_data.addPair2JsonStr(*pjson, "accept", accept);
    json_data.addPair2JsonStr(*pjson, "Content-Type", contentType);
    json_data.addPair2JsonStr(*pjson, "Authorization", *pauth);
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
	strncpy(*pwsheader, "Authorization: " , 16);
	strncat(*pwsheader, *pauth, strlen(*pauth));
	strncat(*pwsheader, " \r\n accept: " accept, 12+sizeof(accept));
	strncat(*pwsheader, " \r\n Content-Type: " contentType, 19+sizeof(contentType));	
	strncat(*pwsheader, " \r\n", 3);
    return *pwsheader;
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
    return *pauth;
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