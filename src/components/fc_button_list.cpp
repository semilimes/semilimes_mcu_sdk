#include "fc_button_list.h"

/* Function: FcButtonList.set

    A group of user-clickable buttons with a label

    Prototype:
        void FcButtonList::set(const char* refname,const char* title,bool reqSel,const char* value,bool vertList,const char* linesize);

    Parameters:
        refname - is the reference name of the button list
        title - is the global label displayed at the beginning of the component
        reqSel - sets this component interaction as required before submitting the parent form
        value - will be populated with a button name when a user submits a form with a button selection
        vertList -  is a preference to tell a client app to display the buttons vertically
        lineSize  -  defines how the buttons should be spread on multiple lines (row/columns). Allowed values are: char lineSize[7][8] = {"1", "2", "3", "4", "5", "6"};

    Returns:
        void
*/
void FcButtonList::set(const char* refname,const char* title,bool reqSel,const char* value,bool vertList,const char* linesize)
{
    int size = strlen("{\"formComponentType\":\"buttonlist\",\"refName\":\"\",\"title\":\"\",\"requiredSelection\":,\"value\":\"\",\"verticalList\":,\"linesize\":\"\"}")+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+strlen(value)+json_data.boolStrSize(vertList)+strlen(linesize)+1;//add '\0' for null-termination
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","buttonlist");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"value",value);
    json_data.addPair2JsonBool(json,"verticalList", vertList);
    json_data.addPair2JsonStr(json,"linesize", linesize);
}

/* Function: FcButtonList.addIconOptions

    add a list of options 

    Prototype:
        void FcButtonList::addOptions(char*& optTemp, int optSize, const char* iconName);

    Parameters:
        optTemp - options json
        optSize - options json size
        iconName - specifies an object with a name for that icon. You can find the icon names reference at the official Google Fonts page

    Returns:
        void
*/
int FcButtonList::addIconOptions(char*& optTemp, int optSize, const char* iconName)
{
    int size = strlen("{\"name\":\"\"}")+strlen(iconName)+1;
    char* iconOptTemp = new char[size];
    json_data.initJson(iconOptTemp);
    json_data.addPair2JsonStr(iconOptTemp, "name", iconName);
    size += optSize+strlen(",\"icon\":")+1;   //add '\0'
    json_data.arrayResize(optTemp,size);
	json_data.addPair2Json(optTemp,"icon",iconOptTemp);
    return size;
}

/* Function: FcButtonList.addOptions

    add an array of options where name is the option identifier and value is the text displayed to the user

    Prototype:
        void FcButtonList::addOptions(const char* name,const char* value, const char* iconName);

    Parameters:
        name - is the option identifier
        value - text displayed to the user
        iconName -   within options specifies an object with a name for that icon. You can find the icon names reference at the official Google Fonts page

    Returns:
        void
*/
void FcButtonList::addOptions(const char* name,const char* value, const char* iconName)
{
    int size = strlen("{\"name\":\"\",\"value\":\"\"}")+strlen(name)+strlen(value)+1;
    char* optTemp = new char[size];
    json_data.initJson(optTemp);
    json_data.addPair2JsonStr(optTemp, "name", name);
    json_data.addPair2JsonStr(optTemp, "value", value);
    size = this->addIconOptions(optTemp,size,iconName);
    
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
    if(jsonArray!=nullptr) 
    {    
        int size = strlen(",\"options\":")+strlen(json)+strlen(jsonArray)+1;   //add '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"options",jsonArray);
    }
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
