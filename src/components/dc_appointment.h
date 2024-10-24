#ifndef _dc_appointment_
#define _dc_appointment_

#include "../defines.h"

class DcAppointment
{
private:
    #define headerSize 89
    #define headerLocationSize 26
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;

// Function: DcAppointment.addLocation

//     define a specific location where to attend the appointment

//     Prototype:
//         void DcAppointment::addLocation(bool silent);

//     Parameters:
///@param         latitude - define the latitude of a specific location where to attend the appointment
///@param         longitude - define the longitude of a specific location where to attend the appointment
        
//    Returns:
///@return       void
    void addLocation(float latitude, float longitude);

public:
// Function: ~DcAppointment

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~DcAppointment()

//     Parameters:

//     Returns:
///@return         void
    ~DcAppointment()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: DcAppointment.set

//    An appointment message for defining a calendar event, complete with title, description, dates and location

//    Prototype:
//       void DcAppointment::set(char* title, char* description, int start, int end, bool allDay, float latitude, float longitude);

//    Parameters:
///@param         title - is for assigning the main title to the appointment. This parameter is required
///@param         description -  is for assigning an optional description to the event
///@param         start - is an epoch datetime for defining when the appointment will start
///@param         end - is an epoch datetime for defining when the appointment will end
///@param         allDay - is a boolean to determine if the appointment should cover all day, ignoring specific times of the selected start and end timestamps
///@param         latitude - define the latitude of a specific location where to attend the appointment
///@param         longitude - define the longitude of a specific location where to attend the appointment
//    Returns:
///@return       void
    void set(char* title, char* description, int start, int end, bool allDay, float latitude, float longitude);
    

// Function: DcAppointment.get

//     return the json script

//     Prototype:
//         void DcAppointment::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif