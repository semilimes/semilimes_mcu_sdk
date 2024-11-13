#include "get_account_feed.h"

/* Function: GetAccountFeed.set

    Gets the account feed's configuration and content. Each post can only contain a bucket component type.

    Prototype:
        void GetAccountFeed::set(const char* accountId,int before,int after,int limit);

    Parameters:
        accountId - the account id of which show the feeds configuration and content
        before - Get feed's content published before this date (unix timestamp).
        after - Get feed's posts published before this date (unix timestamp).
        limit - Maximum number of posts returned.

    Returns:
      
*/
void GetAccountFeed::set(const char* accountId,int before,int after,int limit)
{
    int size = strlen("{\"accountId\":\"\",\"before\":\"\",\"after\":\"\",\"limit\":\"\"}")+strlen(accountId)+json_data.intStrSize(before)+json_data.intStrSize(after)+json_data.intStrSize(limit)+1;
    json = new char[size];
    json_data.initJson(json);
    json_data.addPair2JsonStr(json, "accountId",accountId);
    json_data.addPair2JsonInt(json, "before", before);
    json_data.addPair2JsonInt(json, "after", after);
    json_data.addPair2JsonInt(json, "limit", limit);
}

/* Function: GetAccountFeed.get

    return the json script
    
    Prototype:
        void GetAccountFeed::get();

    Parameters:

    Returns:
        char*
*/
char* GetAccountFeed::get()
{
    return json;
}