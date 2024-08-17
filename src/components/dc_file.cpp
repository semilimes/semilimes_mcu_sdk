#include "dc_file.h"

/* Function: DcFile.setObj

   A file object containing one or more files to open or download

   Prototype:
      void DcFile::setObj();

   Parameters:

   Returns:
      void
*/
void DcFile::setObj()
{
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
        json_data.addPair2JsonStr(*pjson,"dataComponentType","file");
}

/* Function: DcFile.addFileIds

   Add a File Id to the array
      void DcFile::addFileIds(char* fileIds);

   Prototype:
      void DcFile::addFileIds(char* fileIds);

   Parameters:
      fileIds - the File Id to add

   Returns:
      void
*/
void DcFile::addFileIds(char* fileIds)
{    
   json_data.add2JsonStr(*pjsonArray,fileIds);
}

/* Function: DcFile.appendFileIds

   Append the File Id array to the json message 

   Prototype:
      void DcFile::appendFileIds();

   Parameters:

   Returns:
      void
*/
void DcFile::appendFileIds()
{
	json_data.add2JsonArray(*pjson,"fileIds",*pjsonArray);
}