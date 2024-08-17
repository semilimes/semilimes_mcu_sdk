#ifndef _fc_switch_
#define _fc_switch_

#include "../defines.h"

class FcSwitch
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: FcSwitch

//     An on/off switch

//     Prototype:
//         void FcSwitch(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    FcSwitch(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: FcSwitch.setObj

//     An on/off switch

//     Prototype:
//         void FcSwitch::setObj(char* refname,char* title,bool value);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the switch
///@param         value - is the default value of the switch when creating and the selected value when submitting

//     Returns:
///@return         void

    void setObj(char* refname,char* title,bool value);
};

#endif