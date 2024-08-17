#ifndef _header_
#define _header_

#include "../defines.h"

class Header
{
private:
    char** pauth;
    char** pjson;
    char** pwsheader;
    SmeJson json_data;

// Function: Header.setJSON

//     create the Autorization json 

//     Prototype:
//         void Header::setJSON();

//     Parameters:

//     Returns:
///@returns         void

    void  setJSON();

public:

// Function: Header

//     set the api-key, and provide the pointers to json and websocket header array

//     Prototype:
//         Header(char* auth, char* json, char* wsheader);

//     Parameters:
///@param          auth - the pointer to the predefined array to contain the authorization script 
///@param          json - the pointer to the predefined array to contain the json script 
///@param          wsheader - the pointer to the predefined array to contain the websocket header  

//     Returns:
///@returns         void
    Header(char* auth, char* json, char* wsheader)
    {
        pauth = &auth;
        pjson = &json;
        pwsheader = &wsheader;
        json_data.initJson(*pjson);
    }

// Function: Header.setAuthorization

//     set the api-key

//     Prototype:
//         void Header::setAuthorization(char* apikey);

//     Parameters:
///@param          apikey - apikey received during the provisioning phase, needed to create the authorization string

//     Returns:
///@returns         void

    void setAuthorization(char* apikey);

// Function: Header.getHttpsUrl

//     return the https server url

//     Prototype:
//         char* Header::getHttpsUrl();

//     Parameters:

//     Returns:
///@returns         char* httpsUrl

    char* getHttpsUrl();

// Function: Header.getwsEP

//     return the web socket endpoint

//     Prototype:
//         char* Header::getwsEP();

//     Parameters:

//     Returns:
///@returns         char* wsEP

    char* getWsEP();

// Function: Header.getwsClientEP

//     return the web socket client endpoint

//     Prototype:
//         char* Header::getwsClientEP();

//     Parameters:

//     Returns:
///@returns         char* wsClientEP

    char* getWsClientEP();

// Function: Header.getwsHost

//     return the web socket host

//     Prototype:
//         char* Header::getwsHost();

//     Parameters:

//     Returns:
///@returns         char* wsHost

    char* getWsHost();

// Function: Header.getwsPort

//     return the web socket port

//     Prototype:
//         int Header::getwsPort();

//     Parameters:

//     Returns:
///@returns         int  wsPort

    int getWsPort();

// Function: Header.getWsHeader

//     return the formatted websocket header 

//     Prototype:
//         char* Header::getWsHeader();

//     Parameters:

//     Returns:
///@returns         *pwsheader - a char* containing the ws header

    char* getWsHeader();

// Function: Header.getContentType

//     return the contentType 

//     Prototype:
//         char* Header::getContentType();

//     Parameters:

//     Returns:
///@returns         contentType

    char* getContentType();

// Function: Header.getAuthorization

//     return the authorization 

//     Prototype:
//         char* Header::getAuthorization();

//     Parameters:

//     Returns:
///@returns         *pauth

    char* getAuthorization();

// Function: Header.getAuthorization

//     return the accept 

//     Prototype:
//         char* Header::getAccept();

//     Parameters:

//     Returns:
///@returns         accept

    char* getAccept();
};

#endif