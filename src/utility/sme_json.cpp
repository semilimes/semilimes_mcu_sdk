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