#include "add_account_feed.h"

/* Function: AddAccountFeed.set

    Gets the account feed's configuration and content. Each post can only contain a bucket component type.
    
    Prototype:
        void AddAccountFeed::set(const char* title,const char* description,const char* avatar,bool visible,bool locked,bool enReaction);
    
    Parameters:
        title - sets the feed title
        description - sets the feed description
        avatar - takes a fileId (obtained by a File Upload endpoint) and sets the main avatar image of the feed
        locked - define the feed general edit permissions. If set to true, its content cannot be interacted by other users
        enReactions - allows other users to post reactions (e.g. likes) to feed’s content

    Returns:
      
*/
void AddAccountFeed::set(const char* title,const char* description,const char* avatar,bool visible,bool locked,bool enReaction)
{
    int size = strlen("{\"title\":\"\",\"description\":\"\",\"avatar\":\"\",\"visible\":,\"locked\":,\"enReactions\":}")+strlen(title)+strlen(description)+strlen(avatar)+json_data.boolStrSize(visible)+json_data.boolStrSize(locked)+json_data.boolStrSize(enReaction)+1; //add '\0' for null-termination
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonStr(json,"description",description);
    json_data.addPair2JsonStr(json,"avatar",avatar);
	json_data.addPair2JsonBool(json,"visible",visible);
	json_data.addPair2JsonBool(json,"locked",locked);
	json_data.addPair2JsonBool(json,"enReactions",enReaction);
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
    int size = strlen("{}")+strlen(data)+1;
    
    if(!jsonArray)
    {
        jsonArray = new char[size];
        json_data.initJsonArray(jsonArray);
    }
    else
    {
        size += strlen(jsonArray)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
        json_data.arrayResize(jsonArray,size+1); //add '\0' for null-termination
    }
    json_data.add2Json(jsonArray,data);
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
    if(jsonArray!=nullptr)
    {   
        int size = strlen(",\"dataComponents\":")+strlen(json)+strlen(jsonArray)+19;   //add '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"dataComponents",jsonArray);
    }
}

/* Function: AddAccountFeed.get

    return the json script

    Prototype:
        void AddAccountFeed::get();

    Parameters:

    Returns:
        char*
*/
char* AddAccountFeed::get()
{
    return json;
}

