#include "fc_date_picker.h"

/* Function: FcDatePicker.setObj

    A graphical date-picker to select a date from a calendar

    Prototype:
        void FcDatePicker::setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the picker
        reqSel - indicates if the selection is required to submit the form
        value -  is the chosen contact ids when form is submitted
        actBtnTitle - is the label of the pick button

    Returns:
        void
*/
void FcDatePicker::setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"formComponentType","datepicker");
    json_data.addPair2JsonStr(*pjson,"refName",refname);
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonBool(*pjson,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(*pjson,"value",value);
    json_data.addPair2JsonStr(*pjson,"actionButtonTitle",actBtnTitle);
}