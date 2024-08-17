#ifndef _bucket_open_
#define _bucket_open_

#include "../defines.h"

class BucketOpen
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: BucketOpen

//     This endpoint let the user access the bucket content by its bucketId.

//     Prototype:
//         void BucketOpen(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    BucketOpen(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: BucketOpen.setObj

//     This endpoint let the user access the bucket content by its bucketId.

//     Prototype:
///@param         void setObj(char* bucketId);

//     Parameters:
//         bucketId -  is the unique Id to reference an existing bucket

//     Returns:
///@returns        void
    void setObj(char* bucketId);

// Function: BucketOpen.getEPurl

//     provides the full url for this endpoint

//     Prototype:
///@param         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint

    char* getEPurl();
};

#endif