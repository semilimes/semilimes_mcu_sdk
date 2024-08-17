#ifndef _fc_date_picker_
#define _fc_date_picker_

#include "../defines.h"

class FcDatePicker
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: FcDatePicker

//     A graphical date-picker to select a date from a calendar

//     Prototype:
//         void FcDatePicker(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    FcDatePicker(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: FcDatePicker.setObj

//     A graphical date-picker to select a date from a calendar

//     Prototype:
//         void FcDatePicker::setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the picker
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value -  is the chosen contact ids when form is submitted
///@param         actBtnTitle - is the label of the pick button

//     Returns:
///@return         void
    void setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle);
};

#endif