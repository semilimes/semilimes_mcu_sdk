#ifndef _fc_contact_picker_
#define _fc_contact_picker_

#include "../defines.h"

class FcContactPicker
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: FcContactPicker

//     A picker allowing to select and reference contacts

//     Prototype:
//         void FcContactPicker(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    FcContactPicker(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: FcContactPicker.setObj

//     A picker allowing to select and reference contacts

//     Prototype:
//         void FcContactPicker::setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle,bool multiSel);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the picker
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value -  is the chosen contact ids when form is submitted
///@param         actBtnTitle - is the label of the pick button
///@param         multiSel -  is a flag that allows the user to select multiple objects in the UI

//     Returns:
///@return         void
    void setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle,bool multiSel);
};

#endif