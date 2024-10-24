#include "dc_webview.h"

/* Function: DcWebview.set

    A message referencing a webpage, to be viewed as a web frame

    Prototype:
        void DcWebview::set(char* url, bool enableFullScreenView, char* viewSize);

    Parameters:
        url - is the address to be rendered in the webview
        enableFullScreenView - to enable the fullscreen 
        viewSize - determines the view proportions. Allowed values are: har viewSizeTypes[4][4] = {"1:1", "1:2", "3:2", "2:1"};
        displayMode -  gives the choice to display the destination url in multiple modes (the default behaviour is link): char displayMode  [3][10] = {"link", "thumbnail", "liveweb"};
        linkDisplayName - is used when displayMode is set to link, and it sets a custom name for the displaying URL
    Returns:
        void
*/
void DcWebview::set(char* url, bool enableFullScreenView, char* viewSize, char* displayMode, char* linkDisplayName)
{
    int size = headerSize+strlen(url)+json_data.boolStrSize(enableFullScreenView)+strlen(viewSize)+strlen(displayMode)+strlen(linkDisplayName)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"dataComponentType","webview");
    json_data.addPair2JsonStr(json,"url",url);
    json_data.addPair2JsonStr(json,"displayMode",displayMode);
    json_data.addPair2JsonStr(json,"linkDisplayName",linkDisplayName);
    json_data.addPair2JsonBool(json,"enableFullScreenView",enableFullScreenView);
    json_data.addPair2JsonStr(json,"viewSize",viewSize);
}

/* Function: DcWebview.get

    return the json script

    Prototype:
        void DcWebview::get();

    Parameters:

    Returns:
        char*
*/
char* DcWebview::get()
{
    return json;
}