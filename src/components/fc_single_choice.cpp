#include "fc_single_choice.h"

/* Function: FcSingleChoice.set

    A component displaying a list of options and allowing only one choice

    Prototype:
        void FcSingleChoice::set(const char* refname,const char* title,bool reqSel, const char* mode, const char* value);

    Parameters:
        refname - it is the reference name of the object
        title - is the global label displayed at the beginning of the component
        reqSel - indicates if the selection is required to submit the form
        mode - indicates if the choice should be displayed as a radio list or a dropdown control. char mode[2][9] = {"list", "dropdown"};
        value - points to one of the choices name and determines which option is selected on submission

    Returns:
        void
*/
void FcSingleChoice::set(const char* refname,const char* title,bool reqSel, const char* mode, const char* value)
{
    int size = strlen("{\"formComponentType\":\"singlechoice\",\"refName\":\"\",\"title\":\"\",\"requiredSelection\":,\"mode\":\"\",\"value\":\"\"}")+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+strlen(mode)+strlen(value)+1;//add '\0' for null-termination
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","singlechoice");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"mode",mode);
    json_data.addPair2JsonStr(json,"value",value);
}

/* Function: FcSingleChoice.addOptions

   add an array of options where name is the option identifier and value is the text displayed to the user

    Prototype:
        void FcSingleChoice::addOptions(const char* name,const char* value);

   Parameters:
        name - is the option identifier
        value - text displayed to the user
        
   Returns:
      void
*/
void FcSingleChoice::addOptions(const char* name,const char* value)
{
    int size = strlen("[{\"name\":\"\",\"value\":\"\"}]")+strlen(name)+strlen(value)+1;
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
    if(jsonArray!=nullptr)
    {
        int size = strlen(",\"options\":")+strlen(json)+strlen(jsonArray)+1;   //add '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"options",jsonArray);
    }
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
