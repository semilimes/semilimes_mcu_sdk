#ifndef _fc_switch_
#define _fc_switch_

#include "../defines.h"

class FcSwitch
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    
public:
// Function: ~FcSwitch

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcSwitch()

//     Parameters:

//     Returns:
///@return         void
    ~FcSwitch()
    {
        delete[] json;
        json = nullptr;
    }

// Function: FcSwitch.set

//     An on/off switch

//     Prototype:
//         void FcSwitch::set(const char* refname,const char* title,bool value);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the switch
///@param         value - is the default value of the switch when creating and the selected value when submitting

//     Returns:
///@return         void

    void set(const char* refname,const char* title,bool value);

// Function: FcSwitch.get

//     return the json script

//     Prototype:
//         void FcSwitch::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif