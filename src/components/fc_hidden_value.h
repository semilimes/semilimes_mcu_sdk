#ifndef _fc_hidden_value_
#define _fc_hidden_value_

#include "../defines.h"

class FcHiddenValue
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    
public:
// Function: ~FcHiddenValue

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcHiddenValue()

//     Parameters:

//     Returns:
///@return         void
    ~FcHiddenValue()
    {
        delete[] json;
        json = nullptr;
    }

// Function: FcHiddenValue.set

//     A value into the form which is not visible to the use

//     Prototype:
//         void FcHiddenValue::set(const char* refname,const char* value);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         value -  the hidden value

//     Returns:
///@return         void
    void set(const char* refname,const char* value);

// Function: FcHiddenValue.get

//     return the json script

//     Prototype:
//         void FcHiddenValue::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif