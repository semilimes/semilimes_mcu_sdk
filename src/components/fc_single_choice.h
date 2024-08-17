#ifndef _fc_single_choice_
#define _fc_single_choice_

#include "../defines.h"

class FcSingleChoice
{
private:
    SmeJson json_data;
    char** pjson;
    char** pjsonArray;
    
public:
// Function: FcSingleChoice

//     A component displaying a list of options and allowing only one choice

//     Prototype:
//         void FcMultipleChoice(char* json, char* jsonArray);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 
///@param         jsonArray - it is a temporary char array that will contain the Options 

//     Returns:
///@return         void
    FcSingleChoice(char* json, char* jsonArray)
    {
        pjson = &json;
        pjsonArray = &jsonArray;
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
        json_data.addPair2JsonStr(*pjson,"formComponentType","singlechoice");
    }

// Function: FcSingleChoice.setObj

//     Initialize the component that display a list of options and allowing only one choice

//     Prototype:
//         void FcSingleChoice::setObj(char* refname,char* title,bool reqSel, char* value);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the global label displayed at the beginning of the component
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value - points to one of the choices name and determines which option is selected on submission

//     Returns:
///@return         void
    void setObj(char* refname,char* title,bool reqSel, char* value);

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
};

#endif