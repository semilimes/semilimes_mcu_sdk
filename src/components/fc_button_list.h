#ifndef _fc_button_list_
#define _fc_button_list_

#include "../defines.h"

class FcButtonList
{
private:
    #define headerSize 106
    #define headerArraySize 24
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;
    
public:
// Function: ~FcButtonList

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcButtonList()

//     Parameters:

//     Returns:
///@return         void
    ~FcButtonList()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: FcButtonList.set

//     Initialize a group of user-clickable buttons with a label

//     Prototype:
//         void FcButtonList::set(char* refname,char* title,bool reqSel,char* value,bool vertList);

//     Parameters:
///@param         refname - is the reference name of the button list
///@param         title - is the global label displayed at the beginning of the component
///@param         reqSel - sets this component interaction as required before submitting the parent form
///@param         value - will be populated with a button name when a user submits a form with a button selection
///@param         vertList -  is a preference to tell a client app to display the buttons vertically

//     Returns:
///@return         void
    void set(char* refname,char* title,bool reqSel,char* value,bool vertList);

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
    
// Function: FcButtonList.get

//     return the json script

//     Prototype:
//         void FcButtonList::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif