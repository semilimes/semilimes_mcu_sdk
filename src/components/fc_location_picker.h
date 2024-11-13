#ifndef _fc_location_picker_
#define _fc_location_picker_

#include "../defines.h"

class FcLocationPicker
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    
public:
// Function: ~FcLocationPicker

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcLocationPicker()

//     Parameters:

//     Returns:
///@return         void
    ~FcLocationPicker()
    {
        delete[] json;
        json = nullptr;
    }

// Function: FcLocationPicker.set

//     A picker showing a map where to choose a location or address

//     Prototype:
//         void FcLocationPicker::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle,bool currLocOnly);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the picker
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value -  is the chosen contact ids when form is submitted
///@param         actBtnTitle - is the label of the pick button
///@param         currLocOnly - 

//     Returns:
///@return         void
    void set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle,bool currLocOnly);
// Function: FcLocationPicker.get

//     return the json script

//     Prototype:
//         void FcLocationPicker::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif