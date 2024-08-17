#include "add_account_feed.h"

/* Function: AddAccountFeed.setObj

    Gets the account feed's configuration and content. Each post can only contain a bucket component type.
    
    Prototype:
        void AddAccountFeed::setObj(char* title,char* description,char* avatar,bool visible,bool locked,bool enReaction);
    
    Parameters:
        title - sets the feed title
        description - sets the feed description
        avatar - takes a fileId (obtained by a File Upload endpoint) and sets the main avatar image of the feed
        locked - define the feed general edit permissions. If set to true, its content cannot be interacted by other users
        enReactions - allows other users to post reactions (e.g. likes) to feed’s content

    Returns:
      
*/
void AddAccountFeed::setObj(char* title,char* description,char* avatar,bool visible,bool locked,bool enReaction)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonStr(*pjson,"description",description);
    json_data.addPair2JsonStr(*pjson,"avatar",avatar);
	json_data.addPair2JsonBool(*pjson,"visible",visible);
	json_data.addPair2JsonBool(*pjson,"locked",locked);
	json_data.addPair2JsonBool(*pjson,"enReactions",enReaction);

}

/* Function: AddAccountFeed.addDataComponents

    Add a data component to the array

    Prototype:
        void AddAccountFeed::addDataComponents(char* data);

    Parameters:
        data - the json description of the data component

    Returns:
        void
*/
void AddAccountFeed::addDataComponents(char* data)
{    
   json_data.add2Json(*pjsonArray,data);
}

/* Function: AddAccountFeed.appendDataComponents

    Append the selected data components

    Prototype:
        void AddAccountFeed::appendDataComponents();

    Parameters:

    Returns:
        void
*/
void AddAccountFeed::appendDataComponents()
{
	json_data.add2JsonArray(*pjson,"dataComponents",*pjsonArray);
}
