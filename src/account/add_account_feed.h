#ifndef _fc_add_account_feed_
#define _fc_add_account_feed_

#include "../defines.h"

class AddAccountFeed
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;
    
public:
// Function: ~AddAccountFeed

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~AddAccountFeed()

//     Parameters:

//     Returns:
///@return         void
    ~AddAccountFeed()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: AddAccountFeed.set

//     Gets the account feed's configuration and content. Each post can only contain a bucket component type.
    
//     Prototype:
//         void AddAccountFeed::set(const char* title,const char* description,const char* avatar,bool visible,bool locked,bool enReaction);
    
//     Parameters:
///@param          title - sets the feed title
///@param          description - sets the feed description
///@param          avatar - takes a fileId (obtained by a File Upload endpoint) and sets the main avatar image of the feed
///@param          locked - define the feed general edit permissions. If set to true, its content cannot be interacted by other users
///@param          enReactions - allows other users to post reactions (e.g. likes) to feed’s content

//     Returns:
///@returns         void      
      

    void set(const char* title,const char* description,const char* avatar,bool visible,bool locked,bool enReaction);

// Function: AddAccountFeed.addDataComponents

//     Add a data component to the array

//     Prototype:
//         void AddAccountFeed::addDataComponents(cost char* data);

//     Parameters:
///@param         data - the json description of the data component

//     Returns:
///@returns         void      

    void addDataComponents(const char* data);

// Function: AddAccountFeed.appendDataComponents

//     Append the selected data components

//     Prototype:
//         void AddAccountFeed::appendDataComponents();

//     Parameters:

//     Returns:
///@returns         void  

    void appendDataComponents();
    

// Function: AddAccountFeed.get

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
//         void AddAccountFeed::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif