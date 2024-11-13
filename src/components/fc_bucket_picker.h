#ifndef _fc_bucket_picker_
#define _fc_bucket_picker_

#include "../defines.h"

class FcBucketPicker
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;
    
public:
// variable: FcBucketPicker.featureTypes

//     describes the type of the feature
///@param        char featureTypes[4][10] = {"post", "profile", "groupchat", "channel"};
    char featureTypes[4][10] = {"post", "profile", "groupchat", "channel"};
// Function: ~FcBucketPicker

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcBucketPicker()

//     Parameters:

//     Returns:
///@return         void
    ~FcBucketPicker()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: FcBucketPicker.set

//     A picker allowing to select and reference buckets

//     Prototype:
//         void FcBucketPicker::set(const char* refname,const char* title,bool reqSel, const char* filter,const char* actBtnTitle,bool multiSel);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the picker
///@param         reqSel - indicates if the selection is required to submit the form
///@param         filter - determines what type of bucket one wants the user to pick from. Allowed (multiple) values are: featureTypes[4][10] = {"post", "profile", "groupchat", "channel"};
///@param         actBtnTitle - is the label of the pick button
///@param         multiSel -  is a flag that allows the user to select multiple objects in the UI

//     Returns:
///@return         void
    void set(const char* refname,const char* title,bool reqSel, const char* filter,const char* actBtnTitle,bool multiSel);

// Function: FcBucketPicker.addValue

//     add a selected bucket id upon form submission. It can be of the following types: char featureTypes[4][10] = {"post", "profile", "groupchat", "channel"};

//     Prototype:
//         void FcBucketPicker::addValue(const char* value, const char* featuretype);

//     Parameters:
///@param         id - it is the id of the bucket
///@param         featuretype - It can be of the following types: char featureTypes[4][10] = {"post", "profile", "groupchat", "channel"}; 

//     Returns:
///@return         void
    void addValue(const char* id, const char* featuretype);

// Function: FcBucketPicker.appendValue

//     Append the selected buckets

//     Prototype:
//         void FcBucketPicker::appendValue();

//     Parameters:

//     Returns:
///@return         void
    void appendValue();
    

// Function: FcBucketPicker.get

//     return the json script

//     Prototype:
//         void FcBucketPicker::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif