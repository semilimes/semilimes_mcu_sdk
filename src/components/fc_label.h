#ifndef _fc_label_
#define _fc_label_

#include "../defines.h"

class FcLabel
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: FcLabel

//     A simple read-only label

//     Prototype:
//         void FcLabel(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    FcLabel(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: FcLabel.setObj

//     A simple read-only label

//     Prototype:
//         void FcLabel::setObj(char* refname,char* title);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title -  the label title

//     Returns:
///@return         void
    void setObj(char* refname,char* title);
};

#endif