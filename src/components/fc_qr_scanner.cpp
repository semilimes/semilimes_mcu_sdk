#include "fc_qr_scanner.h"

/* Function: FcQrScanner.set

    A scanner button allowing to scan and read QR Codes

    Prototype:
        void FcQrScanner::set(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the scanner
        reqSel - indicates if the selection is required to submit the form
        value - is the decoded value of the NFC scan upon form submission
        actBtnTitle -  is the label of the scan button

    Returns:
        void
*/
void FcQrScanner::set(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle)
{
    int size = headerSize+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+strlen(value)+strlen(actBtnTitle)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","qrcodescanner");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"value",value);
    json_data.addPair2JsonStr(json,"actionButtonTitle",actBtnTitle);
}

/* Function: FcQrScanner.get

    return the json script

    Prototype:
        void FcQrScanner::get();

    Parameters:

    Returns:
        char*
*/
char* FcQrScanner::get()
{
    return json;
}