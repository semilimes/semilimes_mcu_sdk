#ifndef _dc_simple_text_
#define _dc_simple_text_

#include "../defines.h"

class DcSimpleText
{
private:
    #define headerSize 38
    SmeJson json_data;
    char* json = nullptr;

public:
// Function: ~DcSimpleText

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~DcSimpleText()

//     Parameters:

//     Returns:
///@return         void
    ~DcSimpleText()
    {
        delete[] json;
        json = nullptr;
    }

// Function: DcSimpleText.set

//     A simple text message

//     Prototype:
//         void DcSimpleText::set(char* text);

//     Parameters:
///@param         text - the content of the text message

//     Returns:
///@return         void
    void set(char* text);
    
// Function: DcSimpleText.get

//     return the json script

//     Prototype:
//         void DcSimpleText::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif