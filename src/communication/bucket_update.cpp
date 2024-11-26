#include "bucket_update.h"

/* Function: BucketUpdate.set

    This endpoint allows the user to update the content of a specific bucket.

    Prototype:
        void set(cost char* bucketId);

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
void BucketUpdate::set(const char* bucketId, const char* title, const char* description, const char* avatar, bool visible, bool locked, bool enReactions)
{
    int size = strlen("{\"dataComponentType\":\"bucket\",\"bucketId\":\"\",\"title\":\"\",\"description\":\"\",\"avatar\":\"\",\"visible\":\"\",\"locked\":,\"enReactions\":}")+strlen(bucketId)+strlen(title)+strlen(description)+strlen(avatar)+json_data.boolStrSize(visible)+json_data.boolStrSize(locked)+json_data.boolStrSize(enReactions)+1;//add '\0' for null-termination
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"dataComponentType","bucket");
    json_data.addPair2JsonStr(json,"bucketId",bucketId);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonStr(json,"description",description);
    json_data.addPair2JsonStr(json,"avatar",avatar);
    json_data.addPair2JsonBool(json,"visible",visible);
    json_data.addPair2JsonBool(json,"locked",locked);
    json_data.addPair2JsonBool(json,"enReactions",enReactions);
}

/* Function: BucketUpdate.addDataComponents

    Append the selected components

    Prototype:
        void addDataComponents(cost char* component);

    Parameters:
        component - the json script of the dataComponent to add

    Returns:
        void
*/
void BucketUpdate::addDataComponents(const char* component)
{        
    int size = strlen("[]")+strlen(component)+1;
    
    if(!jsonArray)
    {
        jsonArray = new char[size];
        json_data.initJsonArray(jsonArray);
    }
    else
    {
        size += strlen(jsonArray)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
        json_data.arrayResize(jsonArray,size+1); //add '\0' for null-termination
    }
    json_data.add2Json(jsonArray,component);
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
    if(jsonArray!=nullptr)
    {
        int size = strlen(",\"dataComponents\":")+strlen(json)+strlen(jsonArray)+1;   //add '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"dataComponents",jsonArray);
    }
}

/* Function: BucketUpdate.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* sme_httpsUrl + endpoint
*/
char* BucketUpdate::getEPurl()
{
    return sme_httpsUrl sme_communication_bucket_update;
}

/* Function: BucketUpdate.getWSEPurl

    provides the full url for this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* BucketUpdate::getWSEPurl()
{
    return sme_communication_bucket_update;        
}

/* Function: BucketUpdate.get

    return the json script

    Prototype:
        void BucketUpdate::get();

    Parameters:

    Returns:
        char*
*/
char* BucketUpdate::get()
{
    return json;
}