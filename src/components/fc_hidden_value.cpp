#include "fc_hidden_value.h"

/* Function: FcHiddenValue.setObj

    A value into the form which is not visible to the use

    Prototype:
        void FcHiddenValue::setObj(char* refname,char* value);

    Parameters:
        refname - it is the reference name of the object
        value -  the hidden value

    Returns:
        void
*/
void FcHiddenValue::setObj(char* refname,char* value)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson, "formComponentType", "hiddenvalue");
    json_data.addPair2JsonStr(*pjson, "refName", refname);
    json_data.addPair2JsonStr(*pjson, "value", value);
}