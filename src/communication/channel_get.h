#ifndef _get_channels_
#define _get_channels_

#include "../defines.h"

class ChannelGet
{
private:
    SmeJson json_data;
    char** pjson;
    
public:
// Function: ChannelGet

//     This endpoint finds channels based on specified parameters

//     Prototype:
//         void ChannelGet(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 

//     Returns:
///@return         void
    ChannelGet(char* json)
    {
        pjson = &json;
        json_data.initJson(*pjson);
    }

// Function: ChannelGet.setObj

//     This endpoint finds channels based on specified parameters

//     Prototype:
//         void setObj(char* ownerId,char* editorId,char* channelId,char* title);

//     Parameters:
///@param     ownerId - Returns channels owned by the specified account Id
///@param     editorId - Returns channels whose editor is this account Id
///@param     channelId - Returns the channel with this id
///@param     title - Returns channels with this title


//     Returns:
///@returns        void
    void setObj(char* ownerId,char* editorId,char* channelId,char* title);

// Function: ChannelGet.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif