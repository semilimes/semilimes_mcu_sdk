#ifndef _dc_form_
#define _dc_form_

#include "../defines.h"

class DcForm
{
private:
    #define headerSize 102
    #define headerArraySize 2
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;

public:
// variable: DcForm.featureType

//     describes the types of the feature
///@param        char featureType[3][10] = {"contact","groupchat","channel"};
    char featureType[3][10] = {"contact","groupchat","channel"};

// Function: ~DcForm

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~DcForm()

//     Parameters:

//     Returns:
///@return         void
    ~DcForm()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: DcForm.set

//    A form message is a complex data component which can be arbitrarily structured using available form components

//    Prototype:
//       void DcForm::set(bool submitEnabled, bool retainStatus, char* submitText, char* refName);

//    Parameters:
///@param         recId - the receiver Id
///@param         recFeatureType - the type of the receiver: char* featureType[3][10] = {"contact","groupchat","channel"}
///@param         submitEnabled - enables the Submit button to be pressed before the form is actually submitted. Otherwise, the form will be submitted each time a user fills in/change values of a form component.
///@param         retainStatus - enables the form to maintain the last submitted values when the use case requires many users to operate the same form
///@param         submitText - is the text to be displayed in the Submit button of the form
///@param         refName - is a friendly name given to the form for later reference when filtering form submissions from clients.
//    Returns:
///@return       void
    void set(char* recId, char* recFeatureType, bool submitEnabled, bool retainStatus, char* submitText, char* refName);

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
    

// Function: DcForm.get

//     return the json script

//     Prototype:
//         void DcForm::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif