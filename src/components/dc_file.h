#ifndef _dc_file_
#define _dc_file_

#include "../defines.h"

class DcFile
{
private:
    #define headerSize 28
    #define headerArraySize 2
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;

public:
/* Function: DcFile.set

   A file object containing one or more files to open or download

   Prototype:
      void DcFile::set();

   Parameters:

   Returns:
      void
*/
    DcFile()
    {
        int size = headerSize+1;//add '\0' for null-termination
        json = new char[size]; 

        json_data.initJson(json);
        json_data.addPair2JsonStr(json,"dataComponentType","file");
    }

// Function: ~DcFile

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~DcFile()

//     Parameters:

//     Returns:
///@return         void
    ~DcFile()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: DcFile.addFileIds

//    Add a File Id to the array
//       void DcFile::addFileIds(char* fileIds);

//    Prototype:
//       void DcFile::addFileIds(char* fileIds);

//    Parameters:
///@param       fileIds - the File Id to add

//    Returns:
///@return       void
    void addFileId(char* fileIds);

// Function: DcFile.appendFileIds

//    Append the File Id array to the json message 

//    Prototype:
//       void DcFile::appendFileIds();

//    Parameters:

//    Returns:
///@return       void
    void appendFileIds();

// Function: DcFile.get

//     return the json script

//     Prototype:
//         void DcFile::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif