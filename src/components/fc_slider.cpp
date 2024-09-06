#include "fc_slider.h"

/* Function: FcSlider.set

    A slider to let the user select a value by dragging its handle

    Prototype:
        void FcSlider::set(char* refname,char* title,bool reqSel,int value,int min,int max,int step);

    Parameters:
        refname - it is the reference name of the object
        title - is the text displayed next to the slider
        reqSel - indicates if the selection is required to submit the form
        value - is the value selected on the slider on initializing (sending the form) or submission
        min - is the value selected when slider is at its minimum
        max - is the value selected when slider is at its maximum
        step - s the value amount that sums or subtracts to the initial value at each slider minimum drag

    Returns:
        void
*/
void FcSlider::set(char* refname,char* title,bool reqSel,int value,int min,int max,int step)
{
    int size = headerSize+strlen(refname)+strlen(title)+json_data.boolStrSize(reqSel)+json_data.intStrSize(value)+json_data.intStrSize(min)+json_data.intStrSize(max)+json_data.intStrSize(step)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","slider");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonBool(json,"requiredSelection",reqSel);
    json_data.addPair2JsonInt(json,"value",value);
    json_data.addPair2JsonInt(json,"min",min);
    json_data.addPair2JsonInt(json,"max",max);
    json_data.addPair2JsonInt(json,"step",step);
}

/* Function: FcSlider.get

    return the json script

    Prototype:
        void FcSlider::get();

    Parameters:

    Returns:
        char*
*/
char* FcSlider::get()
{
    return json;
}