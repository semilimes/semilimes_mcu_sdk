#ifndef _fc_nfc_reader_
#define _fc_nfc_reader_

#include "../defines.h"

class FcNfcReader
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    
public:
// Function: ~FcNfcReader

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcNfcReader()

//     Parameters:

//     Returns:
///@return         void
    ~FcNfcReader()
    {
        delete[] json;
        json = nullptr;
    }

// Function: FcNfcReader.set

//     A scanner button allowing to read NFC tags

//     Prototype:
//         void FcNfcReader::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the text displayed next to the scanner
///@param         reqSel - indicates if the selection is required to submit the form
///@param         value - is the decoded value of the NFC scan upon form submission
///@param         actBtnTitle -  is the label of the scan button

//     Returns:
///@return         void
    void set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle);

// Function: FcNfcReader.get

//     return the json script

//     Prototype:
//         void FcNfcReader::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif