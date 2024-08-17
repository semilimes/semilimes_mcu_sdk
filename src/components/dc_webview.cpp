#include "dc_webview.h"

/* Function: DcWebview.setObj

    A message referencing a webpage, to be viewed as a web frame

    Prototype:
        void DcWebview::setObj(char* url, bool enableFullScreenView, char* viewSize);

    Parameters:
        url - is the address to be rendered in the webview
        enableFullScreenView - to enable the fullscreen 
        viewSize - determines the view proportions. Allowed values are: har viewSizeTypes[4][4] = {"1:1", "1:2", "3:2", "2:1"};
    Returns:
        void
*/
void DcWebview::setObj(char* url, bool enableFullScreenView, char* viewSize)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"dataComponentType","webview");
    json_data.addPair2JsonStr(*pjson,"url",url);
    json_data.addPair2JsonBool(*pjson,"enableFullScreenView",enableFullScreenView);
    json_data.addPair2JsonStr(*pjson,"viewSize",viewSize);
}