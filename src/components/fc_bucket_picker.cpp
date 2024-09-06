#include "fc_bucket_picker.h"

/* Function: FcBucketPicker.set

    A picker allowing to select and reference buckets

    Prototype:
        void FcBucketPicker::set(char* refname,char* title,bool reqSel, char* filter,char* actBtnTitle,bool multiSel);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the picker
        reqSel - indicates if the selection is required to submit the form
        filter - determines what type of bucket one wants the user to pick from. Allowed (multiple) values are: featureTypes[4][10] = {"post", "profile", "groupchat", "channel"};
        actBtnTitle - is the label of the pick button
        multiSel -  is a flag that allows the user to select multiple objects in the UI

    Returns:
        void
*/
void FcBucketPicker::set(char* refname,char* title,bool reqSel, char* filter,char* actBtnTitle,bool multiSel)
{
    int size = headerSize+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+strlen(filter)+strlen(actBtnTitle)+json_data.boolStrSize(multiSel)+1;//add '\0' for null-termination
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","bucketpicker");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"filter",filter);
    json_data.addPair2JsonStr(json,"actionButtonTitle",actBtnTitle);
    json_data.addPair2JsonBool(json,"multiSelection",multiSel);
}

/* Function: FcBucketPicker.addValue

    add a selected bucket id upon form submission. It can be of the following types: char featureTypes[4][10] = {"post", "profile", "groupchat", "channel"};

    Prototype:
        void FcBucketPicker::addValue(char* value);

    Parameters:
        filter - It can be of the following types: 

    Returns:
        void
*/
void FcBucketPicker::addValue(char* id, char* featuretype)
{
    int size = headerArraySize+strlen(id)+strlen(featuretype)+1;
    char* optTemp = new char[size];
    json_data.initJson(optTemp);
    json_data.addPair2JsonStr(optTemp, "id", id);
    json_data.addPair2JsonStr(optTemp, "featureType", featuretype);
    
    if(!jsonArray)
    {
        jsonArray = new char[size+1];
        json_data.initJsonArray(jsonArray);
    }
    else
    {
        size += strlen(jsonArray)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
        json_data.arrayResize(jsonArray,size+1); //add '\0' for null-termination
    }
    json_data.add2Json(jsonArray,optTemp);
}

/* Function: FcBucketPicker.appendValue

    Append the selected buckets

    Prototype:
        void FcBucketPicker::appendValue();

    Parameters:

    Returns:
        void
*/
void FcBucketPicker::appendValue()
{
    int size = strlen(json)+strlen(jsonArray)+10;   //add ',"value":' and '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"value",jsonArray);
}

/* Function: FcBucketPicker.get

    return the json script

    Prototype:
        void FcBucketPicker::get();

    Parameters:

    Returns:
        char*
*/
char* FcBucketPicker::get()
{
    return json;
}
