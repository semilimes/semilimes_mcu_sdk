#include "get_account_feed.h"

/* Function: GetAccountFeed.setObj

    Gets the account feed's configuration and content. Each post can only contain a bucket component type.

    Prototype:
        void GetAccountFeed::setObj(char* accountId,int before,int after,int limit);

    Parameters:
        accountId - the account id of which show the feeds configuration and content
        before - Get feed's content published before this date (unix timestamp).
        after - Get feed's posts published before this date (unix timestamp).
        limit - Maximum number of posts returned.

    Returns:
      
*/
void GetAccountFeed::setObj(char* accountId,int before,int after,int limit)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson, "accountId",accountId);
    json_data.addPair2JsonInt(*pjson, "before", before);
    json_data.addPair2JsonInt(*pjson, "after", after);
    json_data.addPair2JsonInt(*pjson, "limit", limit);

}