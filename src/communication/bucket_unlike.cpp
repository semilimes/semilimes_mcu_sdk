#include "bucket_unlike.h"

/* Function: BucketUnlike.setObj

    This endpoint unsets a like by the current account to any referenced bucket that allows likes.

    Prototype:
        void setObj(char* bucketId);

    Parameters:
        bucketId -  is the unique Id to reference an existing bucket

    Returns:
        void
*/
void BucketUnlike::set(char* bucketId)
{
    int size = headerSize+strlen(bucketId)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"bucketId",bucketId);
}

/* Function: BucketUnlike.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* BucketUnlike::getEPurl()
{
    return httpsUrl communication_bucket_unlike;        
}

/* Function: BucketUnlike.get

    return the json script

    Prototype:
        void BucketUnlike::get();

    Parameters:

    Returns:
        char*
*/
char* BucketUnlike::get()
{
    return json;
}