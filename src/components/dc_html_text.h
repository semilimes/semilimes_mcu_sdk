#ifndef _dc_html_text_
#define _dc_html_text_

#include "../defines.h"

class DcHtmlText
{
private:
    #define headerSize 38
    SmeJson json_data;
    char* json = nullptr;

public:
// Function: ~DcHtmlText

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~DcHtmlText()

//     Parameters:

//     Returns:
///@return         void
    ~DcHtmlText()
    {
        delete[] json;
        json = nullptr;
    }

// Function: DcHtmlText.set

//     An html message

//     Prototype:
//         void DcHtmlText::set(char* html);

//     Parameters:
///@param         html - the html script 

//     Returns:
///@return         void
    void set(char* html);
    
// Function: DcHtmlText.get

//     return the json script

//     Prototype:
//         void DcHtmlText::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif