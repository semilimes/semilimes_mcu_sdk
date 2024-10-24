#include "dc_file.h"

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
void DcFile::addFileId(char* fileIds)
{    
   int size = headerArraySize+strlen(fileIds)+1;
   
   if(!jsonArray)
   {
      jsonArray = new char[size+1];
      json_data.initJsonArray(jsonArray);
   }
   else
   {
      size += strlen(jsonArray)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
      json_data.arrayResize(jsonArray,size+1); //add '\0' for null-termination
   }
   json_data.add2Json(jsonArray,fileIds);
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
   if(jsonArray!=nullptr)
   {
      int size = strlen(json)+strlen(jsonArray)+12;   //add ',"fileIds":' and '\0'
      json_data.arrayResize(json,size);
      json_data.add2JsonArray(json,"fileIds",jsonArray);
   }
}

/* Function: DcFile.get

    return the json script

    Prototype:
        void DcFile::get();

    Parameters:

    Returns:
        char*
*/
char* DcFile::get()
{
    return json;
}