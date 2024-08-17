#include "fc_button_list.h"

/* Function: FcButtonList.setObj

    A group of user-clickable buttons with a label

    Prototype:
        void FcButtonList::setObj(char* refname,char* title,bool reqSel,char* value,bool vertList);

    Parameters:
        refname - is the reference name of the button list
        title - is the global label displayed at the beginning of the component
        reqSel - sets this component interaction as required before submitting the parent form
        value - will be populated with a button name when a user submits a form with a button selection
        vertList -  is a preference to tell a client app to display the buttons vertically

    Returns:
        void
*/
void FcButtonList::setObj(char* refname,char* title,bool reqSel,char* value,bool vertList)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"formComponentType","buttonlist");
    json_data.addPair2JsonStr(*pjson,"refName",refname);
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonBool(*pjson,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(*pjson,"value",value);
    json_data.addPair2JsonBool(*pjson,"verticalList", vertList);
    json_data.initJsonArray(*pjsonArray);
}

/* Function: FcButtonList.addOptions

    add an array of options where name is the option identifier and value is the text displayed to the user

    Prototype:
        void FcButtonList::addOptions(char* name,char* value);

    Parameters:
        name - is the option identifier
        value - text displayed to the user

    Returns:
        void
*/
void FcButtonList::addOptions(char* name,char* value)
{
    char optTemp[100]="{}";
    json_data.addPair2JsonStr(optTemp, "name", name);
    json_data.addPair2JsonStr(optTemp, "value", value);
    json_data.add2Json(*pjsonArray,optTemp);
}

/* Function: FcButtonList.appendOptions

    Append the selected options

    Prototype:
        void FcButtonList::appendOptions();

    Parameters:

    Returns:
        void
*/
void FcButtonList::appendOptions()
{    
	json_data.add2JsonArray(*pjson,"options",*pjsonArray);
}