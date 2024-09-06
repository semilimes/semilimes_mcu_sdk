#ifndef _dc_webview_
#define _dc_webview_

#include "../defines.h"

class DcWebview
{
private:
    #define headerSize 78
    SmeJson json_data;
    char* json = nullptr;

public:
// variable: DcWebview.viewSizeTypes

//     describes the types of viewSize
///@param        char viewSizeTypes[4][4] = {"1:1", "1:2", "3:2", "2:1"};
char viewSizeTypes[4][4] = {"1:1", "1:2", "3:2", "2:1"};
// Function: ~DcWebview

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~DcWebview()

//     Parameters:

//     Returns:
///@return         void
    ~DcWebview()
    {
        delete[] json;
        json = nullptr;
    }

// Function: DcWebview.set

//     A message referencing a webpage, to be viewed as a web frame

//     Prototype:
//         void DcWebview::set(char* url, bool enableFullScreenView, char* viewSize);

//     Parameters:
///@param         url - is the address to be rendered in the webview
///@param         enableFullScreenView - to enable the fullscreen 
///@param         viewSize - determines the view proportions. Allowed values are: har viewSizeTypes[4][4] = {"1:1", "1:2", "3:2", "2:1"};
//     Returns:
///@return         void
    void set(char* url, bool enableFullScreenView, char* viewSize);
    
// Function: DcWebview.get

//     return the json script

//     Prototype:
//         void DcWebview::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif