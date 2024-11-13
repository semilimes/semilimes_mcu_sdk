#include "dc_gauge.h"

/* Function: DcGauge.set

    A gauge to show numerical data with a configurable ranges and colors

    Prototype:
        void DcGauge::set(const char* title,int thickness,int degrees,int spacing,int fontSize,int value,const char* displayValue,const char* pointer,const char* pointerColor,const char* progressBar,const char* progressBarColor);

    Parameters:
        refname - it is the reference name of the object
        title - is the global label displayed at the beginning of the component
        thickness - controls thickness of the gauge segments. Allowed values: 10-100
        degrees - specifies the angular space the gauge will be using. Allowed values: 30-360
        spacing - specifies the separation distance between segments. Allowed values: 0-20
        fontSize - determines the size of the displayValue near to the gauge. Allowed values: 8-48
        value - is the normalized value to control the gauge. Allowed values: 0-100
        displayValue - is a free field to show the actual value, or the actual value + unit of measure, or just a custom text
        pointer - shows a moving indicator on the gauge, depending on the value, and must have one of the following values: char pointer[4][9] = {"none", "triangle", "circle", "needle"};
        pointerColor - defines the RGB color of the pointer, if set. The allowed value is in the #[0-F][0-F][0-F][0-F][0-F][0-F] format
        progressBar - shows a progress bar moving on the arch of the gauge, depending on the value, and must have one of the following values: char progressBar[3][8] = {"none", "basic", "rounded"};
        progressBarColor - defines the RGB color of the progress bar, if set. The allowed value is in the #[0-F][0-F][0-F][0-F][0-F][0-F] format

    Returns:
        void
*/
void DcGauge::set(const char* title,int thickness,int degrees,int spacing,int fontSize,int value,const char* displayValue,const char* pointer,const char* pointerColor,const char* progressBar,const char* progressBarColor)
{
    int size = strlen("{\"dataComponentType\":\"gauge\",\"title\":\"\",\"thickness\":,\"degrees\":,\"spacing\":,\"fontSize\":,\"value\":,\"displayValue\":\"\",\"pointer\":\"\",\"pointerColor\":\"\",\"progressBar\":\"\",\"progressBarColor\":\"\"}")+strlen(title)+json_data.intStrSize(thickness)+json_data.intStrSize(degrees)+json_data.intStrSize(spacing)+json_data.intStrSize(fontSize)+json_data.intStrSize(value)+strlen(displayValue)+strlen(pointer)+strlen(pointerColor)+strlen(progressBar)+strlen(progressBarColor)+1;//add '\0' for null-termination
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"dataComponentType","gauge");
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonInt(json,"thickness",thickness);
    json_data.addPair2JsonInt(json,"degrees",degrees);
    json_data.addPair2JsonInt(json,"spacing",spacing);
    json_data.addPair2JsonInt(json,"fontSize",fontSize);
    json_data.addPair2JsonInt(json,"value",value);
    json_data.addPair2JsonStr(json,"displayValue",displayValue);
    json_data.addPair2JsonStr(json,"pointer",pointer);
    json_data.addPair2JsonStr(json,"pointerColor",pointerColor);
    json_data.addPair2JsonStr(json,"progressBar",progressBar);
    json_data.addPair2JsonStr(json,"progressBarColor",progressBarColor);
}

/* Function: DcGauge.addSegment

    is an array of the graphical segments composing the gauge

    Prototype:
        void DcGauge::addSegment(int from,int to,const char* color);

   Parameters:
        from - between the 0-99 range
        to - between the 1-100 range
        color - defines the RGB color of the pointer, if set. The allowed value is in the #[0-F][0-F][0-F][0-F][0-F][0-F] format
        
   Returns:
      void
*/
void DcGauge::addSegment(int from,int to,const char* color)
{
    int size = strlen("{\"from\":\"\",\"to\":\"\",\"color\":\"\"}")+json_data.intStrSize(from)+json_data.intStrSize(to)+strlen(color)+1;
    char* optTemp = new char[size];
    json_data.initJson(optTemp);
    json_data.addPair2JsonInt(optTemp, "from", from);
    json_data.addPair2JsonInt(optTemp, "to", to);
    json_data.addPair2JsonStr(optTemp, "color", color);
    
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

/* Function: DcGauge.appendSegments

    Append the selected Segments

    Prototype:
        void DcGauge::appendSegments();

    Parameters:

    Returns:
        void
*/
void DcGauge::appendSegments()
{ 
    if(jsonArray!=nullptr)
    {
        int size = strlen(json)+strlen(jsonArray)+13;   //add bytes for ',"segments":' and '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"segments",jsonArray);
    }
}

/* Function: DcGauge.get

    return the json script

    Prototype:
        void DcGauge::get();

    Parameters:

    Returns:
        char*
*/
char* DcGauge::get()
{
    return json;
}
