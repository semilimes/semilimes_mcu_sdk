#include "dc_form.h"

/* Function: DcForm.setObj

   A form message is a complex data component which can be arbitrarily structured using available form components

   Prototype:
      void DcForm::setObj(bool submitEnabled, bool retainStatus, char* submitText, char* refName);

   Parameters:
        submitEnabled - enables the Submit button to be pressed before the form is actually submitted. Otherwise, the form will be submitted each time a user fills in/change values of a form component.
        retainStatus - enables the form to maintain the last submitted values when the use case requires many users to operate the same form
        submitText - is the text to be displayed in the Submit button of the form
        refName - is a friendly name given to the form for later reference when filtering form submissions from clients.
   Returns:
      void
*/
void DcForm::setObj(bool submitEnabled, bool retainStatus, char* submitText, char* refName)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"dataComponentType","form");
    json_data.addPair2JsonBool(*pjson,"submitEnabled",submitEnabled);
    json_data.addPair2JsonBool(*pjson,"retainStatus",retainStatus);
    json_data.addPair2JsonStr(*pjson,"submitText",submitText);
    json_data.addPair2JsonStr(*pjson,"refName",refName);
}

/* Function: DcForm.addReceiver

   Add a receiver Id to the array

   Prototype:
      void DcForm::addReceiver(char* id, char* featureType);

   Parameters:
        id - the receiver Id to add
        featureType - the type of the receiver: char* featureType[3][10] = {"contact","groupchat","channel"}
   Returns:
      void
*/
void DcForm::addReceiver(char* id, char* featureType)
{  
    char temp[200]="{}\0";
    json_data.addPair2JsonStr(temp,"id",id);
    json_data.addPair2JsonStr(temp,"featureType",featureType);
    json_data.addPair2Json(*pjson,"receiver",temp);
}

/* Function: DcForm.addFormComponents

   Add a Form Component to the array

   Prototype:
      void DcForm::addFormComponents(char* component);

   Parameters:
        component - the json of the form component
        
   Returns:
      void
*/
void DcForm::addFormComponents(char* component)
{    
    json_data.add2Json(*pjsonArray,component);
}

/* Function: DcForm.appendFormComponents

   Append the Form Components to the json message 

   Prototype:
      void DcForm::appendFormComponents();

   Parameters:
   
   Returns:
      void
*/
void DcForm::appendFormComponents()
{
	json_data.add2JsonArray(*pjson,"formComponents",*pjsonArray);
}
