#include "channel_create.h"

/* Function: ChannelCreate.set

    This endpoint allows to create a new channel and set the initial editors. The role of the current accountId will be automatically set to editor.

    Prototype:
        void set(char* title,char* avatar,bool visible,bool locked);

    Parameters:
        title - sets the channel title
        avatar -  takes a fileId (obtained by a File Upload endpoint) and sets the main avatar image of the channel
        visible - sets the channel general visibility. If set to false, the channel will be only visible to its creator
        locked - sets the channel's general edit permissions. If set to true, its content cannot be interacted by other users

    Returns:
        void
*/
void ChannelCreate::set(char* title,char* avatar,bool visible,bool locked)
{
    int size = headerSize+strlen(title)+strlen(avatar)+json_data.boolStrSize(visible)+json_data.boolStrSize(locked)+1;//add '\0' for null-termination
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"title",title);
    json_data.addPair2JsonStr(json,"avatar",avatar);
	json_data.addPair2JsonBool(json,"visible",visible);
	json_data.addPair2JsonBool(json,"locked",locked);
}

/* Function: ChannelCreate.addEditorsId

    Append the selected editorId

    Prototype:
        void addEditorsId(char* data);

    Parameters:
        data - the id of the editor to add

    Returns:
        void
*/
void ChannelCreate::addEditorsId(char* data)
{  
    int size = headerArraySize+strlen(data)+3; //add '\0' and \"\" 
    
    if(!jsonArray)
    {
        jsonArray = new char[size];
        json_data.initJsonArray(jsonArray);
    }
    else
    {
        size += strlen(jsonArray)-1; //in the count we have to subtract bytes for '[]' and add ',' -> -1
        json_data.arrayResize(jsonArray,size+1); //add '\0' for null-termination
    }
    json_data.add2JsonStr(jsonArray,data);
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
    int size = strlen(json)+strlen(jsonArray)+14;   //add ',"editorIds":' and '\0'
    json_data.arrayResize(json,size);
	json_data.add2JsonArray(json,"editorIds",jsonArray);
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

/* Function: ChannelCreate.get

    return the json script

    Prototype:
        void ChannelCreate::get();

    Parameters:

    Returns:
        char*
*/
char* ChannelCreate::get()
{
    return json;
}

