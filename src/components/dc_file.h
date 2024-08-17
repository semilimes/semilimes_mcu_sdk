#ifndef _dc_file_
#define _dc_file_

#include "../defines.h"

class DcFile
{
private:
    SmeJson json_data;
    char** pjson;
    char** pjsonArray;

public:
// Function: DcFile

//    A file object containing one or more files to open or download

//     Prototype:
//         void DcFile(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    DcFile(char* json, char* jsonArray)
    {
        pjson = &json;
        pjsonArray = &jsonArray;
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
        json_data.addPair2JsonStr(*pjson,"dataComponentType","file");
    }

// Function: DcFile.setObj

//    A file object containing one or more files to open or download

//    Prototype:
//       void DcFile::setObj();

//    Parameters:

//    Returns:
///@return       void
    void setObj();

// Function: DcFile.addFileIds

//    Add a File Id to the array
//       void DcFile::addFileIds(char* fileIds);

//    Prototype:
//       void DcFile::addFileIds(char* fileIds);

//    Parameters:
///@param       fileIds - the File Id to add

//    Returns:
///@return       void
    void addFileIds(char* fileIds);

// Function: DcFile.appendFileIds

//    Append the File Id array to the json message 

//    Prototype:
//       void DcFile::appendFileIds();

//    Parameters:

//    Returns:
///@return       void
    void appendFileIds();
};

#endif