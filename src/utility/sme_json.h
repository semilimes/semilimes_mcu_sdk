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
	char* concatJson(const char* json1, const char* json2);
	void add2Json(char* json, const char* data);
	void add2JsonStr(char* json, const char* data);
	void add2JsonArray(char* json, const char* property, const char* data);
	void addPair2Json(char* json, const char* property, const char* data);
	void addPair2JsonStr(char* json, const char* property, const char* data);
	void addPair2JsonInt(char* json, const char* property, int data);
	void addPair2JsonFloat(char* json, const char* property, float data, int ndec=2);
	void addPair2JsonBool(char* json, const char* property, bool data);
	void substr(int pos, int len, const char* strIn, char* strOut);
	int boolStrSize(bool data);
	int intStrSize(int data);
	int floatStrSize(float data, int ndigits);
	void arrayResize(char*& json, int size);
};

#endif