#ifndef _fc_add_account_feed_
#define _fc_add_account_feed_

#include "../defines.h"

class AddAccountFeed
{
private:
    #define headerSize 77
    #define headerArraySize 2
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
//         void AddAccountFeed::set(char* title,char* description,char* avatar,bool visible,bool locked,bool enReaction);
    
//     Parameters:
///@param          title - sets the feed title
///@param          description - sets the feed description
///@param          avatar - takes a fileId (obtained by a File Upload endpoint) and sets the main avatar image of the feed
///@param          locked - define the feed general edit permissions. If set to true, its content cannot be interacted by other users
///@param          enReactions - allows other users to post reactions (e.g. likes) to feed’s content

//     Returns:
///@returns         void      
      

    void set(char* title,char* description,char* avatar,bool visible,bool locked,bool enReaction);

// Function: AddAccountFeed.addDataComponents

//     Add a data component to the array

//     Prototype:
//         void AddAccountFeed::addDataComponents(char* data);

//     Parameters:
///@param         data - the json description of the data component

//     Returns:
///@returns         void      

    void addDataComponents(char* data);

// Function: AddAccountFeed.appendDataComponents

//     Append the selected data components

//     Prototype:
//         void AddAccountFeed::appendDataComponents();

//     Parameters:

//     Returns:
///@returns         void  

    void appendDataComponents();
    

// Function: AddAccountFeed.get

//     return the json script

//     Prototype:
//         void AddAccountFeed::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif