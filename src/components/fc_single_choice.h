#ifndef _fc_single_choice_
#define _fc_single_choice_

#include "../defines.h"

class FcSingleChoice
{
private:
    #define headerSize 92
    #define headerArraySize 24
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;
    
public:
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
//         void FcSingleChoice::set(char* refname,char* title,bool reqSel, char* value);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the global label displayed at the beginning of the component
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value - points to one of the choices name and determines which option is selected on submission

//     Returns:
///@return         void
    void set(char* refname,char* title,bool reqSel, char* value);

// Function: FcSingleChoice.addOptions

//    add an array of options where name is the option identifier and value is the text displayed to the user

//     Prototype:
//         void FcSingleChoice::addOptions(char* name,char* value);

//    Parameters:
///@param         name - is the option identifier
///@param         value - text displayed to the user
        
//    Returns:
///@return       void

    void addOptions(char* name,char* value);

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