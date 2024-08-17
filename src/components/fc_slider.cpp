#include "fc_slider.h"

/* Function: FcSlider.setObj

    A slider to let the user select a value by dragging its handle

    Prototype:
        void FcSlider::setObj(char* refname,char* title,bool reqSel,int value,int min,int max,int step);

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
void FcSlider::setObj(char* refname,char* title,bool reqSel,int value,int min,int max,int step)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"formComponentType","slider");
    json_data.addPair2JsonStr(*pjson,"refName",refname);
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonBool(*pjson,"requiredSelection",reqSel);
    json_data.addPair2JsonInt(*pjson,"value",value);
    json_data.addPair2JsonInt(*pjson,"min",min);
    json_data.addPair2JsonInt(*pjson,"max",max);
    json_data.addPair2JsonInt(*pjson,"step",step);
}