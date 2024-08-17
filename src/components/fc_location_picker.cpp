#include "fc_location_picker.h"

/* Function: FcLocationPicker.setObj

    A picker showing a map where to choose a location or address

    Prototype:
        void FcLocationPicker::setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle,bool currLocOnly);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the picker
        reqSel - indicates if the selection is required to submit the form
        value -  is the chosen contact ids when form is submitted
        actBtnTitle - is the label of the pick button
        currLocOnly - 

    Returns:
        void
*/
void FcLocationPicker::setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle,bool currLocOnly)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"formComponentType","locationpicker");
    json_data.addPair2JsonStr(*pjson,"refName",refname);
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonBool(*pjson,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(*pjson,"value",value);
    json_data.addPair2JsonStr(*pjson,"actionButtonTitle",actBtnTitle);
    json_data.addPair2JsonBool(*pjson,"currentLocationOnly",currLocOnly);
}