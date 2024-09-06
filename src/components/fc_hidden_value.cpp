#include "fc_hidden_value.h"

/* Function: FcHiddenValue.set

    A value into the form which is not visible to the use

    Prototype:
        void FcHiddenValue::set(char* refname,char* value);

    Parameters:
        refname - it is the reference name of the object
        value -  the hidden value

    Returns:
        void
*/
void FcHiddenValue::set(char* refname,char* value)
{
    int size = headerSize+strlen(refname)+strlen(value)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json, "formComponentType", "hiddenvalue");
    json_data.addPair2JsonStr(json, "refName", refname);
    json_data.addPair2JsonStr(json, "value", value);
}

/* Function: FcHiddenValue.get

    return the json script

    Prototype:
        void FcHiddenValue::get();

    Parameters:

    Returns:
        char*
*/
char* FcHiddenValue::get()
{
    return json;
}