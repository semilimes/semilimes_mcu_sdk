#include "fc_switch.h"

/* Function: FcSwitch.set

    An on/off switch

    Prototype:
        void FcSwitch::set(char* refname,char* title,bool value);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the switch
        value - is the default value of the switch when creating and the selected value when submitting

    Returns:
        void
*/
void FcSwitch::set(char* refname,char* title,bool value)
{
    int size = headerSize+strlen(refname)+strlen(title)+json_data.boolStrSize(value)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json, "formComponentType","switch");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"value",value);
}

/* Function: FcSwitch.get

    return the json script

    Prototype:
        void FcSwitch::get();

    Parameters:

    Returns:
        char*
*/
char* FcSwitch::get()
{
    return json;
}