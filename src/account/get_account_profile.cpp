#include "get_account_profile.h"

/* Function: GetMyAccount.set

    Gets the account profile's configuration and content.

    Prototype:
        void GetAccountProfile::set(char* accountId);

    Parameters:
        accountId - the account id of which show configuration and content

    Returns:
      
*/
void GetAccountProfile::set(char* accountId)
{
    int size = headerSize+strlen(accountId)+1;
    json = new char[size];
    json_data.initJson(json);
    json_data.addPair2JsonStr(json, "accountId", accountId);
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