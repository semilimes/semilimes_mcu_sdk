#include "fc_time_picker.h"

/* Function: FcTimePicker.set

    A graphical time-picker to select a date from a calendar

    Prototype:
        void FcTimePicker::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the picker
        reqSel - indicates if the selection is required to submit the form
        value -  is the chosen time value when form is submitted
        actBtnTitle - is the label of the pick button

    Returns:
        void
*/
void FcTimePicker::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle)
{
    int size = strlen("{\"formComponentType\":\"timepicker\",\"refName\":\"\",\"title\":\"\",\"requiredSelection\":,\"value\":\"\",\"actionButtonTitle\":\"\"}")+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+strlen(value)+strlen(actBtnTitle)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","timepicker");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"value",value);
    json_data.addPair2JsonStr(json,"actionButtonTitle",actBtnTitle);
}

/* Function: FcTimePicker.get

    return the json script

    Prototype:
        void FcTimePicker::get();

    Parameters:

    Returns:
        char*
*/
char* FcTimePicker::get()
{
    return json;
}