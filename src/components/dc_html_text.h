#ifndef _dc_html_text_
#define _dc_html_text_

#include "../defines.h"

class DcHtmlText
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: DcHtmlText

//     An html message

//     Prototype:
//         void DcHtmlText(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    DcHtmlText(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: DcHtmlText.setObj

//     An html message

//     Prototype:
//         void DcHtmlText::setObj(char* html);

//     Parameters:
///@param         html - the html script 

//     Returns:
///@return         void
    void setObj(char* html);
};

#endif