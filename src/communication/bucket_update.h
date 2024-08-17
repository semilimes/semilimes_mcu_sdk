#ifndef _bucket_update
#define _bucket_update

#include "../defines.h"

class BucketUpdate
{
private:
    SmeJson json_data;
    char** pjson;
    char** pjsonArray;

public:
// Function: BucketUpdate

//     This endpoint allows the user to update the content of a specific bucket.

//     Prototype:
//         void BucketUpdate(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 
///@param         jsonArray - it is a temporary char array that will contain the data components 

//     Returns:
///@return         void
    BucketUpdate(char* json, char* jsonArray)
    {
        pjson = &json;
        pjsonArray = &jsonArray;
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
        json_data.addPair2JsonStr(*pjson,"dataComponentType","bucket");
    }

// Function: BucketUpdate.setObj

//     This endpoint allows the user to update the content of a specific bucket.

//     Prototype:
//         void setObj(char* bucketId);

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
    void setObj(char* bucketId, char* title, char* description, char* avatar, bool visible, bool locked, bool enReactions);

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
};

#endif