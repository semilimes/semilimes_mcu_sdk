#ifndef _channels_my_get_
#define _channels_my_get_

#include "../defines.h"

class ChannelsMyGet
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: ChannelsMyGet

//     This endpoint retrieves the channels the calling user account is owner, editor or subscriber of.

//     Prototype:
//         void ChannelsMyGet(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void    
    ChannelsMyGet(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: ChannelsMyGet.setObj

//     This endpoint retrieves the channels the calling user account is owner, editor or subscriber of.

//     Prototype:
//         void setObj(bool owner,bool editor,bool subscriber);

//     Parameters:
///@param         ownerId - Returns channels owned by the specified account Id
///@param         editorId - Returns channels whose editor is this account Id
///@param         title - Returns channels with this title

//     Returns:
///@returns         void
    void setObj(bool owner,bool editor,bool subscriber);

// Function: ChannelsMyGet.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif