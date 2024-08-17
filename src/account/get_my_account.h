#ifndef _fc_get_account_
#define _fc_get_account_

#include "../defines.h"

class GetMyAccount
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: GetMyAccount

//     This endpoint lists all the user accounts somehow linked to the calling user, including owned subaccounts and shared accounts.

//     Prototype:
//         void GetMyAccount(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    GetMyAccount(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: GetMyAccount.setObj

//     This endpoint lists all the user accounts somehow linked to the calling user, including owned subaccounts and shared accounts.

//     Prototype:
//         void GetMyAccount::setObj(bool main,bool sub,bool shared,bool details);

//     Parameters:
///@param          main - include main account
///@param          sub - include subaccounts
///@param          shared - include shared accounts
///@param          details - include details

//     Returns:
///@returns         void
      

    void setObj(bool main,bool sub,bool shared,bool details);
};

#endif