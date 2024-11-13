#include "fc_color_picker.h"

/* Function: FcColorPicker.set

    A graphical color-picker to select a color from a palette and return its RGB value

    Prototype:
        void FcColorPicker::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the picker
        reqSel - indicates if the selection is required to submit the form
        value -  is the chosen contact ids when form is submitted
        actBtnTitle - is the label of the pick button

    Returns:
        void
*/
void FcColorPicker::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle)
{
    int size = strlen("{\"formComponentType\":\"colorpicker\",\"refName\":\"\",\"title\":\"\",\"requiredSelection\":,\"value\":\"\",\"actionButtonTitle\":\"\"}")+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+strlen(value)+strlen(actBtnTitle)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","colorpicker");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"value",value);
    json_data.addPair2JsonStr(json,"actionButtonTitle",actBtnTitle);
}

/* Function: FcColorPicker.get

    return the json script

    Prototype:
        void FcColorPicker::get();

    Parameters:

    Returns:
        char*
*/
char* FcColorPicker::get()
{
    return json;
}