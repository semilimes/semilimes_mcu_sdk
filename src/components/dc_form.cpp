#include "dc_form.h"

/* Function: DcForm.set

   A form message is a complex data component which can be arbitrarily structured using available form components

   Prototype:
      void DcForm::set(bool submitEnabled, bool retainStatus, char* submitText, char* refName);

   Parameters:
        id - the receiver Id to add
        featureType - the type of the receiver: char* featureType[3][10] = {"contact","groupchat","channel"}
        submitEnabled - enables the Submit button to be pressed before the form is actually submitted. Otherwise, the form will be submitted each time a user fills in/change values of a form component.
        retainStatus - enables the form to maintain the last submitted values when the use case requires many users to operate the same form
        submitText - is the text to be displayed in the Submit button of the form
        refName - is a friendly name given to the form for later reference when filtering form submissions from clients.
        align - allows to align all the children form components to a direction. Allowed values: align[3][7] = {"left","center","right"};
        authorizeSubmit - allows to protect the in-app submission of the form by a pin code or biometrics, whatever is set in the messenger app.
        hideSubmissionMsg - is a boolean to suppress in-app submission messages sent to receiver, while the API will still receive a submission for further processing
   Returns:
      void
*/
void DcForm::set(char* recId, char* recFeatureType, bool submitEnabled, bool retainStatus, char* submitText, char* refName, char* align, bool authorizeSubmit, bool hideSubmissionMsg)
{
   int size = 27+strlen(recId)+strlen(recFeatureType)+1;//add '{"id":"","featureType":""}\0' with null-termination
   char* recjson = new char[size]; 

   json_data.initJson(recjson);
   json_data.addPair2JsonStr(recjson,"id",recId);
   json_data.addPair2JsonStr(recjson,"featureType",recFeatureType);

   size += headerSize+json_data.boolStrSize(submitEnabled)+strlen(align)+json_data.boolStrSize(authorizeSubmit)+json_data.boolStrSize(retainStatus)+strlen(submitText)+json_data.boolStrSize(hideSubmissionMsg)+strlen(refName)+13; //add ',"receiver":' and '\0' for null-termination
   json = new char[size]; 

   json_data.initJson(json);
   json_data.addPair2JsonStr(json,"dataComponentType","form");
   json_data.addPair2JsonBool(json,"submitEnabled",submitEnabled);
   json_data.addPair2JsonStr(json,"align",align);
   json_data.addPair2JsonBool(json,"authorizeSubmit",authorizeSubmit);
   json_data.addPair2JsonBool(json,"retainStatus",retainStatus);
   json_data.addPair2JsonStr(json,"submitText",submitText);
   json_data.addPair2Json(json,"receiver",recjson);
   json_data.addPair2JsonBool(json,"hideSubmissionMsg",hideSubmissionMsg);
   json_data.addPair2JsonStr(json,"refName",refName);    
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
    int size = headerArraySize+strlen(component)+1;
    
    if(!jsonArray)
    {
        jsonArray = new char[size];
        json_data.initJsonArray(jsonArray);
    }
    else
    {
        size += strlen(jsonArray)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
        json_data.arrayResize(jsonArray,size+1); //add '\0' for null-termination
    }
    json_data.add2Json(jsonArray,component);
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
   if(jsonArray!=nullptr)
   {
      int size = strlen(json)+strlen(jsonArray)+19;   //add ',"formComponents":' and '\0'
      json_data.arrayResize(json,size);
      json_data.add2JsonArray(json,"formComponents",jsonArray);
   }
}

/* Function: DcForm.get

    return the json script

    Prototype:
        void DcForm::get();

    Parameters:

    Returns:
        char*
*/
char* DcForm::get()
{
    return json;
}
