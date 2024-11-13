#ifndef _fc_gauge_
#define _fc_gauge_

#include "../defines.h"

class FcGauge
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;
    
public:
//      shows a moving indicator on the gauge, depending on the value
///@param        char pointer[4][9] = {"none","triangle","circle","needle"};
    char pointer[4][9] = {"none", "triangle", "circle", "needle"};

//      shows a progress bar moving on the arch of the gauge, depending on the value
///@param        char progressBar[3][8] = {"none", "basic", "rounded"};
    char progressBar[3][8] = {"none", "basic", "rounded"};

// Function: ~FcGauge

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcGauge()

//     Parameters:

//     Returns:
///@return         void
    ~FcGauge()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: FcGauge.set

//     A gauge to show numerical data with a configurable ranges and colors

//     Prototype:
//         void FcGauge::set(const char* refname,const char* title,int thickness,int degrees,int spacing,int fontSize,int value,const char* displayValue,const char* pointer,const char* pointerColor,const char* progressBar,const char* progressBarColor);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the global label displayed at the beginning of the component
///@param         thickness - controls thickness of the gauge segments. Allowed values: 10-100
///@param         degrees - specifies the angular space the gauge will be using. Allowed values: 30-360
///@param         spacing - specifies the separation distance between segments. Allowed values: 0-20
///@param         fontSize - determines the size of the displayValue near to the gauge. Allowed values: 8-48
///@param         value - is the normalized value to control the gauge. Allowed values: 0-100
///@param         displayValue - is a free field to show the actual value, or the actual value + unit of measure, or just a custom text
///@param         pointer - shows a moving indicator on the gauge, depending on the value, and must have one of the following values: char pointer[4][9] = {"none", "triangle", "circle", "needle"};
///@param         pointerColor - defines the RGB color of the pointer, if set. The allowed value is in the #[0-F][0-F][0-F][0-F][0-F][0-F] format
///@param         progressBar - shows a progress bar moving on the arch of the gauge, depending on the value, and must have one of the following values: char progressBar[3][8] = {"none", "basic", "rounded"};
///@param         progressBarColor - defines the RGB color of the progress bar, if set. The allowed value is in the #[0-F][0-F][0-F][0-F][0-F][0-F] format

//     Returns:
///@return         void
    void set(const char* refname,const char* title,int thickness,int degrees,int spacing,int fontSize,int value,const char* displayValue,const char* pointer,const char* pointerColor,const char* progressBar,const char* progressBarColor);

// Function: FcGauge.addSegment

//    is an array of the graphical segments composing the gauge.

//     Prototype:
//         void FcGauge::addSegment(int from,int to,const char* color);

//    Parameters:
///@param         from - between the 0-99 range
///@param         to - between the 1-100 range
///@param         color - defines the RGB color of the pointer, if set. The allowed value is in the #[0-F][0-F][0-F][0-F][0-F][0-F] format
        
//    Returns:
///@return       void

    void addSegment(int from,int to,const char* color);

// Function: FcGauge.appendSegments

//     Append the selected Segments

//     Prototype:
//         void FcGauge::appendSegments();

//     Parameters:

//     Returns:
///@return         void
    void appendSegments();

// Function: FcGauge.get

//     return the json script

//     Prototype:
//         void FcGauge::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif