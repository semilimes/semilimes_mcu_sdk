#ifndef _fc_date_picker_
#define _fc_date_picker_

#include "../defines.h"

class FcDatePicker
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    
public:
// Function: ~FcDatePicker

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcDatePicker()

//     Parameters:

//     Returns:
///@return         void
    ~FcDatePicker()
    {
        delete[] json;
        json = nullptr;
    }

// Function: FcDatePicker.set

//     A graphical date-picker to select a date from a calendar

//     Prototype:
//         void FcDatePicker::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the picker
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value -  is the chosen date when form is submitted
///@param         actBtnTitle - is the label of the pick button

//     Returns:
///@return         void
    void set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle);

// Function: FcDatePicker.get

//     return the json script

//     Prototype:
//         void FcDatePicker::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif