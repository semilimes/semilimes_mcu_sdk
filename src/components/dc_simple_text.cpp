#include "dc_simple_text.h"

/* Function: DcSimpleText.set

    A simple text message

    Prototype:
        void DcSimpleText::set(const char* text);

    Parameters:
        text - the content of the text message

    Returns:
        void
*/
void DcSimpleText::set(const char* text)
{
    int size = headerSize+strlen(text)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json, "dataComponentType", "text");
    json_data.addPair2JsonStr(json, "text", text);
}

/* Function: DcSimpleText.get

    return the json script

    Prototype:
        void DcSimpleText::get();

    Parameters:

    Returns:
        char*
*/
char* DcSimpleText::get()
{
    return json;
}