#include "channels_my_get.h"

/* Function: ChannelsMyGet.setObj

    This endpoint retrieves the channels the calling user account is owner, editor or subscriber of.

    Prototype:
        void setObj(bool owner,bool editor,bool subscriber);

    Parameters:
        ownerId - Returns channels owned by the specified account Id
        editorId - Returns channels whose editor is this account Id
        title - Returns channels with this title

    Returns:
        void
*/
void ChannelsMyGet::setObj(bool owner,bool editor,bool subscriber)
{
    json_data.initJson(*pjson);
    json_data.addPair2JsonBool(*pjson, "owner", owner);
    json_data.addPair2JsonBool(*pjson, "editor", editor);
    json_data.addPair2JsonBool(*pjson, "subscriber", subscriber);
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