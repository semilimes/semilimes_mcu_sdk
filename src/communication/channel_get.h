#ifndef _get_channels_
#define _get_channels_

#include "../defines.h"

class ChannelGet
{
private:
    SmeJson json_data;
    char* json = nullptr;
    
public:

// Function: ~ChannelGet

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~ChannelGet()

//     Parameters:

//     Returns:
///@return         void
    ~ChannelGet()
    {
        delete[] json;
        json = nullptr;
    }

// Function: ChannelGet.set

//     This endpoint finds channels based on specified parameters

//     Prototype:
//         void set(const char* ownerId,const char* editorId,const char* channelId,const char* title);

//     Parameters:
///@param     ownerId - Returns channels owned by the specified account Id
///@param     editorId - Returns channels whose editor is this account Id
///@param     channelId - Returns the channel with this id
///@param     title - Returns channels with this title


//     Returns:
///@returns        void
    void set(const char* ownerId,const char* editorId,const char* channelId,const char* title);

// Function: ChannelGet.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: ChannelGet.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();
    
// Function: ChannelGet.get

//     return the json script

//     Prototype:
//         void ChannelGet::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif