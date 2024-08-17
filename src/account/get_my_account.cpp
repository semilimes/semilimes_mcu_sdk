#include "get_my_account.h"

/* Function: GetMyAccount.setObj

    This endpoint lists all the user accounts somehow linked to the calling user, including owned subaccounts and shared accounts.

    Prototype:
        void GetMyAccount::setObj(bool main,bool sub,bool shared,bool details);

    Parameters:
        main - include main account
        sub - include subaccounts
        shared - include shared accounts
        details - include details

    Returns:
      
*/
void GetMyAccount::setObj(bool main,bool sub,bool shared,bool details)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonBool(*pjson, "main", main);
    json_data.addPair2JsonBool(*pjson, "sub", sub);
    json_data.addPair2JsonBool(*pjson, "shared", shared);
    json_data.addPair2JsonBool(*pjson, "details", details);

}