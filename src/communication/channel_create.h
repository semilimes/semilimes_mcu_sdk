#ifndef _channel_create_
#define _channel_create_

#include "../defines.h"

class ChannelCreate
{
private:
    SmeJson json_data;
    char** pjson;
    char** pjsonArray;
    
public:
// Function: ChannelCreate

//     This endpoint allows to create a new channel and set the initial editors. The role of the current accountId will be automatically set to editor.

//     Prototype:
//         void ChannelCreate(char* json);

//     Parameters:
///@param         json - it is the char array that will contain the whole json script 
///@param         jsonArray - it is a temporary char array that will contain the Editors 

//     Returns:
///@return         void
    ChannelCreate(char* json, char* jsonArray)
    {
        pjson = &json;
        pjsonArray = &jsonArray;
        json_data.initJson(*pjson);
        json_data.initJsonArray(*pjsonArray);
    }

// Function: ChannelCreate.setObj

//     This endpoint allows to create a new channel and set the initial editors. The role of the current accountId will be automatically set to editor.

//     Prototype:
//         void setObj(char* title,char* avatar,bool visible,bool locked);

//     Parameters:
///@param         title - sets the channel title
///@param         avatar -  takes a fileId (obtained by a File Upload endpoint) and sets the main avatar image of the channel
///@param         visible - sets the channel general visibility. If set to false, the channel will be only visible to its creator
///@param         locked - sets the channel's general edit permissions. If set to true, its content cannot be interacted by other users

//     Returns:
///@returns         void
    void setObj(char* title,char* avatar,bool visible,bool locked);

// Function: ChannelCreate.addEditorsIds

//     Prototype:
//         void addEditorsIds(char* data);

//     Append the selected editorId

//     Parameters:
///@param         data - the id of the editor to add

//     Returns:
///@returns        void
    void addEditorsIds(char* data);

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
///@returns         char* httpsUrl + endpoint
    char* getEPurl();
};

#endif