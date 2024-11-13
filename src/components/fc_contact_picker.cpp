#include "fc_contact_picker.h"

/* Function: FcContactPicker.set

    A picker allowing to select and reference contacts

    Prototype:
        void FcContactPicker::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle,bool multiSel);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the picker
        reqSel - indicates if the selection is required to submit the form
        value -  is the chosen contact ids when form is submitted
        actBtnTitle - is the label of the pick button
        multiSel -  is a flag that allows the user to select multiple objects in the UI

    Returns:
        void
*/
void FcContactPicker::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle,bool multiSel)
{
    int size = strlen("{\"formComponentType\":\"contactpicker\",\"refName\":\"\",\"title\":\"\",\"requiredSelection\":,\"value\":\"\",\"actionButtonTitle\":\"\",\"multiSelection\":}")+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+strlen(value)+strlen(actBtnTitle)+json_data.boolStrSize(multiSel)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","contactpicker");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"value",value);
    json_data.addPair2JsonStr(json,"actionButtonTitle",actBtnTitle);
    json_data.addPair2JsonBool(json,"multiSelection",multiSel);
}

/* Function: FcContactPicker.get

    return the json script

    Prototype:
        void FcContactPicker::get();

    Parameters:

    Returns:
        char*
*/
char* FcContactPicker::get()
{
    return json;
}