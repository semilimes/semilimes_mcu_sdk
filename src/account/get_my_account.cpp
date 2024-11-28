#include "get_my_account.h"

/* Function: GetMyAccount.set

    This endpoint lists all the user accounts somehow linked to the calling user, including owned subaccounts and shared accounts.

    Prototype:
        void GetMyAccount::set(bool main,bool sub,bool shared,bool details);

    Parameters:
        main - include main account
        sub - include subaccounts
        shared - include shared accounts
        details - include details

    Returns:
      
*/
void GetMyAccount::set(bool main,bool sub,bool shared,bool details)
{
    int size = strlen("{\"main\":,\"sub\":,\"shared\":,\"details\":}")+json_data.boolStrSize(main)+json_data.boolStrSize(sub)+json_data.boolStrSize(shared)+json_data.boolStrSize(details)+1;
    json = new char[size];
    json_data.initJson(json);
    json_data.addPair2JsonBool(json, "main", main);
    json_data.addPair2JsonBool(json, "sub", sub);
    json_data.addPair2JsonBool(json, "shared", shared);
    json_data.addPair2JsonBool(json, "details", details);
}

/* Function: GetAccountFeed.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* sme_httpsUrl + endpoint
*/
char* GetMyAccount::getEPurl()
{
    return sme_httpsUrl sme_account_my;        
}

/* Function: GetAccountFeed.getWSEPurl

    provides this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* GetMyAccount::getWSEPurl()
{
    return sme_account_my;
}

/* Function: GetMyAccount.get

    return the json script
    
    Prototype:
        void GetMyAccount::get();

    Parameters:

    Returns:
        char*
*/
char* GetMyAccount::get()
{
    return json;
}