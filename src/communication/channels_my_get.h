#ifndef _channels_my_get_
#define _channels_my_get_

#include "../defines.h"

class ChannelsMyGet
{
private:
    #define headerSize 34
    SmeJson json_data;
    char* json = nullptr;
    
public:
// Function: ~ChannelsMyGet

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~ChannelsMyGet()

//     Parameters:

//     Returns:
///@return         void
    ~ChannelsMyGet()
    {
        delete[] json;
        json = nullptr;
    }

// Function: ChannelsMyGet.set

//     This endpoint retrieves the channels the calling user account is owner, editor or subscriber of.

//     Prototype:
//         void set(bool owner,bool editor,bool subscriber);

//     Parameters:
///@param         ownerId - Returns channels owned by the specified account Id
///@param         editorId - Returns channels whose editor is this account Id
///@param         title - Returns channels with this title

//     Returns:
///@returns         void
    void set(bool owner,bool editor,bool subscriber);

// Function: ChannelsMyGet.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
    
// Function: ChannelsMyGet.get

//     return the json script

//     Prototype:
//         void ChannelsMyGet::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif