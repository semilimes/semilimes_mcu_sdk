#ifndef _device_
#define _device_

#include "../defines.h"

class Device
{
private:
    SmeJson json_data;
    char** pjson;
    char** pjsonPins;
    char** pjsonFunctions;

public:
    Device(char* json, char* jsonPins, char* jsonFunctions)
    {
        pjson = &json;
        pjsonPins = &jsonPins;
        pjsonFunctions = &jsonFunctions;
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonPins);
        json_data.initJsonArray(*pjsonFunctions);
        json_data.addPair2JsonStr(*pjson,"dataComponentType","device");
    }
    char pinTypes[5][10] = {"out", "in", "analogIn", "analogOut", "pwm"};
    
// Function: Device.setObj

//     an object that describes the device from the hw perspective

//     Prototype:
//         void Device::setObj(char* name);

//     Parameters:
///@param         name - it is the name of the device

//     Returns:
///@return         void
    void setObj(char* name);
    
// Function: Device.addGPIO

//     add a GPIO to an array that describes the hw interface capabilities of the device

//     Prototype:
//         void Device::addGPIO(char* name, char* pinType, char* portName, int pinNumber, int value);

//     Parameters:
///@param         name - the name of the device
///@param         GPIOType - the type of the pin: char GPIOTypes[5][10] = {"out", "in", "analogIn", "analogOut", "pwm"};
///@param         portName - the name of the Port
///@param         pinNumber - the pin number
///@param         value - the status of the pin

//     Returns:
///@return         void
    void addGPIO(char* name, char* GPIOType, char* portName, int pinNumber, int value);
    
// Function: Device.appendGPIOs

//     Append the selected GPIO

//     Prototype:
//         void Device::appendGPIOs();

//     Parameters:

//     Returns:
///@return         void
    void appendGPIOs();

// Function: Device.addFunction

//     add an array of internal methods/functions  

//     Prototype:
//         void Device::addFunction(char* name, char* methodName);

//     Parameters:
///@param         name - the name of theobject
///@param         methodName - the name of the method to call

//     Returns:
///@return         void
    void addFunction(char* name, char* methodName);

// Function: Device.appendFunctions

//     Append the selected functions

//     Prototype:
//         void Device::appendFunctions();

//     Parameters:

//     Returns:
///@return         void

    void appendFunctions();
};

#endif