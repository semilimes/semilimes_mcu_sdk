#include "get_account_profile.h"

/* Function: GetMyAccount.setObj

    Gets the account profile's configuration and content.

    Prototype:
        void GetAccountProfile::setObj(char* accountId);

    Parameters:
        accountId - the account id of which show configuration and content

    Returns:
      
*/
void GetAccountProfile::setObj(char* accountId)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson, "accountId", accountId);
}