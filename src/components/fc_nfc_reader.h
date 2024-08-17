#ifndef _fc_nfc_reader_
#define _fc_nfc_reader_

#include "../defines.h"

class FcNfcReader
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: FcNfcReader

//     A scanner button allowing to read NFC tags

//     Prototype:
//         void FcNfcReader(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    FcNfcReader(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: FcNfcReader.setObj

//     A scanner button allowing to read NFC tags

//     Prototype:
//         void FcNfcReader::setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the scanner
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value - is the decoded value of the NFC scan upon form submission
///@param         actBtnTitle -  is the label of the scan button

//     Returns:
///@return         void
    void setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle);
};

#endif