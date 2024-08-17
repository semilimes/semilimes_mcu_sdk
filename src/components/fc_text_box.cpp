#include "fc_text_box.h"

/* Function: FcTextBox.setObj

    A text field with a title and a user-editable text field.

    Prototype:
        void FcTextBox::setObj(char* refname,char* title,char* value,bool reqSel);

    Parameters:
        refname - it is the reference name of the object
        title - is the textbox title
        value - is the text pre-populated in the textbox and the text input by the user at form submission
        reqSel - sets this component interaction as required before submitting the parent form

    Returns:
        void
*/
void FcTextBox::setObj(char* refname,char* title,char* value,bool reqSel)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson, "formComponentType","textbox");
    json_data.addPair2JsonStr(*pjson,"refName",refname);
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonBool(*pjson,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(*pjson,"value",value);
}