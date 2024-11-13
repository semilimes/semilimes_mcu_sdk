#ifndef _fc_multiple_choice_
#define _fc_multiple_choice_

#include "../defines.h"

class FcMultipleChoice
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;
    char* jsonArray2 = nullptr;
    
public:
// Function: ~FcMultipleChoice

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcMultipleChoice()

//     Parameters:

//     Returns:
///@return         void
    ~FcMultipleChoice()
    {
        delete[] json;
        delete[] jsonArray;
        delete[] jsonArray2;
        json = nullptr;
        jsonArray = nullptr;
        jsonArray2 = nullptr;
    }

// Function: FcMultipleChoice.set

//     Init the component that display a list of options and allowing multiple choice

//     Prototype:
//         void FcMultipleChoice::set(const char* refname,const char* title,bool reqSel);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the global label displayed at the beginning of the component
///@param         reqSel - indicates if the selection is required to submit the form

//     Returns:
///@return         void
    void set(const char* refname,const char* title,bool reqSel);

// Function: FcMultipleChoice.addOptions

//     add an array of options where name is the option identifier and value is the text displayed to the user

//     Prototype:
//         void FcMultipleChoice::ddOptions(const char* name,const char* value);

//     Parameters:
///@param         name - is the option identifier
///@param         value - text displayed to the user
        
//    Returns:
///@return       void
    void addOptions(const char* name,const char* value);

// Function: FcMultipleChoice.appendOptions

//     Prototype:
//         void FcMultipleChoice::appendOptions();

//     Append the selected options

///@param     Parameters:

//     Returns:
///@return         void
    void appendOptions();

// Function: FcMultipleChoice.addValue

//     add an array of the names of the choices 

//     Prototype:
//         void FcMultipleChoice::addValue(char* value);

//     Parameters:
///@param         value - is an array containing the names of the choices that are selected on submission: {"name" : "choice1","value": "Choice 1"}

//     Returns:
///@return         void
    void addValue(char* value);


// Function: FcMultipleChoice.appendValues

//     Append the selected options

//     Prototype:
///@param        void FcMultipleChoice::appendValues()

//     Parameters:

//     Returns:
///@return         void
    void appendValues();
    

// Function: FcMultipleChoice.get

//     return the json script

//     Prototype:
//         void FcMultipleChoice::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif