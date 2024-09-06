#ifndef _bucket_update
#define _bucket_update

#include "../defines.h"

class BucketUpdate
{
private:
    #define headerSize 120
    #define headerArraySize 2
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;

public:
// Function: ~BucketUpdate

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~BucketUpdate()

//     Parameters:

//     Returns:
///@return         void
    ~BucketUpdate()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: BucketUpdate.set

//     This endpoint allows the user to update the content of a specific bucket.

//     Prototype:
//         void set(char* bucketId);

//     Parameters:
///@param         bucketId -  is the unique Id to reference an existing bucket
///@param         title - sets the bucket title
///@param         description - sets the bucket description
///@param         avatar -  takes a fileId (obtained by a File Upload endpoint) and sets the main avatar image of the bucket
///@param         visible - sets the bucket general visibility. If set to false, the bucket will be only visible to its creator
///@param        locked - sets the bucket’s general edit permissions. If set to true, its content cannot be interacted by other users
///@param         enReactions - allows other users to post reactions (e.g. likes) to bucket’s content

//     Returns:
///@returns        void
    void set(char* bucketId, char* title, char* description, char* avatar, bool visible, bool locked, bool enReactions);

// Function: BucketUpdate.addDataComponents

//     Prototype:
//         void addDataComponents(char* component);

//     Append the selected components

//     Parameters:
///@param        component - the json script of the dataComponent to add

//     Returns:
///@returns        void
    void addDataComponents(char* component);

// Function: BucketUpdate.appendDataComponents

//     Append the selected dataComponents

//     Prototype:
//         void appendDataComponents();

//     Parameters:

//     Returns:
///@returns         void
    void appendDataComponents();

// Function: BucketUpdate.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns        char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: BucketUpdate.get

//     return the json script

//     Prototype:
//         void BucketUpdate::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif