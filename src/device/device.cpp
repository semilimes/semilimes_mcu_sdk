#include "device.h"

/* Function: Device.set

    an object that describes the device from the hw perspective

    Prototype:
        void Device::set(char* name);

    Parameters:
        name - the name of the object

    Returns:
        void
*/
void Device::set(char* name)
{
    int size = headerSize+strlen(name)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"name",name);
}


/* Function: Device.addGPIO

    add a GPIO to an array that describes the hw interface capabilities of the device

    Prototype:
        void Device::addGPIO(char* name, char* pinType, char* portName, int pinNumber, int value);

    Parameters:
        name - the name of the object
        GPIOType - defines the type of the pin, can be one of the following: char pinTypes[5][10] = {"out", "in", "analogIn", "analogOut", "pwm"};
        portName - the name of the hw port
        pinNumber - the pin number
        value - the value of the pin

    Returns:
        void
*/
void Device::addGPIO(char* name, char* GPIOType, char* portName, int pinNumber, int value)
{  
    int size = headerPinSize+strlen(name)+strlen(GPIOType)+strlen(portName)+json_data.intStrSize(pinNumber)+json_data.intStrSize(value)+1;
    char* pinTmp = new char[size];
    json_data.initJson(pinTmp);
    json_data.addPair2JsonStr(pinTmp,"name",name);
    json_data.addPair2JsonStr(pinTmp,"pinType",GPIOType);
    json_data.addPair2JsonStr(pinTmp,"portName",portName);
    json_data.addPair2JsonInt(pinTmp,"pinNumber",pinNumber);
    json_data.addPair2JsonInt(pinTmp,"value",value);

    size += 2;//add "[]"  
    if(!jsonPins)
    {
        jsonPins = new char[size];
        json_data.initJsonArray(jsonPins);
    }
    else
    {
        size = strlen(jsonPins)+strlen(pinTmp)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
        json_data.arrayResize(jsonPins,size+1); 
    }
    json_data.add2Json(jsonPins,pinTmp);
    delete[] pinTmp;
}

/* Function: Device.addFunction

    add an array of internal methods/functions  

    Prototype:
        void Device::addFunction(char* name, char* methodName);

    Parameters:
        name - the name of theobject
        methodName - the name of the method to call

    Returns:
        void
*/
void Device::addFunction(char* name, char* methodName)
{  
    int size = headerPinSize+strlen(name)+strlen(methodName)+1;
    char* fncTmp = new char[size];
    json_data.initJson(fncTmp);
    json_data.addPair2JsonStr(fncTmp,"name",name);
    json_data.addPair2JsonStr(fncTmp,"methodName",methodName);

    size += 2;//add "[]"  
    if(!jsonFunctions)
    {
        jsonFunctions = new char[size];
        json_data.initJsonArray(jsonFunctions);
    }
    else
    {
        size = strlen(jsonFunctions)+strlen(fncTmp)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
        json_data.arrayResize(jsonFunctions,size+1); 
    }
    json_data.add2Json(jsonFunctions,fncTmp);
    delete[] fncTmp;
}

/* Function: Device.appendGPIOs

    Append the selected GPIO

    Prototype:
        void Device::appendGPIOs();

    Parameters:

    Returns:
        void
*/
void Device::appendGPIOs()
{
    int size = strlen(json)+strlen(jsonPins)+9;   //add ',"pins":' and '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"pins",jsonPins);
}

/* Function: Device.appendFunctions

    Append the selected functions

    Prototype:
        void Device::appendFunctions();

    Parameters:

    Returns:
        void
*/
void Device::appendFunctions()
{
    int size = strlen(json)+strlen(jsonFunctions)+14;   //add ',"functions":' and '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"functions",jsonFunctions);
}

/* Function: Device.get

    return the json script

    Prototype:
        void Device::get();

    Parameters:

    Returns:
        char*
*/
char* Device::get()
{
    return json;
}
