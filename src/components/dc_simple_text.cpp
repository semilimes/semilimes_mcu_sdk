#include "dc_simple_text.h"

/* Function: DcSimpleText.setObj

    A simple text message

    Prototype:
        void DcSimpleText::setObj(char* text);

    Parameters:
        text - the content of the text message

    Returns:
        void
*/
void DcSimpleText::setObj(char* text)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson, "dataComponentType", "text");
    json_data.addPair2JsonStr(*pjson, "text", text);
}