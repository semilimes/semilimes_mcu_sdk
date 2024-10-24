#ifndef _fc_event_picker_
#define _fc_event_picker_

#include "../defines.h"

class FcEventPicker
{
private:
    #define headerSize 121
    #define headerArraySize 92
    #define headerArray2Size 2
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;
    char* jsonArray2 = nullptr;
    
public:
//     is a string that can hold list or buttons value. It will change how the events are displayed upon a date selection in the semilimes app
///@param        char eventsDisplayMode[2][8] = {"list", "buttons"};
char eventsDisplayMode[2][8] = {"list", "buttons"};

// Function: ~FcEventPicker

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~FcEventPicker()

//     Parameters:

//     Returns:
///@return         void
    ~FcEventPicker()
    {
        delete[] json;
        delete[] jsonArray;
        delete[] jsonArray2;
        json = nullptr;
        jsonArray = nullptr;
        jsonArray2 = nullptr;
    }

// Function: FcEventPicker.set

//     A calendar-shaped form component which allows the user to navigate through events and pick one or more for sending it out in a form submission

//     Prototype:
//         void FcEventPicker::set(char* refname, char* title, bool requiredSelection, bool multiSelection, char* eventsDisplayMode);

//     Parameters:
///@param         refname - it is the reference name of the object
///@param         title - is the global label displayed at the beginning of the component
///@param         reqSel - indicates if the selection is required to submit the form
///@param         reqSel - is a boolean to tell the form it can only have one or more events selected before submission
///@param         multiSelection - is a boolean to tell the form it can only have one or more events selected before submission
///@param         eventsDisplayMode - is a string that can hold list or buttons value. It will change how the events are displayed upon a date selection in the semilimes app: char eventsDisplayMode[2][8] = {"list", "buttons"};

//     Returns:
///@return         void
    void set(char* refname, char* title, bool reqSel, bool multiSelection, char* eventsDisplayMode);


// Function: FcEventPicker.addValue

//     is an array that contains one or more selected events when the form is submitted

//     Prototype:
//         void FcEventPicker::addValue(char* value);

//     Parameters:
///@param         value - the events when the form is submitted
        
//    Returns:
///@return       void
    void addValue(char* value);


// Function: FcEventPicker.appendValues

//     Prototype:
//         void FcEventPicker::appendValues();

//     Append the selected Values

///@param     Parameters:

//     Returns:
///@return         void
    void appendValues();


// Function: FcEventPicker.addEvent

//     is an array of predetermined events that populate the calendar widget displayed in the semilimes app

//     Prototype:
//         void FcEventPicker::addEvent(char* id, int start, char* title, char* description, char* referenceBucketId, char* additionalInfo);

//     Parameters:
///@param         id -  Arbitrary Unique Id assigned by client
///@param         start - Epoch milliseconds for event start
///@param         title - EventTitle
///@param         description - EventDescription
///@param         referenceBucketId - accepts any bucket GUID from semilimes environment, and allows the related event to display a details button that opens the destination bucket. The referenced bucket can be of any form (P2P/Group chat, channel, profile, bucket)
///@param         additionalInfo -  is an arbitrary object to keep hidden properties in the event and retrieve it upon submission.

//     Returns:
///@return         void
    void addEvent(char* id, int start, char* title, char* description, char* referenceBucketId, char* additionalInfo);


// Function: FcEventPicker.appendValues

//     Append the selected options

//     Prototype:
///@param        void FcEventPicker::appendValues()

//     Parameters:

//     Returns:
///@return         void
    void appendEvents();
    

// Function: FcEventPicker.get

//     return the json script

//     Prototype:
//         void FcEventPicker::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif