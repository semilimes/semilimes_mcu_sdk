#include "fc_multiple_choice.h"

/* Function: FcMultipleChoice.set

    A component displaying a list of options and allowing multiple choice

    Prototype:
        void FcMultipleChoice::set(char* refname,char* title,bool reqSel);

    Parameters:
        refname - it is the reference name of the object
        title - is the global label displayed at the beginning of the component
        reqSel - indicates if the selection is required to submit the form

    Returns:
        void
*/
void FcMultipleChoice::set(char* refname,char* title,bool reqSel)
{
    int size = headerSize+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+1;//add '\0' for null-termination
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","multichoice");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
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
    if(jsonArray!=nullptr)
    {
        int size = strlen(json)+strlen(jsonArray)+12;   //add bytes for ',"options":' and '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"options",jsonArray);
    }
}

/* Function: FcMultipleChoice.addValue

    add an array of the names of the choices 

    Prototype:
        void FcMultipleChoice::addValue(char* value);

    Parameters:
        value - is an array containing the names of the choices that are selected on submission
        {
            "name" : "choice1",
            "value": "Choice 1"
        }

    Returns:
        void
*/
void FcMultipleChoice::addValue(char* value)
{    
    int size = headerArray2Size+strlen(value)+3; //add '\0' and \"\" 
    
    if(!jsonArray2)
    {
        jsonArray2 = new char[size+1];
        json_data.initJsonArray(jsonArray2);
    }
    else
    {
        size += strlen(jsonArray2)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
        json_data.arrayResize(jsonArray2,size+1); //add '\0' for null-termination
    }
    json_data.add2JsonStr(jsonArray2,value);
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
    if(jsonArray2!=nullptr)
    {
        int size = strlen(json)+strlen(jsonArray2)+10;   //add bytes for ',"value":' and '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"value",jsonArray2);
    }
}

/* Function: FcMultipleChoice.get

    return the json script

    Prototype:
        void FcMultipleChoice::get();

    Parameters:

    Returns:
        char*
*/
char* FcMultipleChoice::get()
{
    return json;
}
