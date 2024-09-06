#include "fc_single_choice.h"

/* Function: FcSingleChoice.set

    A component displaying a list of options and allowing only one choice

    Prototype:
        void FcSingleChoice::set(char* refname,char* title,bool reqSel, char* value);

    Parameters:
        refname - it is the reference name of the object
        title - is the global label displayed at the beginning of the component
        reqSel - indicates if the selection is required to submit the form
        value - points to one of the choices name and determines which option is selected on submission

    Returns:
        void
*/
void FcSingleChoice::set(char* refname,char* title,bool reqSel, char* value)
{
    int size = headerSize+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+strlen(value)+1;//add '\0' for null-termination
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","singlechoice");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"value",value);
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
    int size = strlen(json)+strlen(jsonArray)+12;   //add bytes for ',"options":' and '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"options",jsonArray);
}

/* Function: FcSingleChoice.get

    return the json script

    Prototype:
        void FcSingleChoice::get();

    Parameters:

    Returns:
        char*
*/
char* FcSingleChoice::get()
{
    return json;
}
