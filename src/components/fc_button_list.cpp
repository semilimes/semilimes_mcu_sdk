#include "fc_button_list.h"

/* Function: FcButtonList.set

    A group of user-clickable buttons with a label

    Prototype:
        void FcButtonList::set(char* refname,char* title,bool reqSel,char* value,bool vertList);

    Parameters:
        refname - is the reference name of the button list
        title - is the global label displayed at the beginning of the component
        reqSel - sets this component interaction as required before submitting the parent form
        value - will be populated with a button name when a user submits a form with a button selection
        vertList -  is a preference to tell a client app to display the buttons vertically

    Returns:
        void
*/
void FcButtonList::set(char* refname,char* title,bool reqSel,char* value,bool vertList)
{
    int size = headerSize+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+strlen(value)+json_data.boolStrSize(vertList)+1;//add '\0' for null-termination
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","buttonlist");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"value",value);
    json_data.addPair2JsonBool(json,"verticalList", vertList);
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
    int size = headerArraySize+strlen(name)+strlen(value)+1;
    char* optTemp = new char[size];
    json_data.initJson(optTemp);
    json_data.addPair2JsonStr(optTemp, "name", name);
    json_data.addPair2JsonStr(optTemp, "value", value);
    
    if(!jsonArray)
    {
        jsonArray = new char[size+1];
        json_data.initJsonArray(jsonArray);
    }
    else
    {
        size += strlen(jsonArray)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
        json_data.arrayResize(jsonArray,size+1); //add '\0' for null-termination
    }
    json_data.add2Json(jsonArray,optTemp);
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
    int size = strlen(json)+strlen(jsonArray)+12;   //add bytes for ',"options":' and '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"options",jsonArray);
}

/* Function: FcButtonList.get

    return the json script

    Prototype:
        void FcButtonList::get();

    Parameters:

    Returns:
        char*
*/
char* FcButtonList::get()
{
    return json;
}
