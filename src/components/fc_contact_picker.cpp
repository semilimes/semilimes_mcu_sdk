#include "fc_contact_picker.h"

/* Function: FcContactPicker.setObj

    A picker allowing to select and reference contacts

    Prototype:
        void FcContactPicker::setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle,bool multiSel);

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
void FcContactPicker::setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle,bool multiSel)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"formComponentType","contactpicker");
    json_data.addPair2JsonStr(*pjson,"refName",refname);
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonBool(*pjson,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(*pjson,"value",value);
    json_data.addPair2JsonStr(*pjson,"actionButtonTitle",actBtnTitle);
    json_data.addPair2JsonBool(*pjson,"multiSelection",multiSel);
}