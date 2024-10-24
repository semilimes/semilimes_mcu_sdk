#include "dc_appointment.h"

/* Function: DcAppointment.set

    An appointment message for defining a calendar event, complete with title, description, dates and location

    Prototype:
       void DcAppointment::set(char* title, char* description, int start, int end, bool allDay, float latitude, float longitude);

    Parameters:
        title - is for assigning the main title to the appointment. This parameter is required
        description -  is for assigning an optional description to the event
        start - is an epoch datetime for defining when the appointment will start
        end - is an epoch datetime for defining when the appointment will end
        allDay - is a boolean to determine if the appointment should cover all day, ignoring specific times of the selected start and end timestamps
        latitude - define the latitude of a specific location where to attend the appointment
        longitude - define the longitude of a specific location where to attend the appointment
    Returns:
        void
*/
void DcAppointment::set(char* title, char* description, int start, int end, bool allDay, float latitude, float longitude)
{
    int size = headerSize+strlen(title)+strlen(description)+json_data.intStrSize(start)+json_data.intStrSize(end)+json_data.boolStrSize(allDay)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"dataComponentType","appointment");
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonStr(json,"description",description);
    json_data.addPair2JsonInt(json,"start",start);
    json_data.addPair2JsonInt(json,"end",end);
    json_data.addPair2JsonBool(json,"allDay",allDay);
    this->addLocation(latitude, longitude);
}

/* Function: DcAppointment.addOptions

     define a specific location where to attend the appointment

     Prototype:
         void DcAppointment::addLocation(bool silent);

     Parameters:
        latitude - define the latitude of a specific location where to attend the appointment
        longitude - define the longitude of a specific location where to attend the appointment

    Returns:
        void
*/
void DcAppointment::addLocation(float latitude, float longitude)
{
    int ndigits = 6;
    int size = headerLocationSize+json_data.floatStrSize(latitude,ndigits)+json_data.floatStrSize(longitude,ndigits)+1;
    char* optTemp = new char[size];
    json_data.initJson(optTemp);
    json_data.addPair2JsonFloat(optTemp, "latitude", latitude);
    json_data.addPair2JsonFloat(optTemp, "longitude", longitude);
    size += strlen(json)+13;   //add bytes for ',"location":' and '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"location",optTemp);
}

/* Function: DcAppointment.get

    return the json script

    Prototype:
        void DcAppointment::get();

    Parameters:

    Returns:
        char*
*/
char* DcAppointment::get()
{
    return json;
}