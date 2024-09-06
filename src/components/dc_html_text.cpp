#include "dc_html_text.h"

/* Function: DcHtmlText.set

    An html message

    Prototype:
        void DcHtmlText::set(char* html);

    Parameters:
        html - the html script 

    Returns:
        void
*/
void DcHtmlText::set(char* html)
{
    int size = headerSize+strlen(html)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json, "dataComponentType", "html");
    json_data.addPair2JsonStr(json, "html", html);
}

/* Function: DcHtmlText.get

    return the json script

    Prototype:
        void DcHtmlText::get();

    Parameters:

    Returns:
        char*
*/
char* DcHtmlText::get()
{
    return json;
}