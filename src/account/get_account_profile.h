#ifndef _fc_get_account_profile_
#define _fc_get_account_profile_

#include "../defines.h"

class GetAccountProfile
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: GetAccountProfile

//     Gets the account profile's configuration and content.

//     Prototype:
//         void GetAccountProfile(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    GetAccountProfile(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: GetMyAccount.setObj

//     Gets the account profile's configuration and content.

//     Prototype:
//         void GetAccountProfile::setObj(char* accountId);

//     Parameters:
///@param         accountId - the account id of which show configuration and content

//     Returns:
///@returns         void
      

    void setObj(char* accountId);
};

#endif