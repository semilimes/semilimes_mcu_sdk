#ifndef _bucket_like_
#define _bucket_like_

#include "../defines.h"

class BucketLike
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: BucketLike

//     This endpoint sets a like by the current account to any referenced bucket that allows likes.

//     Prototype:
//         void BucketLike(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    BucketLike(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: BucketLike.setObj

//     This endpoint sets a like by the current account to any referenced bucket that allows likes.

//     Prototype:
//         void setObj(char* bucketId);

//     Parameters:
///@param         bucketId -  is the unique Id to reference an existing bucket

//     Returns:
///@returns         void
    void setObj(char* bucketId);

// Function: BucketLike.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif