#ifndef _fc_qr_scanner_
#define _fc_qr_scanner_

#include "../defines.h"

class FcQrScanner
{
private:
    #define headerSize 126
    SmeJson json_data;
    char* json = nullptr; 
    
public:
//      selects the type of code to support. Allowed values
///@param        char mode[3][8] = {"auto","qrcode","barcode"};
    char mode[3][8] = {"auto","qrcode","barcode"};

// Function: ~FcQrScanner

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcQrScanner()

//     Parameters:

//     Returns:
///@return         void
    ~FcQrScanner()
    {
        delete[] json;
        json = nullptr;
    }

// Function: FcQrScanner.set

//     A scanner button allowing to scan and read QR Codes

//     Prototype:
//         void FcQrScanner::set(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the scanner
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value - is the decoded value of the NFC scan upon form submission
///@param         actBtnTitle -  is the label of the scan button
///@param         mode -  selects the type of code to support. Allowed values: auto, qrcode, barcode. char mode[3][8] = {"auto","qrcode","barcode"};

//     Returns:
///@return         void
    void set(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle, char* mode);

// Function: FcQrScanner.get

//     return the json script

//     Prototype:
//         void FcQrScanner::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif