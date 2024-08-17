#include "bucket_update.h"

/* Function: BucketUpdate.setObj

    This endpoint allows the user to update the content of a specific bucket.

    Prototype:
        void setObj(char* bucketId);

    Parameters:
        bucketId -  is the unique Id to reference an existing bucket
        title - sets the bucket title
        description - sets the bucket description
        avatar -  takes a fileId (obtained by a File Upload endpoint) and sets the main avatar image of the bucket
        visible - sets the bucket general visibility. If set to false, the bucket will be only visible to its creator
        locked - sets the bucket’s general edit permissions. If set to true, its content cannot be interacted by other users
        enReactions - allows other users to post reactions (e.g. likes) to bucket’s content

    Returns:
        void
*/
void BucketUpdate::setObj(char* bucketId, char* title, char* description, char* avatar, bool visible, bool locked, bool enReactions)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"bucketId",bucketId);
    json_data.addPair2JsonStr(*pjson,"dataComponentType","bucket");
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonStr(*pjson,"description",description);
    json_data.addPair2JsonStr(*pjson,"avatar",avatar);
    json_data.addPair2JsonBool(*pjson,"visible",visible);
    json_data.addPair2JsonBool(*pjson,"locked",locked);
    json_data.addPair2JsonBool(*pjson,"enReactions",enReactions);
}

/* Function: BucketUpdate.addDataComponents

    Append the selected components

    Prototype:
        void addDataComponents(char* component);

    Parameters:
        component - the json script of the dataComponent to add

    Returns:
        void
*/
void BucketUpdate::addDataComponents(char* component)
{    
    json_data.add2Json(*pjsonArray,component);
}

/* Function: BucketUpdate.appendDataComponents

    Append the selected dataComponents

    Prototype:
        void appendDataComponents();

    Parameters:

    Returns:
        void
*/
void BucketUpdate::appendDataComponents()
{
	json_data.add2JsonArray(*pjson,"dataComponents",*pjsonArray);
}

/* Function: BucketUpdate.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* BucketUpdate::getEPurl()
{
    return httpsUrl communication_bucket_update;
}