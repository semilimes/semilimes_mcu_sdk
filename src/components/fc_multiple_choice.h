#ifndef _fc_multiple_choice_
#define _fc_multiple_choice_

#include "../defines.h"

class FcMultipleChoice
{
private:
    SmeJson json_data;
    char** pjson;
    char** pjsonArray;
    char** pjsonArray2;
    
public:
// Function: FcMultipleChoice

//     A component displaying a list of options and allowing multiple choice

//     Prototype:
//         void FcMultipleChoice(char* json, char* jsonArray, char* jsonArray2);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 
///@param         jsonArray - it is a temporary char array that will contain the Options 
///@param         jsonArray2 - it is a temporary char array that will contain the Values

//     Returns:
///@return         void
    FcMultipleChoice(char* json, char* jsonArray, char* jsonArray2)
    {
        pjson = &json;
        pjsonArray = &jsonArray;
        pjsonArray2 = &jsonArray2;
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
        json_data.initJsonArray(*pjsonArray2);
    }

// Function: FcMultipleChoice.setObj

//     Init the component that display a list of options and allowing multiple choice

//     Prototype:
//         void FcMultipleChoice::setObj(char* refname,char* title,bool reqSel);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the global label displayed at the beginning of the component
///@param         reqSel - indicates if the selection is required to submit the form

//     Returns:
///@return         void
    void setObj(char* refname,char* title,bool reqSel);

// Function: FcMultipleChoice.addOptions

//     add an array of options where name is the option identifier and value is the text displayed to the user

//     Prototype:
//         void FcMultipleChoice::addOptions(char* data);

//     Parameters:
///@param         name - is the option identifier
///@param         value - text displayed to the user
        
//    Returns:
///@return       void
    void addOptions(char* name,char* value);

// Function: FcMultipleChoice.appendOptions

//     Prototype:
//         void FcMultipleChoice::appendOptions();

//     Append the selected options

///@param     Parameters:

//     Returns:
///@return         void
    void appendOptions();

// Function: FcMultipleChoice.addValues

//     add an array of the names of the choices 

//     Prototype:
//         void FcMultipleChoice::addValues(char* value);

//     Parameters:
///@param         value - is an array containing the names of the choices that are selected on submission: {"name" : "choice1","value": "Choice 1"}

//     Returns:
///@return         void
    void addValues(char* value);


// Function: FcMultipleChoice.appendValues

//     Append the selected options

//     Prototype:
///@param        void FcMultipleChoice::appendValues()

//     Parameters:

//     Returns:
///@return         void
    void appendValues();
};

#endif