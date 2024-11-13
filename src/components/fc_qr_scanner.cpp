#include "fc_qr_scanner.h"

/* Function: FcQrScanner.set

    A scanner button allowing to scan and read QR Codes

    Prototype:
        void FcQrScanner::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle, const char* mode);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the scanner
        reqSel - indicates if the selection is required to submit the form
        value - is the decoded value of the NFC scan upon form submission
        actBtnTitle -  is the label of the scan button
        mode -  selects the type of code to support. Allowed values: auto, qrcode, barcode. char mode[3][8] = {"auto","qrcode","barcode"};

    Returns:
        void
*/
void FcQrScanner::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle, const char* mode)
{
    int size = strlen("{\"formComponentType\":\"qrcodescanner\",\"refName\":\"\",\"title\":\"\",\"requiredSelection\":,\"mode\":\"\",\"value\":\"\",\"actionButtonTitle\":\"\"}")+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+strlen(value)+strlen(actBtnTitle)+strlen(mode)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","qrcodescanner");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"mode",mode);
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