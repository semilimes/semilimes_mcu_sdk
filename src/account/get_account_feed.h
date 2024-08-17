#ifndef _fc_get_account_feed_
#define _fc_get_account_feed_

#include "../defines.h"

class GetAccountFeed
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: GetAccountFeed

//     Gets the account feed's configuration and content. Each post can only contain a bucket component type.

//     Prototype:
//         void GetAccountFeed(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    GetAccountFeed(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: GetAccountFeed.setObj

//     Gets the account feed's configuration and content. Each post can only contain a bucket component type.

//     Prototype:
//         void GetAccountFeed::setObj(char* accountId,int before,int after,int limit);

//     Parameters:
///@param         accountId - the account id of which show the feeds configuration and content
///@param          before - Get feed's content published before this date (unix timestamp).
///@param          after - Get feed's posts published before this date (unix timestamp).
///@param          limit - Maximum number of posts returned.

//     Returns:
///@returns         void      

    void setObj(char* accountId,int before,int after,int limit);
};

#endif