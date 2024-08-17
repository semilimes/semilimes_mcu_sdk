#ifndef _dc_form_
#define _dc_form_

#include "../defines.h"

class DcForm
{
private:
    SmeJson json_data;
    char** pjson;
    char** pjsonArray;

public:
// Function: DcForm

//     A form message is a complex data component which can be arbitrarily structured using available form components

//     Prototype:
//         void DcForm(char* json, char* jsonArray);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 
///@param         jsonArray - it is a temporary char array that will contain the Form Components 

//     Returns:
///@return         void
    DcForm(char* json, char* jsonArray)
    {
        pjson = &json;
        pjsonArray = &jsonArray;
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
        json_data.addPair2JsonStr(*pjson,"dataComponentType","form");
    }
    char featureType[3][10] = {"contact","groupchat","channel"};

// Function: DcForm.setObj

//    A form message is a complex data component which can be arbitrarily structured using available form components

//    Prototype:
//       void DcForm::setObj(bool submitEnabled, bool retainStatus, char* submitText, char* refName);

//    Parameters:
///@param         submitEnabled - enables the Submit button to be pressed before the form is actually submitted. Otherwise, the form will be submitted each time a user fills in/change values of a form component.
///@param         retainStatus - enables the form to maintain the last submitted values when the use case requires many users to operate the same form
///@param         submitText - is the text to be displayed in the Submit button of the form
///@param         refName - is a friendly name given to the form for later reference when filtering form submissions from clients.
//    Returns:
///@return       void
    void setObj(bool submitEnabled, bool retainStatus, char* submitText, char* refName);

// Function: DcForm.addReceiver

//    Add a receiver Id to the array

//    Prototype:
//       void DcForm::addReceiver(char* id, char* featureType);

//    Parameters:
///@param         id - the receiver Id to add
///@param         featureType - the type of the receiver: char* featureType[3][10] = {"contact","groupchat","channel"}
//    Returns:
///@return       void
    void addReceiver(char* id, char* featureType);

// Function: DcForm.addFormComponents

//    Add a Form Component to the array

//    Prototype:
//       void DcForm::addFormComponents(char* component);

//    Parameters:
///@param         component - the json of the form component
        
//    Returns:
///@return       void
    void addFormComponents(char* component);

// Function: DcForm.appendFormComponents

//    Append the Form Components to the json message 

//    Prototype:
//       void DcForm::appendFormComponents();

//    Parameters:
   
//    Returns:
///@return       void
    void appendFormComponents();
};

#endif