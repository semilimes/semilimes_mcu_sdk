#include "bucket_open.h"

/* Function: BucketOpen.set

    This endpoint let the user access the bucket content by its bucketId.

    Prototype:
        void set(char* bucketId);

    Parameters:
        bucketId -  is the unique Id to reference an existing bucket

    Returns:
        void
*/
void BucketOpen::set(char* bucketId)
{
    int size = headerSize+strlen(bucketId)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"bucketId",bucketId);
}

/* Function: BucketOpen.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* BucketOpen::getEPurl()
{
    return httpsUrl communication_bucket;        
}

/* Function: BucketOpen.get

    return the json script

    Prototype:
        void BucketOpen::get();

    Parameters:

    Returns:
        char*
*/
char* BucketOpen::get()
{
    return json;
}