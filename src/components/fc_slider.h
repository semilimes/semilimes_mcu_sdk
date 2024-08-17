#ifndef _fc_slider_
#define _fc_slider_

#include "../defines.h"

class FcSlider
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: FcSlider

//     A slider to let the user select a value by dragging its handle

//     Prototype:
//         void FcSlider(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    FcSlider(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: FcSlider.setObj

//     A slider to let the user select a value by dragging its handle

//     Prototype:
//         void FcSlider::setObj(char* refname,char* title,bool reqSel,int value,int min,int max,int step);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the slider
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value - is the value selected on the slider on initializing (sending the form) or submission
///@param         min - is the value selected when slider is at its minimum
///@param         max - is the value selected when slider is at its maximum
///@param         step - s the value amount that sums or subtracts to the initial value at each slider minimum drag

//     Returns:
///@return         void
    void setObj(char* refname,char* title,bool reqSel,int value,int min,int max,int step);
};

#endif