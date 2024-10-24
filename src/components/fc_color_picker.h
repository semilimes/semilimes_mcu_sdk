#ifndef _fc_color_picker_
#define _fc_color_picker_

#include "../defines.h"

class FcColorPicker
{
private:
    #define headerSize 114
    SmeJson json_data;
    char* json = nullptr; 
    
public:
// Function: ~FcColorPicker

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcColorPicker()

//     Parameters:

//     Returns:
///@return         void
    ~FcColorPicker()
    {
        delete[] json;
        json = nullptr;
    }

// Function: FcColorPicker.set

//     A graphical color-picker to select a color from a palette and return its RGB value

//     Prototype:
//         void FcColorPicker::set(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the picker
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value -  is the chosen contact ids when form is submitted
///@param         actBtnTitle - is the label of the pick button

//     Returns:
///@return         void
    void set(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle);

// Function: FcColorPicker.get

//     return the json script

//     Prototype:
//         void FcColorPicker::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif