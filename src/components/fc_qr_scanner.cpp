#include "fc_qr_scanner.h"

/* Function: FcQrScanner.setObj

    A scanner button allowing to scan and read QR Codes

    Prototype:
        void FcQrScanner::setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the scanner
        reqSel - indicates if the selection is required to submit the form
        value - is the decoded value of the NFC scan upon form submission
        actBtnTitle -  is the label of the scan button

    Returns:
        void
*/
void FcQrScanner::setObj(char* refname,char* title,bool reqSel, char* value,char* actBtnTitle)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"formComponentType","qrcodescanner");
    json_data.addPair2JsonStr(*pjson,"refName",refname);
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonBool(*pjson,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(*pjson,"value",value);
    json_data.addPair2JsonStr(*pjson,"actionButtonTitle",actBtnTitle);
}