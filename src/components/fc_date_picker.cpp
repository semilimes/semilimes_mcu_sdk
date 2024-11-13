#include "fc_date_picker.h"

/* Function: FcDatePicker.set

    A graphical date-picker to select a date from a calendar

    Prototype:
        void FcDatePicker::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the picker
        reqSel - indicates if the selection is required to submit the form
        value -  is the chosen date when form is submitted
        actBtnTitle - is the label of the pick button

    Returns:
        void
*/
void FcDatePicker::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle)
{
    int size = strlen("{\"formComponentType\":\"datepicker\",\"refName\":\"\",\"title\":\"\",\"requiredSelection\":,\"value\":\"\",\"actionButtonTitle\":\"\"}")+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+strlen(value)+strlen(actBtnTitle)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","datepicker");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"value",value);
    json_data.addPair2JsonStr(json,"actionButtonTitle",actBtnTitle);
}

/* Function: FcDatePicker.get

    return the json script

    Prototype:
        void FcDatePicker::get();

    Parameters:

    Returns:
        char*
*/
char* FcDatePicker::get()
{
    return json;
}