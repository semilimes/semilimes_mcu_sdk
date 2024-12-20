#ifndef _fc_single_choice_
#define _fc_single_choice_

#include "../defines.h"

class FcSingleChoice
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;
    
public:
//      indicates if the choice should be displayed as a radio list or a dropdown control.
///@param        char mode[2][9] = {"list", "dropdown"};
    char mode[2][9] = {"list", "dropdown"};

// Function: ~FcSingleChoice

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcSingleChoice()

//     Parameters:

//     Returns:
///@return         void
    ~FcSingleChoice()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: FcSingleChoice.set

//     Initialize the component that display a list of options and allowing only one choice

//     Prototype:
//         void FcSingleChoice::set(const char* refname,const char* title,bool reqSel, const char* mode, const char* value);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the global label displayed at the beginning of the component
///@param         reqSel - indicates if the selection is required to submit the form
///@param         mode - indicates if the choice should be displayed as a radio list or a dropdown control. char mode[2][9] = {"list", "dropdown"};
///@param         value - points to one of the choices name and determines which option is selected on submission

//     Returns:
///@return         void
    void set(const char* refname,const char* title,bool reqSel, const char* mode, const char* value);

// Function: FcSingleChoice.addOptions

//    add an array of options where name is the option identifier and value is the text displayed to the user

//     Prototype:
//         void FcSingleChoice::ddOptions(const char* name,const char* value);

//    Parameters:
///@param         name - is the option identifier
///@param         value - text displayed to the user
        
//    Returns:
///@return       void

    void addOptions(const char* name,const char* value);

// Function: FcSingleChoice.appendOptions

//     Append the selected options

//     Prototype:
//         void FcSingleChoice::appendOptions();

//     Parameters:

//     Returns:
///@return         void
    void appendOptions();

// Function: FcSingleChoice.get

//     return the json script

//     Prototype:
//         void FcSingleChoice::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif