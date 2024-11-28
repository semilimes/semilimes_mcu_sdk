#include "get_account_profile.h"

/* Function: GetMyAccount.set

    Gets the account profile's configuration and content.

    Prototype:
        void GetAccountProfile::set(const char* accountId);

    Parameters:
        accountId - the account id of which show configuration and content

    Returns:
      
*/
void GetAccountProfile::set(const char* accountId)
{
    int size = strlen("{\"accountId\":\"\"}")+strlen(accountId)+1;
    json = new char[size];
    json_data.initJson(json);
    json_data.addPair2JsonStr(json, "accountId", accountId);
}

/* Function: GetAccountFeed.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* sme_httpsUrl + endpoint
*/
char* GetAccountProfile::getEPurl()
{
    return sme_httpsUrl sme_account_profile;        
}

/* Function: GetAccountFeed.getWSEPurl

    provides this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* GetAccountProfile::getWSEPurl()
{
    return sme_account_profile;
}

/* Function: GetAccountProfile.get

    return the json script
    
    Prototype:
        void GetAccountProfile::get();

    Parameters:

    Returns:
        char*
*/
char* GetAccountProfile::get()
{
    return json;
}