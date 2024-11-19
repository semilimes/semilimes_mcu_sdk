#ifndef _channel_create_
#define _channel_create_

#include "../defines.h"

class ChannelCreate
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;
    
public:
// Function: ~ChannelCreate

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~ChannelCreate()

//     Parameters:

//     Returns:
///@return         void
    ~ChannelCreate()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: ChannelCreate.set

//     This endpoint allows to create a new channel and set the initial editors. The role of the current accountId will be automatically set to editor.

//     Prototype:
//         void set(const char* title,const char* avatar,bool visible,bool locked);

//     Parameters:
///@param         title - sets the channel title
///@param         avatar -  takes a fileId (obtained by a File Upload endpoint) and sets the main avatar image of the channel
///@param         visible - sets the channel general visibility. If set to false, the channel will be only visible to its creator
///@param         locked - sets the channel's general edit permissions. If set to true, its content cannot be interacted by other users

//     Returns:
///@returns         void
    void set(const char* title,const char* avatar,bool visible,bool locked);

// Function: ChannelCreate.addEditorsId

//     Prototype:
//         void addEditorsId(const char* data);

//     Append the selected editorId

//     Parameters:
///@param         data - the id of the editor to add

//     Returns:
///@returns        void
    void addEditorsId(const char* data);

// Function: ChannelCreate.appendEditorsIds

//     Append the selected EditorsIds

//     Prototype:
//         void appendEditorsIds();

//     Parameters:

//     Returns:
///@returns         void
    void appendEditorsIds();

// Function: ChannelCreate.getEPurl

//     provides the full url for this endpoint

//     Prototype:
//         char* getEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* sme_httpsUrl + endpoint
    char* getEPurl();
    
// Function: ChannelCreate.getWSEPurl

//     provides this endpoint

//     Prototype:
//         char* getWSEPurl();

//     Parameters:
       
//     Returns:
///@returns         char* endpoint
    char* getWSEPurl();

// Function: ChannelCreate.get

//     return the json script

//     Prototype:
//         void ChannelCreate::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif