#ifndef _fc_get_account_feed_
#define _fc_get_account_feed_

#include "../defines.h"

class GetAccountFeed
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    
public:
// Function: ~GetAccountFeed

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~GetAccountFeed()

//     Parameters:

//     Returns:
///@return         void
    ~GetAccountFeed()
    {
        delete[] json;
        json = nullptr;
    }

// Function: GetAccountFeed.set

//     Gets the account feed's configuration and content. Each post can only contain a bucket component type.

//     Prototype:
//         void GetAccountFeed::set(const char* accountId,int before,int after,int limit);

//     Parameters:
///@param         accountId - the account id of which show the feeds configuration and content
///@param          before - Get feed's content published before this date (unix timestamp).
///@param          after - Get feed's posts published before this date (unix timestamp).
///@param          limit - Maximum number of posts returned.

//     Returns:
///@returns         void      

    void set(const char* accountId,int before,int after,int limit);

// Function: GetAccountFeed.get

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
    
//     return the json script

//     Prototype:
//         void GetAccountFeed::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif