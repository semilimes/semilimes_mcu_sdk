#include "fc_label.h"

/* Function: FcLabel.setObj

    A simple read-only label

    Prototype:
        void FcLabel::setObj(char* refname,char* title);

    Parameters:
        refname - it is the reference name of the object
        title -  the label title

    Returns:
        void
*/
void FcLabel::setObj(char* refname,char* title)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"formComponentType","label");
    json_data.addPair2JsonStr(*pjson,"refName",refname);
    json_data.addPair2JsonStr(*pjson,"title",title);
}