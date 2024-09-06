#ifndef _fc_time_picker_
#define _fc_time_picker_

#include "../defines.h"

class FcTimePicker
{
private:
    #define headerSize 113
    SmeJson json_data;
    char* json = nullptr; 
    
public:
// Function: ~FcTimePicker

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcTimePicker()

//     Parameters:

//     Returns:
///@return         void
    ~FcTimePicker()
    {
        delete[] json;
        json = nullptr;
    }

// Function: FcTimePicker.set

//     A graphical time-picker to select a date from a calendar

//     Prototype:
//         void FcTimePicker::set(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the picker
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value -  is the chosen contact ids when form is submitted
///@param         actBtnTitle - is the label of the pick button

//     Returns:
///@return         void
    void set(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle);

// Function: FcTimePicker.get

//     return the json script

//     Prototype:
//         void FcTimePicker::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif