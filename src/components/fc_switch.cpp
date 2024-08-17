#include "fc_switch.h"

/* Function: FcSwitch.setObj

    An on/off switch

    Prototype:
        void FcSwitch::setObj(char* refname,char* title,bool value);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the switch
        value - is the default value of the switch when creating and the selected value when submitting

    Returns:
        void
*/
void FcSwitch::setObj(char* refname,char* title,bool value)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson, "formComponentType","switch");
    json_data.addPair2JsonStr(*pjson,"refName",refname);
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonBool(*pjson,"value",value);
}