#ifndef _fc_get_account_profile_
#define _fc_get_account_profile_

#include "../defines.h"

class GetAccountProfile
{
private:
    #define headerSize 16
    SmeJson json_data;
    char* json = nullptr; 
    
public:
// Function: ~GetAccountProfile

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GetAccountProfile()

//     Parameters:

//     Returns:
///@return         void
    ~GetAccountProfile()
    {
        delete[] json;
        json = nullptr;
    }

// Function: GetAccountProfile.set

//     Gets the account profile's configuration and content.

//     Prototype:
//         void GetAccountProfile::set(char* accountId);

//     Parameters:
///@param         accountId - the account id of which show configuration and content

//     Returns:
///@returns         void
      

    void set(char* accountId);

// Function: GetAccountProfile.get

//     return the json script

//     Prototype:
//         void GetAccountProfile::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif