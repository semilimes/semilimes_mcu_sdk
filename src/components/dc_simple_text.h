#ifndef _dc_simple_text_
#define _dc_simple_text_

#include "../defines.h"

class DcSimpleText
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: DcSimpleText

//     A simple text message

//     Prototype:
//         void DcSimpleText(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    DcSimpleText(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: DcSimpleText.setObj

//     A simple text message

//     Prototype:
//         void DcSimpleText::setObj(char* text);

//     Parameters:
///@param         text - the content of the text message

//     Returns:
///@return         void
    void setObj(char* text);
};

#endif