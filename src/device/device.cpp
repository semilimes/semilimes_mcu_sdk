#include "device.h"

/* Function: Device.set

    an object that describes the device from the hw perspective

    Prototype:
        void Device::set(char* refname char* name);

    Parameters:
        deviceId - it is the device Id
        name - the name of the object

    Returns:
        void
*/
void Device::set(char* deviceId, char* name)
{
    int size = headerSize+strlen(name)+strlen(deviceId)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"name",name);
    json_data.addPair2JsonStr(json,"deviceId",deviceId);
}

/* Function: Device.gpioTypeIndex

     turn the GPIOType into the corresponding index

     Prototype:
         void gpioTypeIndex(char* GPIOType, char* GPIOTypeIndex);

     Parameters:
         GPIOType - the type of the pin: char pinTypes[5][10] = {"out", "in", "analogIn", "analogOut", "pwm"};
         GPIOTypeIndex - the corresponding index to the GPIOtype

     Returns:
         void
*/
void Device::gpioTypeIndex(char* gpioType, char* GPIOTypeIndex)
{
  if(strcmp(gpioType, GPIOType[0])==0) strcpy(GPIOTypeIndex,"0");
  else if(strcmp(gpioType, GPIOType[1])==0) strcpy(GPIOTypeIndex,"1");
  else if(strcmp(gpioType, GPIOType[2])==0) strcpy(GPIOTypeIndex,"2");
  else if(strcmp(gpioType, GPIOType[3])==0) strcpy(GPIOTypeIndex,"3");
  else if(strcmp(gpioType, GPIOType[4])==0) strcpy(GPIOTypeIndex,"4");
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
void Device::addGPIO(char* name, char* GPIOType, char* portName, char* pinNumber, char* pullType)
{  
    int size = headerPinSize+strlen(name)+strlen(GPIOType)+strlen(portName)+strlen(pinNumber)+strlen(pullType)+1;
    char* pinTmp = new char[size];
    json_data.initJson(pinTmp);
    json_data.addPair2JsonStr(pinTmp,"name",name);
    json_data.addPair2JsonStr(pinTmp,"GPIOType",GPIOType);
    json_data.addPair2JsonStr(pinTmp,"portName",portName);
    json_data.addPair2JsonStr(pinTmp,"pinNumber",pinNumber);
    json_data.addPair2JsonStr(pinTmp,"pullType",pullType);

    size += 2;//add "[]"  
    if(!jsonGPIOs)
    {
        jsonGPIOs = new char[size];
        json_data.initJsonArray(jsonGPIOs);
    }
    else
    {
        size = strlen(jsonGPIOs)+strlen(pinTmp)+1; //in the count we have to add ',' -> +1
        json_data.arrayResize(jsonGPIOs,size+1); 
    }
    json_data.add2Json(jsonGPIOs,pinTmp);
    delete[] pinTmp;
}

/* Function: Device.addFunction

    add an array of internal methods/functions  

    Prototype:
        void Device::addFunction(char* name, char* functionName);

    Parameters:
        name - the name of theobject
        functionName - the name of the method to call

    Returns:
        void
*/
void Device::addFunction(char* name, char* functionName)
{  
    int size = headerPinSize+strlen(name)+strlen(functionName)+1;
    char* fncTmp = new char[size];
    json_data.initJson(fncTmp);
    json_data.addPair2JsonStr(fncTmp,"name",name);
    json_data.addPair2JsonStr(fncTmp,"functionName",functionName);

    size += 2;//add "[]"  
    if(!jsonFunctions)
    {
        jsonFunctions = new char[size];
        json_data.initJsonArray(jsonFunctions);
    }
    else
    {
        size = strlen(jsonFunctions)+strlen(fncTmp)+1; //in the count we have to add ',' -> +1
        json_data.arrayResize(jsonFunctions,size+1); 
    }
    json_data.add2Json(jsonFunctions,fncTmp);
    delete[] fncTmp;
}

/* Function: Device.addFunction

    add an array of internal methods/functions  

    Prototype:
        void Device::addFunction(char* name, char* functionName);

    Parameters:
        name - the name of theobject
        functionName - the name of the method to call
        arg1 - the first argument of the function

    Returns:
        void
*/
void Device::addFunction(char* name, char* functionName, char* arg1)
{  
    int size = headerFunctionA1Size+strlen(name)+strlen(functionName)+strlen(arg1)+1;
    char* fncTmp = new char[size];
    json_data.initJson(fncTmp);
    json_data.addPair2JsonStr(fncTmp,"name",name);
    json_data.addPair2JsonStr(fncTmp,"functionName",functionName);
    json_data.addPair2JsonStr(fncTmp,"argument1",arg1);

    size += 2;//add "[]"  
    if(!jsonFunctions)
    {
        jsonFunctions = new char[size];
        json_data.initJsonArray(jsonFunctions);
    }
    else
    {
        size = strlen(jsonFunctions)+strlen(fncTmp)+1; //in the count we have to add ',' -> +1
        json_data.arrayResize(jsonFunctions,size+1); 
    }
    json_data.add2Json(jsonFunctions,fncTmp);
    delete[] fncTmp;
}

/* Function: Device.addFunction

    add an array of internal methods/functions  

    Prototype:
        void Device::addFunction(char* name, char* functionName);

    Parameters:
        name - the name of theobject
        functionName - the name of the method to call
        arg1 - the first argument of the function
        arg2 - the second argument of the function

    Returns:
        void
*/
void Device::addFunction(char* name, char* functionName, char* arg1, char* arg2)
{  
    int size = headerFunctionA2Size+strlen(name)+strlen(functionName)+strlen(arg1)+strlen(arg2)+1;
    char* fncTmp = new char[size];
    json_data.initJson(fncTmp);
    json_data.addPair2JsonStr(fncTmp,"name",name);
    json_data.addPair2JsonStr(fncTmp,"functionName",functionName);
    json_data.addPair2JsonStr(fncTmp,"argument1",arg1);
    json_data.addPair2JsonStr(fncTmp,"argument2",arg2);

    size += 2;//add "[]"  
    if(!jsonFunctions)
    {
        jsonFunctions = new char[size];
        json_data.initJsonArray(jsonFunctions);
    }
    else
    {
        size = strlen(jsonFunctions)+strlen(fncTmp)+1; //in the count we have to add ',' -> +1
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
    int size = strlen(json)+strlen(jsonGPIOs)+10;   //add ',"GPIOs":' and '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"GPIOs",jsonGPIOs);
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
