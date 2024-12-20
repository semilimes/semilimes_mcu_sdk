#ifndef _bucket_open_
#define _bucket_open_

#include "../defines.h"

class BucketOpen
{
private:
    SmeJson json_data;
    char* json = nullptr;
    
public:

// Function: ~BucketOpen

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~BucketOpen()

//     Parameters:

//     Returns:
///@return         void
    ~BucketOpen()
    {
        delete[] json;
        json = nullptr;
    }

// Function: BucketOpen.set

//     This endpoint let the user access the bucket content by its bucketId.

//     Prototype:
///@param         void set(const char* bucketId);

//     Parameters:
//         bucketId -  is the unique Id to reference an existing bucket

//     Returns:
///@returns        void
    void set(const char* bucketId);

// Function: BucketOpen.getEPurl

//     provides the full url for this endpoint

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
    
// Function: BucketOpen.get

//     return the json script

//     Prototype:
//         void BucketOpen::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif