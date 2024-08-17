#ifndef _sme_json_
#define _sme_json_

#include <string.h> 
#include <stdio.h>

class SmeJson
{
private:
public:
	void initJson(char* json);
	void initJsonArray(char* json);
	char* concatJson(char* json1, char* json2);
	void add2Json(char* json, char* data);
	void add2JsonStr(char* json, char* data);
	void add2JsonArray(char* json, char* property, char* data);
	void addPair2Json(char* json, char* property, char* data);
	void addPair2JsonStr(char* json, char* property, char* data);
	void addPair2JsonInt(char* json, char* property, int data);
	void addPair2JsonFloat(char* json, char* property, float data, int ndec=2);
	void addPair2JsonBool(char* json, char* property, bool data);
	void substr(int pos, int len, char* strIn, char* strOut);
};

#endif