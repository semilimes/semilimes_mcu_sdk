#include "fc_location_picker.h"

/* Function: FcLocationPicker.set

    A picker showing a map where to choose a location or address

    Prototype:
        void FcLocationPicker::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle,bool currLocOnly);

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
void FcLocationPicker::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle,bool currLocOnly)
{
    int size = strlen("{\"formComponentType\":\"locationpicker\",\"refName\":\"\",\"title\":\"\",\"requiredSelection\":,\"value\":\"\",\"actionButtonTitle\":\"\",\"currentLocationOnly\":}")+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+strlen(value)+strlen(actBtnTitle)+json_data.boolStrSize(currLocOnly)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","locationpicker");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"value",value);
    json_data.addPair2JsonStr(json,"actionButtonTitle",actBtnTitle);
    json_data.addPair2JsonBool(json,"currentLocationOnly",currLocOnly);
}

/* Function: FcLocationPicker.get

    return the json script

    Prototype:
        void FcLocationPicker::get();

    Parameters:

    Returns:
        char*
*/
char* FcLocationPicker::get()
{
    return json;
}