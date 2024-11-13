#ifndef _bucket_unlike_
#define _bucket_unlike_

#include "../defines.h"

class BucketUnlike
{
private:
    SmeJson json_data;
    char* json = nullptr;
    
public:

// Function: ~BucketUnlike

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~BucketUnlike()

//     Parameters:

//     Returns:
///@return         void
    ~BucketUnlike()
    {
        delete[] json;
        json = nullptr;
    }

// Function: BucketUnlike.set

//     This endpoint unsets a like by the current account to any referenced bucket that allows likes.

//     Prototype:
//         void set(const char* bucketId);

//     Parameters:
///@param         bucketId -  is the unique Id to reference an existing bucket

//     Returns:
///@returns         void
    void set(const char* bucketId);

// Function: BucketUnlike.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: BucketUnlike.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: BucketUnlike.get

//     return the json script

//     Prototype:
//         void BucketUnlike::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif