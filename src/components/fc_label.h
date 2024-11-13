#ifndef _fc_label_
#define _fc_label_

#include "../defines.h"

class FcLabel
{
private:
    SmeJson json_data;
    char* json = nullptr; 

public:
// Function: ~FcLabel

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcLabel()

//     Parameters:

//     Returns:
///@return         void
    ~FcLabel()
    {
        delete[] json;
        json = nullptr;
    }

// Function: FcLabel.set

//     A simple read-only label

//     Prototype:
//         void FcLabel::set(const char* refname,const char* title);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title -  the label title

//     Returns:
///@return         void
    void set(const char* refname,const char* title);

// Function: FcLabel.get

//     return the json script

//     Prototype:
//         void FcLabel::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif