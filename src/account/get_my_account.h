#ifndef _fc_get_account_
#define _fc_get_account_

#include "../defines.h"

class GetMyAccount
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    
public:
// Function: ~GetMyAccount

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GetMyAccount()

//     Parameters:

//     Returns:
///@return         void
    ~GetMyAccount()
    {
        delete[] json;
        json = nullptr;
    }

// Function: GetMyAccount.set

//     This endpoint lists all the user accounts somehow linked to the calling user, including owned subaccounts and shared accounts.

//     Prototype:
//         void GetMyAccount::set(bool main,bool sub,bool shared,bool details);

//     Parameters:
///@param          main - include main account
///@param          sub - include subaccounts
///@param          shared - include shared accounts
///@param          details - include details

//     Returns:
///@returns         void
      

    void set(bool main,bool sub,bool shared,bool details);

//     Prototype:
///@param         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* sme_httpsUrl + endpoint

    char* getEPurl();

// Function: BucketOpen.getWSEPurl

//     provides this endpoint

//     Prototype:
///@param         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint

    char* getWSEPurl();
    
// Function: GetMyAccount.get

//     return the json script

//     Prototype:
//         void GetMyAccount::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif