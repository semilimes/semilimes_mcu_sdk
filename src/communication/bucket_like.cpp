#include "bucket_like.h"

/* Function: BucketLike.set

    This endpoint sets a like by the current account to any referenced bucket that allows likes.

    Prototype:
        void set(char* bucketId);

    Parameters:
        bucketId -  is the unique Id to reference an existing bucket

    Returns:
        void
*/
void BucketLike::set(char* bucketId)
{
    int size = headerSize+strlen(bucketId)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"bucketId",bucketId);
}

/* Function: BucketLike.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* BucketLike::getEPurl()
{
    return httpsUrl communication_bucket_like;        
}

/* Function: BucketLike.get

    return the json script

    Prototype:
        void BucketLike::get();

    Parameters:

    Returns:
        char*
*/
char* BucketLike::get()
{
    return json;
}