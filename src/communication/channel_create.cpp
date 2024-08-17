#include "channel_create.h"

/* Function: ChannelCreate.setObj

    This endpoint allows to create a new channel and set the initial editors. The role of the current accountId will be automatically set to editor.

    Prototype:
        void setObj(char* title,char* avatar,bool visible,bool locked);

    Parameters:
        title - sets the channel title
        avatar -  takes a fileId (obtained by a File Upload endpoint) and sets the main avatar image of the channel
        visible - sets the channel general visibility. If set to false, the channel will be only visible to its creator
        locked - sets the channel's general edit permissions. If set to true, its content cannot be interacted by other users

    Returns:
        void
*/
void ChannelCreate::setObj(char* title,char* avatar,bool visible,bool locked)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonStr(*pjson,"title",title);
    json_data.addPair2JsonStr(*pjson,"avatar",avatar);
	json_data.addPair2JsonBool(*pjson,"visible",visible);
	json_data.addPair2JsonBool(*pjson,"locked",locked);
}

/* Function: ChannelCreate.addEditorsIds

    Append the selected editorId

    Prototype:
        void addEditorsIds(char* data);

    Parameters:
        data - the id of the editor to add

    Returns:
        void
*/
void ChannelCreate::addEditorsIds(char* data)
{    
   json_data.add2JsonStr(*pjsonArray,data);
}

/* Function: ChannelCreate.appendEditorsIds

    Append the selected EditorsIds

    Prototype:
        void appendEditorsIds();

    Parameters:

    Returns:
        void
*/
void ChannelCreate::appendEditorsIds()
{
	json_data.add2JsonArray(*pjson,"editorIds",*pjsonArray);
}

/* Function: ChannelCreate.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* ChannelCreate::getEPurl()
{
    return httpsUrl communication_channel_create;
}