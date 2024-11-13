#include "fc_text_box.h"

/* Function: FcTextBox.set

    A text field with a title and a user-editable text field.

    Prototype:
        void FcTextBox::set(const char* refname,const char* title,const char* value,bool reqSel);

    Parameters:
        refname - it is the reference name of the object
        title - is the textbox title
        value - is the text pre-populated in the textbox and the text input by the user at form submission
        reqSel - sets this component interaction as required before submitting the parent form

    Returns:
        void
*/
void FcTextBox::set(const char* refname,const char* title,const char* value,bool reqSel)
{
    int size = strlen("{\"formComponentType\":\"textbox\",\"refName\":\"\",\"title\":\"\",\"requiredSelection\":,\"value\":\"\"}")+strlen(refname)+strlen(title)+strlen(value)+json_data.boolStrSize(reqSel)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json, "formComponentType","textbox");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"value",value);
}

/* Function: FcTextBox.get

    return the json script

    Prototype:
        void FcTextBox::get();

    Parameters:

    Returns:
        char*
*/
char* FcTextBox::get()
{
    return json;
}