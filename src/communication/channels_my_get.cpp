#include "channels_my_get.h"

/* Function: ChannelsMyGet.set

    This endpoint retrieves the channels the calling user account is owner, editor or subscriber of.

    Prototype:
        void set(bool owner,bool editor,bool subscriber);

    Parameters:
        ownerId - Returns channels owned by the specified account Id
        editorId - Returns channels whose editor is this account Id
        title - Returns channels with this title

    Returns:
        void
*/
void ChannelsMyGet::set(bool owner,bool editor,bool subscriber)
{
    int size = strlen("{\"owner\":,\"editor\":,\"subscriber\":}")+json_data.boolStrSize(owner)+json_data.boolStrSize(editor)+json_data.boolStrSize(subscriber)+1;
    json = new char[size];

    json_data.initJson(json);
    json_data.addPair2JsonBool(json, "owner", owner);
    json_data.addPair2JsonBool(json, "editor", editor);
    json_data.addPair2JsonBool(json, "subscriber", subscriber);
}

/* Function: ChannelsMyGet.getEPurl

    provides the full url for this endpoint

    Prototype:
        char* getEPurl();

    Parameters:
       
    Returns:
        char* httpsUrl + endpoint
*/
char* ChannelsMyGet::getEPurl()
{
    return httpsUrl communication_channel_my;
}

/* Function: ChannelsMyGet.getWSEPurl

    provides this endpoint

    Prototype:
        char* getWSEPurl();

    Parameters:
       
    Returns:
        char* endpoint
*/
char* ChannelsMyGet::getWSEPurl()
{
    return communication_channel_my;
}

/* Function: ChannelsMyGet.get

    return the json script

    Prototype:
        void ChannelsMyGet::get();

    Parameters:

    Returns:
        char*
*/
char* ChannelsMyGet::get()
{
    return json;
}