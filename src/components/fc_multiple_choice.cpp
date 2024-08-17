#include "fc_multiple_choice.h"

/* Function: FcMultipleChoice.setObj

    A component displaying a list of options and allowing multiple choice

    Prototype:
        void FcMultipleChoice::setObj(char* refname,char* title,bool reqSel);

    Parameters:
        refname - it is the reference name of the object
        title - is the global label displayed at the beginning of the component
        reqSel - indicates if the selection is required to submit the form

    Returns:
        void
*/
void FcMultipleChoice::setObj(char* refname,char* title,bool reqSel)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"formComponentType","multichoice");
    json_data.addPair2JsonStr(*pjson,"refName",refname);
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonBool(*pjson,"requiredSelection",reqSel);
    json_data.initJsonArray(*pjsonArray);
    json_data.initJsonArray(*pjsonArray2);
}

/* Function: FcMultipleChoice.addOptions

    add an array of options where name is the option identifier and value is the text displayed to the user

    Prototype:
        void FcMultipleChoice::addOptions(char* name,char* value);

    Parameters:
        name - is the option identifier
        value - text displayed to the user
        
   Returns:
      void
*/
void FcMultipleChoice::addOptions(char* name,char* value)
{
    char optTemp[100]="{}";
    json_data.addPair2JsonStr(optTemp, "name", name);
    json_data.addPair2JsonStr(optTemp, "value", value);
    json_data.add2Json(*pjsonArray,optTemp);
}

/* Function: FcMultipleChoice.appendOptions

    Prototype:
        void FcMultipleChoice::appendOptions();

    Append the selected options

    Parameters:

    Returns:
        void
*/
void FcMultipleChoice::appendOptions()
{    
	json_data.add2JsonArray(*pjson,"options",*pjsonArray);
}

/* Function: FcMultipleChoice.addValues

    add an array of the names of the choices 

    Prototype:
        void FcMultipleChoice::addValues(char* value);

    Parameters:
        value - is an array containing the names of the choices that are selected on submission
        {
            "name" : "choice1",
            "value": "Choice 1"
        }

    Returns:
        void
*/
void FcMultipleChoice::addValues(char* value)
{    
    json_data.add2JsonStr(*pjsonArray2,value);
}

/* Function: FcMultipleChoice.appendValues

    Append the selected options

    Prototype:
        void FcMultipleChoice::appendValues()

    Parameters:

    Returns:
        void
*/
void FcMultipleChoice::appendValues()
{    
	json_data.add2JsonArray(*pjson,"value",*pjsonArray2);
}