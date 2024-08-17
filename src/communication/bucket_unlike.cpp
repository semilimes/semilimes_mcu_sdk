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
void BucketUnlike::setObj(char* bucketId)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"bucketId",bucketId);
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