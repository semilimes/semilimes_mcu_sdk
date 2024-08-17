#include "fc_bucket_picker.h"

/* Function: FcBucketPicker.setObj

    A picker allowing to select and reference buckets

    Prototype:
        void FcBucketPicker::setObj(char* refname,char* title,bool reqSel, char* filter,char* actBtnTitle,bool multiSel);

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
void FcBucketPicker::setObj(char* refname,char* title,bool reqSel, char* filter,char* actBtnTitle,bool multiSel)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"formComponentType","bucketpicker");
    json_data.addPair2JsonStr(*pjson,"refName",refname);
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonBool(*pjson,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(*pjson,"filter",filter);
    json_data.addPair2JsonStr(*pjson,"actionButtonTitle",actBtnTitle);
    json_data.addPair2JsonBool(*pjson,"multiSelection",multiSel);
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
void FcBucketPicker::addValue(char* value)
{
    json_data.add2JsonStr(*pjsonArray,value);
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
	json_data.add2JsonArray(*pjson,"value",*pjsonArray);
}