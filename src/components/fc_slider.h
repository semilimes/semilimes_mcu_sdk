#ifndef _fc_slider_
#define _fc_slider_

#include "../defines.h"

class FcSlider
{
private:
    #define headerSize 106
    SmeJson json_data;
    char* json = nullptr;
    
public:
// Function: ~FcSlider

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcSlider()

//     Parameters:

//     Returns:
///@return         void
    ~FcSlider()
    {
        delete[] json;
        json = nullptr;
    }

// Function: FcSlider.set

//     A slider to let the user select a value by dragging its handle

//     Prototype:
//         void FcSlider::set(char* refname,char* title,bool reqSel,int value,int min,int max,int step);

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
    void set(char* refname,char* title,bool reqSel,int value,int min,int max,int step);

// Function: FcSlider.get

//     return the json script

//     Prototype:
//         void FcSlider::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif