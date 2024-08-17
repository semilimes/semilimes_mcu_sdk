#ifndef _fc_text_box_
#define _fc_text_box_

#include "../defines.h"

class FcTextBox
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: FcTextBox

//     A text field with a title and a user-editable text field.

//     Prototype:
//         void FcTextBox(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    FcTextBox(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: FcTextBox.setObj

//     A text field with a title and a user-editable text field.

//     Prototype:
//         void FcTextBox::setObj(char* refname,char* title,char* value,bool reqSel);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the textbox title
///@param         value - is the text pre-populated in the textbox and the text input by the user at form submission
///@param         reqSel - sets this component interaction as required before submitting the parent form

//     Returns:
///@return         void
    void setObj(char* refname,char* title,char* value,bool reqSel=false);
};

#endif