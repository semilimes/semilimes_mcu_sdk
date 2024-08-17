#ifndef _dc_webview_
#define _dc_webview_

#include "../defines.h"

class DcWebview
{
private:
    SmeJson json_data;
    char** pjson;

public:
// Function: DcWebview

//     A message referencing a webpage, to be viewed as a web frame

//     Prototype:
//         void DcWebview(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    DcWebview(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }
    char viewSizeTypes[4][4] = {"1:1", "1:2", "3:2", "2:1"};

// Function: DcWebview.setObj

//     A message referencing a webpage, to be viewed as a web frame

//     Prototype:
//         void DcWebview::setObj(char* url, bool enableFullScreenView, char* viewSize);

//     Parameters:
///@param         url - is the address to be rendered in the webview
///@param         enableFullScreenView - to enable the fullscreen 
///@param         viewSize - determines the view proportions. Allowed values are: har viewSizeTypes[4][4] = {"1:1", "1:2", "3:2", "2:1"};
//     Returns:
///@return         void
    void setObj(char* url, bool enableFullScreenView, char* viewSize);
};

#endif