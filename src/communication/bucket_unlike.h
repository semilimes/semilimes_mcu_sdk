#ifndef _bucket_unlike_
#define _bucket_unlike_

#include "../defines.h"

class BucketUnlike
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: BucketUnlike

//     This endpoint unsets a like by the current account to any referenced bucket that allows likes.

//     Prototype:
//         void BucketUnlike(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    BucketUnlike(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: BucketUnlike.setObj

//     This endpoint unsets a like by the current account to any referenced bucket that allows likes.

//     Prototype:
//         void setObj(char* bucketId);

//     Parameters:
///@param         bucketId -  is the unique Id to reference an existing bucket

//     Returns:
///@returns         void
    void setObj(char* bucketId);

// Function: BucketUnlike.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif