#ifndef _fc_hidden_value_
#define _fc_hidden_value_

#include "../defines.h"

class FcHiddenValue
{
private:   
    SmeJson json_data;
    char** pjson;
    
public:
// Function: FcHiddenValue

//     A value into the form which is not visible to the use

//     Prototype:
//         void FcHiddenValue(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    FcHiddenValue(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: FcHiddenValue.setObj

//     A value into the form which is not visible to the use

//     Prototype:
//         void FcHiddenValue::setObj(char* refname,char* value);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         value -  the hidden value

//     Returns:
///@return         void
    void setObj(char* refname,char* value);
};

#endif