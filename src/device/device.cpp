#include "device.h"

/* Function: Device.setObj

    an object that describes the device from the hw perspective

    Prototype:
        void Device::setObj(char* name);

    Parameters:
        name - the name of the object

    Returns:
        void
*/
void Device::setObj(char* name)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"name",name);
}


/* Function: Device.addGPIO

    add a GPIO to an array that describes the hw interface capabilities of the device

    Prototype:
        void Device::addGPIO(char* name, char* pinType, char* portName, int pinNumber, int value);

    Parameters:
        name - the name of the object
        GPIOType - defines the type of the pin, can be one of the following: char GPIOTypes[5][10] = {"out", "in", "analogIn", "analogOut", "pwm"};
        portName - the name of the hw port
        pinNumber - the pin number
        value - the value of the pin

    Returns:
        void
*/
void Device::addGPIO(char* name, char* GPIOType, char* portName, int pinNumber, int value)
{  
    char temp[200]="{}\0";
    json_data.addPair2JsonStr(temp,"name",name);
    json_data.addPair2JsonStr(temp,"pinType",GPIOType);
    json_data.addPair2JsonStr(temp,"portName",portName);
    json_data.addPair2JsonInt(temp,"pinNumber",pinNumber);
    json_data.addPair2JsonInt(temp,"value",value);
    json_data.add2Json(*pjsonPins,temp);
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
    char temp[200]="{}\0";
    json_data.addPair2JsonStr(temp,"name",name);
    json_data.addPair2JsonStr(temp,"methodName",methodName);
    json_data.add2Json(*pjsonFunctions,temp);
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
	json_data.add2JsonArray(*pjson,"pins",*pjsonPins);
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
	json_data.add2JsonArray(*pjson,"functions",*pjsonFunctions);
}
