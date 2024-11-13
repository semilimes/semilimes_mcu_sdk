#include "fc_nfc_reader.h"

/* Function: FcNfcReader.set

    A scanner button allowing to read NFC tags

    Prototype:
        void FcNfcReader::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the scanner
        reqSel - indicates if the selection is required to submit the form
        value - is the decoded value of the NFC scan upon form submission
        actBtnTitle -  is the label of the scan button

    Returns:
        void
*/
void FcNfcReader::set(const char* refname,const char* title,bool reqSel, const char* value,const char* actBtnTitle)
{
    int size = strlen("{\"formComponentType\":\"nfcreader\",\"refName\":\"\",\"title\":\"\",\"requiredSelection\":,\"value\":\"\",\"actionButtonTitle\":\"\"}")+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+strlen(value)+strlen(actBtnTitle)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","nfcreader");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonStr(json,"value",value);
    json_data.addPair2JsonStr(json,"actionButtonTitle",actBtnTitle);
}

/* Function: FcNfcReader.get

    return the json script

    Prototype:
        void FcNfcReader::get();

    Parameters:

    Returns:
        char*
*/
char* FcNfcReader::get()
{
    return json;
}