#include "sme_json.h"

void SmeJson::initJson(char* json)
{
	strcpy(json,"{}\0");
}

void SmeJson::initJsonArray(char* json)
{
	strcpy(json,"[]\0");
}

void SmeJson::substr(int pos,int len,char* strIn,char* strOut)
{
	int i=0;	
	for(i=0; i<len-pos; i++)
	{
        strOut[i] = strIn[pos + i];
	}
	strOut[i] = '\0';
}

char* SmeJson::concatJson(char* json1,char* json2)
{
	char jsonTmp[1000];
	substr(0,strlen(json1)-1,json1,jsonTmp);
	strncat(jsonTmp,",",1);
	strncat(jsonTmp,json2,strlen(json2));
	strncat(jsonTmp,(json1+(strlen(json1)-1)),1);
	return jsonTmp;
}

void SmeJson::add2Json(char* json,char* data)
{	
	if(strlen(json)>=2) 
	{
		char lastCh = json[strlen(json)-1];

		substr(0,strlen(json)-1,json ,json);
		if(strlen(json)>2) strncat(json,",",1);

		strncat(json,data,strlen(data));
		strncat(json,&lastCh,1);
	}
}	

void SmeJson::add2JsonStr(char* json,char* data)
{	
	if(strlen(json)>=2) 
	{
		char lastCh = json[strlen(json)-1];

		substr(0,strlen(json)-1,json ,json);
		if(strlen(json)>2) strncat(json,",",1);

		strncat(json,"\"",1);
		strncat(json,data,strlen(data));
		strncat(json,"\"",1);
		strncat(json,&lastCh,1);
	}
}

void SmeJson::add2JsonArray(char* json,char* property,char* data)
{	
	if(strlen(json)>=2) 
	{
		char lastCh = json[strlen(json)-1];

		substr(0,strlen(json)-1,json ,json);
		if(strlen(json)>2) strncat(json,",",1);

		strncat(json,"\"",1);
		strncat(json,property,strlen(property));
		strncat(json,"\":",2);
		strncat(json,data,strlen(data));
		strncat(json,&lastCh,1);
	}
}

void SmeJson::addPair2Json(char* json,char* property,char* data)
{	
	if(strlen(json)>=2) 
	{
		char lastCh = json[strlen(json)-1];

		substr(0,strlen(json)-1,json ,json);
		if(strlen(json)>2) strncat(json,",",1);

		strncat(json,"\"",1);
		strncat(json,property,strlen(property));
		strncat(json,"\":",2);
		strncat(json,data,strlen(data));
		strncat(json,&lastCh,1);
	}
}

void SmeJson::addPair2JsonStr(char* json,char* property,char* data)
{	
	if(strlen(json)>=2) 
	{
		char lastCh = json[strlen(json)-1];

		substr(0,strlen(json)-1,json ,json);
		if(strlen(json)>2) strncat(json,",",1);

		strncat(json,"\"",1);
		strncat(json,property,strlen(property));
		strncat(json,"\":\"",3);
		strncat(json,data,strlen(data));
		strncat(json,"\"",1);
		strncat(json,&lastCh,1);
	}
}

void SmeJson::addPair2JsonFloat(char* json,char* property,float data,int ndec)
{
	if(strlen(json)>=2) 
	{
		if(ndec>6) ndec=6;
		char ChValue[20] = "";
		char ndec_[6] = "";
		char char2int[2] = "";

		sprintf(char2int,"%d",ndec);
		strncat(ndec_,"%.",2);
		strncat(ndec_,char2int,strlen(char2int));
		strncat(ndec_,"f",1);
		sprintf(ChValue,ndec_,data);

		char lastCh = json[strlen(json)-1];
		substr(0,strlen(json)-1,json ,json);
		if(strlen(json)>2) strncat(json,",",1);
		
		strncat(json,"\"",1);
		strncat(json,property,strlen(property));
		strncat(json,"\":",2);
		strncat(json,ChValue,strlen(ChValue));
		strncat(json,&lastCh,1);
	}
}


void SmeJson::addPair2JsonInt(char* json,char* property,int data)
{
	if(strlen(json)>=2) 
	{
		char ChValue[10];
		sprintf(ChValue,"%d",data);

		char lastCh = json[strlen(json)-1];
		substr(0,strlen(json)-1,json ,json);
		if(strlen(json)>2) strncat(json,",",1);

		strncat(json,"\"",1);
		strncat(json,property,strlen(property));
		strncat(json,"\":",2);
		strncat(json,ChValue,strlen(ChValue));
		strncat(json,&lastCh,1);
	}
}

void SmeJson::addPair2JsonBool(char* json,char* property,bool data)
{
	if(strlen(json)>=2) 
	{
		char lastCh = json[strlen(json)-1];
		substr(0,strlen(json)-1,json ,json);
		if(strlen(json)>2) strncat(json,",",1);

		strncat(json,"\"",1);
		strncat(json,property,strlen(property));
		strncat(json,"\":",2);
		if(data) strncat(json,"true",4);
		else strncat(json,"false",5);
		strncat(json,&lastCh,1);
	}
}

int SmeJson::boolStrSize(bool data)
{
	if(data) return 4;
	else return 5;
}

int SmeJson::intStrSize(int data)
{
    // Base case
    if (data == 0)
        return 1;
  
    int count = 0;
    // Iterate till n has digits remaining
    while (data != 0) {
        // Remove rightmost digit
        data = data / 10;
          // Increment digit count by 1
        ++count;
    }
    return count;
}

int SmeJson::floatStrSize(float data, int ndigits)
{
    // Base case
    if ((int)data == 0)
        return 1+ndigits;
  
    int count = 0;
    // Iterate till n has digits remaining
    while ((int)data != 0) {
        // Remove rightmost digit
        data = data / 10;
          // Increment digit count by 1
        ++count;
    }
    return count+1+ndigits;
}

void SmeJson::arrayResize(char*& json, int size)
{
    if (size <= 0) return; // Check for invalid size

    // Allocate a new array with the required size
    char* temp = new char[size];

    // Safely copy the data from the old array to the new one
    if (json != nullptr) {
        // Calculate the length of the existing string
        int json_len = strlen(json);
        // Ensure we copy only the necessary amount of data
        int copy_size = (json_len < size - 1) ? json_len : size - 1;
        strncpy(temp, json, copy_size);
        temp[copy_size] = '\0'; // Ensure the new string is null-terminated
        // Deallocate the memory pointed to by json
        delete[] json;
    } else {
        // If json is null, just initialize the new array
        temp[0] = '\0';
    }

    // Reassign the json pointer to the new array
    json = temp;
}