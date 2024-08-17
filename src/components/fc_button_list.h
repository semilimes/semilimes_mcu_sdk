#ifndef _fc_button_list_
#define _fc_button_list_

#include "../defines.h"

class FcButtonList
{
private:
    SmeJson json_data;
    char** pjson;
    char** pjsonArray;
    
public:
// Function: FcSingleChoice

//     A group of user-clickable buttons with a label

//     Prototype:
//         void FcMultipleChoice(char* json, char* jsonArray);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 
///@param         jsonArray - it is a temporary char array that will contain the Options 

//     Returns:
///@return         void
    FcButtonList(char* json, char* jsonArray)
    {
        pjson = &json;
        pjsonArray = &jsonArray;
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
        json_data.addPair2JsonStr(*pjson,"formComponentType","buttonlist");
    }

// Function: FcButtonList.setObj

//     Initialize a group of user-clickable buttons with a label

//     Prototype:
//         void FcButtonList::setObj(char* refname,char* title,bool reqSel,char* value,bool vertList);

//     Parameters:
///@param         refname - is the reference name of the button list
///@param         title - is the global label displayed at the beginning of the component
///@param         reqSel - sets this component interaction as required before submitting the parent form
///@param         value - will be populated with a button name when a user submits a form with a button selection
///@param         vertList -  is a preference to tell a client app to display the buttons vertically

//     Returns:
///@return         void
    void setObj(char* refname,char* title,bool reqSel,char* value,bool vertList);

// Function: FcButtonList.addOptions

//     add an array of options where name is the option identifier and value is the text displayed to the user

//     Prototype:
//         void FcButtonList::addOptions(char* data);

//     Parameters:
///@param         name - is the option identifier
///@param         value - text displayed to the user
        
//    Returns:
///@return       void
    void addOptions(char* name,char* value);

// Function: FcButtonList.appendOptions

//     Append the selected options

//     Prototype:
//         void FcButtonList::appendOptions();

//     Parameters:

//     Returns:
///@return         void
    void appendOptions();
};

#endif