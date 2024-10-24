#ifndef _fc_gauge_
#define _fc_gauge_

#include "../defines.h"

class DcGauge
{
private:
    #define headerSize 184
    #define headerArraySize 27
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

// Function: ~DcGauge

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~DcGauge()

//     Parameters:

//     Returns:
///@return         void
    ~DcGauge()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: DcGauge.set

//     A gauge to show numerical data with a configurable ranges and colors

//     Prototype:
//         void DcGauge::set(char* refname,char* title,bool reqSel, char* value);

//     Parameters:
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
    void set(char* title,int thickness,int degrees,int spacing,int fontSize,int value,char* displayValue,char* pointer,char* pointerColor,char* progressBar,char* progressBarColor);

// Function: DcGauge.addSegment

//    is an array of the graphical segments composing the gauge.

//     Prototype:
//         void DcGauge::addSegment(int from,int to,char* color);

//    Parameters:
///@param         from - between the 0-99 range
///@param         to - between the 1-100 range
///@param         color - defines the RGB color of the pointer, if set. The allowed value is in the #[0-F][0-F][0-F][0-F][0-F][0-F] format
        
//    Returns:
///@return       void

    void addSegment(int from,int to,char* color);

// Function: DcGauge.appendSegments

//     Append the selected Segments

//     Prototype:
//         void DcGauge::appendSegments();

//     Parameters:

//     Returns:
///@return         void
    void appendSegments();

// Function: DcGauge.get

//     return the json script

//     Prototype:
//         void DcGauge::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif