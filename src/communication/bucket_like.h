#ifndef _bucket_like_
#define _bucket_like_

#include "../defines.h"

class BucketLike
{
private:
    #define headerSize 15
    SmeJson json_data;
    char* json = nullptr;
    
public:

// Function: ~BucketLike

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~BucketLike()

//     Parameters:

//     Returns:
///@return         void
    ~BucketLike()
    {
        delete[] json;
        json = nullptr;
    }

// Function: BucketLike.set

//     This endpoint sets a like by the current account to any referenced bucket that allows likes.

//     Prototype:
//         void set(char* bucketId);

//     Parameters:
///@param         bucketId -  is the unique Id to reference an existing bucket

//     Returns:
///@returns         void
    void set(char* bucketId);

// Function: BucketLike.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    

// Function: BucketLike.get

//     return the json script

//     Prototype:
//         void BucketLike::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif