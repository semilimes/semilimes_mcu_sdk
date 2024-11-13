#include "fc_label.h"

/* Function: FcLabel.set

    A simple read-only label

    Prototype:
        void FcLabel::set(const char* refname,const char* title);

    Parameters:
        refname - it is the reference name of the object
        title -  the label title

    Returns:
        void
*/
void FcLabel::set(const char* refname,const char* title)
{
    int size = strlen("{\"formComponentType\":\"label\",\"refName\":\"\",\"title\":\"\"}")+strlen(refname)+strlen(title)+1;
    json = new char[size];
    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"formComponentType","label");
    json_data.addPair2JsonStr(json,"refName",refname);
    json_data.addPair2JsonStr(json,"title",title);
}

/* Function: FcLabel.get

    return the json script
    
    Prototype:
        void FcLabel::get();

    Parameters:

    Returns:
        char*
*/
char* FcLabel::get()
{
    return json;
}