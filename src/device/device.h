#ifndef _device_
#define _device_

#include "../defines.h"

class Device
{
private:
    #define headerSize 25
    #define headerPinSize 68
    #define headerFunctionSize 29
    #define headerFunctionA1Size 44
    #define headerFunctionA2Size 59
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonGPIOs = nullptr;
    char* jsonFunctions = nullptr;

public:
// variable: Device.GPIOType

//     describes the type of the pin
///@param        char GPIOType[5][10] = {"out", "in", "analogIn", "analogOut", "pwm"};
    char GPIOType[5][10] = {"out", "in", "analogIn", "analogOut", "pwm"};

//     describes the type of the pull config
///@param        char pullType[3][5] = {"none", "up", "down"};
    char pullType[3][5] = {"none", "up", "down"};

// Function: Device.set

//     an object that describes the device from the hw perspective

//     Prototype:
//         void Device::set(char* name);

//     Parameters:
///@param         deviceId - it is the device Id 
///@param         name - it is the name of the device

//     Returns:
///@return         void
    void set(char* deviceId, char* name);
    
// Function: Device.gpioTypeIndex

//     turn the GPIOType into the corresponding index

//     Prototype:
//         void gpioTypeIndex(char* GPIOType, char* GPIOTypeIndex);

//     Parameters:
///@param         gpioType - the type of the pin: char pinTypes[5][10] = {"out", "in", "analogIn", "analogOut", "pwm"};
///@param         GPIOTypeIndex - the corresponding index to the GPIOtype

//     Returns:
///@return         void
    void gpioTypeIndex(char* gpioType, char* GPIOTypeIndex);

// Function: Device.addGPIO

//     add a GPIO to an array that describes the hw interface capabilities of the device

//     Prototype:
//         void Device::addGPIO(char* name, char* pinType, char* portName, int pinNumber, int value);

//     Parameters:
///@param         name - the name of the device
///@param         GPIOType - the type of the pin: char pinTypes[5][10] = {"out", "in", "analogIn", "analogOut", "pwm"};
///@param         portName - the name of the Port
///@param         pinNumber - the pin number
///@param         pullType - the status of the pull resistors (none, up , down)

//     Returns:
///@return         void
    void addGPIO(char* name, char* GPIOType, char* portName, char* pinNumber, char* pullType);
    
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
//         void Device::addFunction(char* name, char* functionName);

//     Parameters:
///@param         name - the name of theobject
///@param         functionName - the name of the method to call
///@param         arg1 - the first argument of the function
///@param         arg2 - the second argument of the function

//     Returns:
///@return         void
    void addFunction(char* name, char* functionName);
    void addFunction(char* name, char* functionName, char* arg1);
    void addFunction(char* name, char* functionName, char* arg1, char* arg2);

// Function: Device.appendFunctions

//     Append the selected functions

//     Prototype:
//         void Device::appendFunctions();

//     Parameters:

//     Returns:
///@return         void

    void appendFunctions();
    
// Function: Device.get

//     return the json script

//     Prototype:
//         void Device::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif