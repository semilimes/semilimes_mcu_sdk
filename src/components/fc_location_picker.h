#ifndef _fc_location_picker_
#define _fc_location_picker_

#include "../defines.h"

class FcLocationPicker
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: FcLocationPicker

//     A picker showing a map where to choose a location or address

//     Prototype:
//         void FcLocationPicker(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    FcLocationPicker(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: FcLocationPicker.setObj

//     A picker showing a map where to choose a location or address

//     Prototype:
//         void FcLocationPicker::setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle,bool currLocOnly);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the picker
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value -  is the chosen contact ids when form is submitted
///@param         actBtnTitle - is the label of the pick button
///@param         currLocOnly - 

//     Returns:
///@return         void
    void setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle,bool currLocOnly);
};

#endif