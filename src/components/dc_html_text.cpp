#include "dc_html_text.h"

/* Function: DcHtmlText.setObj

    An html message

    Prototype:
        void DcHtmlText::setObj(char* html);

    Parameters:
        html - the html script 

    Returns:
        void
*/
void DcHtmlText::setObj(char* html)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson, "dataComponentType", "html");
    json_data.addPair2JsonStr(*pjson, "html", html);
}