#ifndef _fc_bucket_picker_
#define _fc_bucket_picker_

#include "../defines.h"

class FcBucketPicker
{
private:
    SmeJson json_data;
    char** pjson;
    char** pjsonArray;
    
public:
// Function: FcBucketPicker

//     A picker allowing to select and reference buckets

//     Prototype:
//         void FcBucketPicker(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 
///@param         jsonArray - it is a temporary char array that will contain the Values 

//     Returns:
///@return         void
    FcBucketPicker(char* json, char* jsonArray)
    {
        pjson = &json;
        pjsonArray = &jsonArray;
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
        json_data.addPair2JsonStr(*pjson,"formComponentType","bucketpicker");
    }
    char featureTypes[4][10] = {"post", "profile", "groupchat", "channel"};

// Function: FcBucketPicker.setObj

//     A picker allowing to select and reference buckets

//     Prototype:
//         void FcBucketPicker::setObj(char* refname,char* title,bool reqSel, char* filter,char* actBtnTitle,bool multiSel);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the picker
///@param         reqSel - indicates if the selection is required to submit the form
///@param         filter - determines what type of bucket one wants the user to pick from. Allowed (multiple) values are: featureTypes[4][10] = {"post", "profile", "groupchat", "channel"};
///@param         actBtnTitle - is the label of the pick button
///@param         multiSel -  is a flag that allows the user to select multiple objects in the UI

//     Returns:
///@return         void
    void setObj(char* refname,char* title,bool reqSel, char* filter,char* actBtnTitle,bool multiSel);

// Function: FcBucketPicker.addValue

//     add a selected bucket id upon form submission. It can be of the following types: char featureTypes[4][10] = {"post", "profile", "groupchat", "channel"};

//     Prototype:
//         void FcBucketPicker::addValue(char* value);

//     Parameters:
///@param         value - It can be of the following types: char featureTypes[4][10] = {"post", "profile", "groupchat", "channel"}; 

//     Returns:
///@return         void
    void addValue(char* value);

// Function: FcBucketPicker.appendValue

//     Append the selected buckets

//     Prototype:
//         void FcBucketPicker::appendValue();

//     Parameters:

//     Returns:
///@return         void
    void appendValue();
};

#endif