#ifndef _fc_text_box_
#define _fc_text_box_

#include "../defines.h"

class FcTextBox
{
private:
    #define headerSize 87
    SmeJson json_data;
    char* json = nullptr; 
    
public:
// Function: ~FcTextBox

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcTextBox()

//     Parameters:

//     Returns:
///@return         void
    ~FcTextBox()
    {
        delete[] json;
        json = nullptr;
    }

// Function: FcTextBox.set

//     A text field with a title and a user-editable text field.

//     Prototype:
//         void FcTextBox::set(char* refname,char* title,char* value,bool reqSel);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the textbox title
///@param         value - is the text pre-populated in the textbox and the text input by the user at form submission
///@param         reqSel - sets this component interaction as required before submitting the parent form

//     Returns:
///@return         void
    void set(char* refname,char* title,char* value,bool reqSel=false);

// Function: FcTextBox.get

//     return the json script

//     Prototype:
//         void FcTextBox::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif