#ifndef _fc_contact_picker_
#define _fc_contact_picker_

#include "../defines.h"

class FcContactPicker
{
private:
    #define headerSize 134
    SmeJson json_data;
    char* json = nullptr; 
    
public:
// Function: ~FcContactPicker

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcContactPicker()

//     Parameters:

//     Returns:
///@return         void
    ~FcContactPicker()
    {
        delete[] json;
        json = nullptr;
    }

// Function: FcContactPicker.set

//     A picker allowing to select and reference contacts

//     Prototype:
//         void FcContactPicker::set(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle,bool multiSel);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the picker
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value -  is the chosen contact ids when form is submitted
///@param         actBtnTitle - is the label of the pick button
///@param         multiSel -  is a flag that allows the user to select multiple objects in the UI

//     Returns:
///@return         void
    void set(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle,bool multiSel);

// Function: FcContactPicker.get

//     return the json script

//     Prototype:
//         void FcContactPicker::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif