#include "bucket_like.h"

/* Function: BucketLike.setObj

    This endpoint sets a like by the current account to any referenced bucket that allows likes.

    Prototype:
        void setObj(char* bucketId);

    Parameters:
        bucketId -  is the unique Id to reference an existing bucket

    Returns:
        void
*/
void BucketLike::setObj(char* bucketId)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"bucketId",bucketId);
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