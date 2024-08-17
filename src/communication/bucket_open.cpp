#include "bucket_open.h"

/* Function: BucketOpen.setObj

    This endpoint let the user access the bucket content by its bucketId.

    Prototype:
        void setObj(char* bucketId);

    Parameters:
        bucketId -  is the unique Id to reference an existing bucket

    Returns:
        void
*/
void BucketOpen::setObj(char* bucketId)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"bucketId",bucketId);
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