#include "fc_single_choice.h"

/* Function: FcSingleChoice.setObj

    A component displaying a list of options and allowing only one choice

    Prototype:
        void FcSingleChoice::setObj(char* refname,char* title,bool reqSel, char* value);

    Parameters:
        refname - it is the reference name of the object
        title - is the global label displayed at the beginning of the component
        reqSel - indicates if the selection is required to submit the form
        value - points to one of the choices name and determines which option is selected on submission

    Returns:
        void
*/
void FcSingleChoice::setObj(char* refname,char* title,bool reqSel, char* value)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"formComponentType","singlechoice");
    json_data.addPair2JsonStr(*pjson,"refName",refname);
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonBool(*pjson,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(*pjson,"value",value);
    json_data.initJsonArray(*pjsonArray);
}

/* Function: FcSingleChoice.addOptions

   add an array of options where name is the option identifier and value is the text displayed to the user

    Prototype:
        void FcSingleChoice::addOptions(char* data);

   Parameters:
        name - is the option identifier
        value - text displayed to the user
        
   Returns:
      void
*/
void FcSingleChoice::addOptions(char* name,char* value)
{
    char optTemp[100]="{}";
    json_data.addPair2JsonStr(optTemp, "name", name);
    json_data.addPair2JsonStr(optTemp, "value", value);
    json_data.add2Json(*pjsonArray,optTemp);
}

/* Function: FcSingleChoice.appendOptions

    Append the selected options

    Prototype:
        void FcSingleChoice::appendOptions();

    Parameters:

    Returns:
        void
*/
void FcSingleChoice::appendOptions()
{    
	json_data.add2JsonArray(*pjson,"options",*pjsonArray);
}