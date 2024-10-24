#include "fc_event_picker.h"

/* Function: FcEventPicker.set

   A calendar-shaped form component which allows the user to navigate through events and pick one or more for sending it out in a form submission

    Prototype:
        void FcEventPicker::set(char* refname, char* title, bool requiredSelection, bool multiSelection, char* eventsDisplayMode);

    Parameters:
        refname - it is the reference name of the object
        title - is the global label displayed at the beginning of the component
        reqSel - indicates if the selection is required to submit the form
        reqSel - is a boolean to tell the form it can only have one or more events selected before submission
        multiSelection - is a boolean to tell the form it can only have one or more events selected before submission
        eventsDisplayMode - is a string that can hold list or buttons value. It will change how the events are displayed upon a date selection in the semilimes app: char eventsDisplayMode[2][8] = {"list", "buttons"};

    Returns:
        void
*/
void FcEventPicker::set(char* refname, char* title, bool reqSel, bool multiSelection, char* eventsDisplayMode)
{
    int size = headerSize+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+json_data.boolStrSize(multiSelection)+strlen(eventsDisplayMode)+1;//add '\0' for null-termination
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","eventpicker");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonBool(json,"multiSelection",multiSelection);
    json_data.addPair2JsonStr(json,"eventsDisplayMode",eventsDisplayMode);
}

/* Function: FcEventPicker.addValue

    is an array that contains one or more selected events when the form is submitted

    Prototype:
        void FcEventPicker::addValue(char* value);

    Parameters:
        value - the events when the form is submitted
        
   Returns:
      void
*/
void FcEventPicker::addValue(char* value)
{
    int size = headerArray2Size+strlen(value)+3; //add '\0' and \"\" 
    
    if(!jsonArray2)
    {
        jsonArray2 = new char[size+1];
        json_data.initJsonArray(jsonArray2);
    }
    else
    {
        size += strlen(jsonArray2)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
        json_data.arrayResize(jsonArray2,size+1); //add '\0' for null-termination
    }
    json_data.add2Json(jsonArray2,value);
}
/* Function: FcEventPicker.appendValues

    Prototype:
        void FcEventPicker::appendValues();

    Append the selected Values

    Parameters:

    Returns:
        void
*/
void FcEventPicker::appendValues()
{
    if(jsonArray2!=nullptr)
    {    
        int size = strlen(json)+strlen(jsonArray2)+10;   //add bytes for ',"value":' and '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"value",jsonArray2);
    }
}

/* Function: FcEventPicker.addEvent

    add an array of the names of the choices 

    Prototype:
        void FcEventPicker::addEvent(char* value);

    Parameters:
        id -  Arbitrary Unique Id assigned by client
        start - Epoch milliseconds for event start
        title - EventTitle
        description - EventDescription
        referenceBucketId - accepts any bucket GUID from semilimes environment, and allows the related event to display a details button that opens the destination bucket. The referenced bucket can be of any form (P2P/Group chat, channel, profile, bucket)
        additionalInfo -  is an arbitrary object to keep hidden properties in the event and retrieve it upon submission.

    Returns:
        void
*/
void FcEventPicker::addEvent(char* id, int start, char* title, char* description, char* referenceBucketId, char* additionalInfo)
{
    int size = headerArraySize+strlen(id)+json_data.intStrSize(start)+strlen(title)+strlen(description)+strlen(referenceBucketId)+strlen(additionalInfo)+1;
    char* optTemp = new char[size];
    json_data.initJson(optTemp);
    json_data.addPair2JsonStr(optTemp, "id", id);
    json_data.addPair2JsonInt(optTemp, "start", start);
    json_data.addPair2JsonStr(optTemp, "title", title);
    json_data.addPair2JsonStr(optTemp, "description", description);
    json_data.addPair2JsonStr(optTemp, "referenceBucketId", referenceBucketId);
    json_data.addPair2JsonStr(optTemp, "additionalInfo", additionalInfo);
    
    if(!jsonArray)
    {
        jsonArray = new char[size+1];
        json_data.initJsonArray(jsonArray);
    }
    else
    {
        size += strlen(jsonArray)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
        json_data.arrayResize(jsonArray,size+1); //add '\0' for null-termination
    }
    json_data.add2Json(jsonArray,optTemp);
}
    
/* Function: FcEventPicker.appendEvents

    Append the selected options

    Prototype:
        void FcEventPicker::appendEvents()

    Parameters:

    Returns:
        void
*/
void FcEventPicker::appendEvents()
{ 
    if(jsonArray!=nullptr)
    {
        int size = strlen(json)+strlen(jsonArray)+11;   //add bytes for ',"events":' and '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"events",jsonArray);
    }
}

/* Function: FcEventPicker.get

    return the json script

    Prototype:
        void FcEventPicker::get();

    Parameters:

    Returns:
        char*
*/
char* FcEventPicker::get()
{
    return json;
}
