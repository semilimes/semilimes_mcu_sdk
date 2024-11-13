#include "dc_tile_view.h"

/* Function: DcTileView.set

    A message displaying a grid of tiles, customizable in position and size. Each tile can display different types of content. With this component you can define the height of the grid, and position the tiles accordingly.

    Prototype:
        void DcTileView::set(int row);

    Parameters:
        row - The tile view grid has N rows and 4 columns. The row and column indexes start from 0, and they are defined under the following display matrix (example: 0 1 means row0, col1):

    Returns:
        void
*/
void DcTileView::set(int row)
{

    int size = strlen("{\"rows\":}")+json_data.intStrSize(row)+1;
    char* rowTemp = new char[size];
    json_data.initJson(rowTemp);
    json_data.addPair2JsonInt(rowTemp, "rows", row);

    size = strlen("{\"dataComponentType\":\"tileview\",\"grid\":}")+size+1;//add '\0' for null-termination
    json = new char[size]; 

    json_data.initJson(json);
    json_data.addPair2JsonStr(json,"dataComponentType","tileview");
    json_data.addPair2Json(json,"grid",rowTemp);
}

/* Function: DcTileView.actionJson

    Prototype:
        void DcTileView::actionJson(const char* action, const char* arg1, const char* arg2, bool arg3);

    Parameters:
        action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
        arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
        arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
        arg3 - openInForeground(response)

    Returns:
        void
*/
char* DcTileView::actionJson(const char* action, const char* arg1, const char* arg2, bool arg3)
{
    int actionSize;
    if(action == actionType[0]) //"opentile"
    {
        actionSize = strlen("{\"tileActionType\":\"\",\"dataComponents\":\"\"}")+strlen(action)+strlen(arg1)+1;
        char* actionTemp = new char[actionSize];
        json_data.initJson(actionTemp);
        json_data.addPair2JsonStr(actionTemp, "tileActionType", action);
        json_data.addPair2JsonStr(actionTemp, "dataComponents", arg1);
        return actionTemp;
    }
    else if(action == actionType[1])    //"openurl"
    {
        actionSize = strlen("{\"tileActionType\":\"\",\"webUrl\":\"\"}")+strlen(action)+strlen(arg1)+1;
        char* actionTemp = new char[actionSize];
        json_data.initJson(actionTemp);
        json_data.addPair2JsonStr(actionTemp, "tileActionType", action);
        json_data.addPair2JsonStr(actionTemp, "webUrl", arg1);
        return actionTemp;
    }
    else if(action == actionType[2])    //"openbucket"
    {
        actionSize = strlen("{\"tileActionType\":\"\",\"bucketId\":\"\"}")+strlen(action)+strlen(arg1)+1;
        char* actionTemp = new char[actionSize];
        json_data.initJson(actionTemp);
        json_data.addPair2JsonStr(actionTemp, "tileActionType", action);
        json_data.addPair2JsonStr(actionTemp, "bucketId", arg1);
        return actionTemp;
    }
    else if(action == actionType[3])    //"openresource"
    {
        actionSize = strlen("{\"tileActionType\":\"\",\"resourceId\":\"\",\"subPath\":\"\"}")+strlen(action)+strlen(arg1)+strlen(arg2)+1;
        char* actionTemp = new char[actionSize];
        json_data.initJson(actionTemp);
        json_data.addPair2JsonStr(actionTemp, "tileActionType", action);
        json_data.addPair2JsonStr(actionTemp, "resourceId", arg1);
        json_data.addPair2JsonStr(actionTemp, "subPath", arg2);
        return actionTemp;
    }
    else if(action == actionType[4])    //"response"
    {
        actionSize = strlen("{\"tileActionType\":\"\",\"responseTemplateId\":\"\",\"receiverId\":\"\",\"openInForeground\":\"\"}")+strlen(action)+strlen(arg1)+strlen(arg2)+json_data.boolStrSize(arg3)+1;
        char* actionTemp = new char[actionSize];
        json_data.initJson(actionTemp);
        json_data.addPair2JsonStr(actionTemp, "tileActionType", action);
        json_data.addPair2JsonStr(actionTemp, "responseTemplateId", arg1);
        json_data.addPair2JsonStr(actionTemp, "receiverId", arg2);
        json_data.addPair2JsonBool(actionTemp, "openInForeground", arg3);
        return actionTemp;
    }
}

/* Function: DcTileView.addColorTile

    Add a new color tile to the tile view.Each tile view can be positioned in this matrix by defining its row and column properties.
    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)

    Prototype:
        void DcTileView::addColorTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* color, const char* action, const char* arg1, const char* arg2="", bool arg3=false);

   Parameters:
        refName - defines an internal custom reference name to identify the tile for further updates
        title - defines a display title to show at the bottom of the tile itself
        row - the row position of the tile
        rowSpan - the row span of the tile
        col - the column position of the tile
        colSpan - the column span of the tile
        action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
        arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
        arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
        arg3 - openInForeground(response)
        
   Returns:
      void
*/
void DcTileView::addColorTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* color, const char* action, const char* arg1, const char* arg2, bool arg3)
{    
    int posSize = strlen("{\"row\":,\"rowSpan\":,\"col\":,\"colSpan\":}")+json_data.intStrSize(row)+json_data.intStrSize(rowSpan)+json_data.intStrSize(col)+json_data.intStrSize(colSpan)+1;
    char* posTemp = new char[posSize];
    json_data.initJson(posTemp);
    json_data.addPair2JsonInt(posTemp, "row", row);
    json_data.addPair2JsonInt(posTemp, "rowSpan", rowSpan);
    json_data.addPair2JsonInt(posTemp, "col", col);
    json_data.addPair2JsonInt(posTemp, "colSpan", colSpan);

    int typeSize = strlen("{\"tileType\":\"color\",\"color\":\"\"}")+strlen(color)+1;
    char* typeTemp = new char[typeSize];
    json_data.initJson(typeTemp);
    json_data.addPair2JsonStr(typeTemp, "tileType", "color");
    json_data.addPair2JsonStr(typeTemp, "color", color);

    int actionSize = strlen(actionJson(action,arg1,arg2,arg3));

    int size = strlen("{\"refName\":\"\",\"title\":\"\",\"position\":,\"type\":,\"action\":}")+strlen(refName)+strlen(title)+posSize+typeSize+actionSize+1;
    char* temp = new char[size];
    json_data.initJson(temp);
    json_data.addPair2JsonStr(temp, "refName", refName);
    json_data.addPair2JsonStr(temp, "title", title);
	json_data.add2JsonArray(temp,"position",posTemp);
	json_data.add2JsonArray(temp,"type",typeTemp);
	json_data.add2JsonArray(temp,"action",actionJson(action,arg1,arg2,arg3));
    
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
    json_data.add2Json(jsonArray,temp);
}

/* Function: DcTileView.addIconTile

    Add a new color tile to the tile view.Each tile view can be positioned in this matrix by defining its row and column properties.
    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)

    Prototype:
        void DcTileView::addIconTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* iconName, const char* iconColor, const char* backgroundColor,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);

   Parameters:
        refName - defines an internal custom reference name to identify the tile for further updates
        title - defines a display title to show at the bottom of the tile itself
        row - the row position of the tile
        rowSpan - the row span of the tile
        col - the col position of the tile
        colSpan - the column span of the tile
        iconName - the name of the icon
        iconColor - the color of the icon
        backgroundColor - the background color of the icon
        action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
        arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
        arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
        arg3 - openInForeground(response)
        
   Returns:
      void
*/
void DcTileView::addIconTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* iconName, const char* iconColor, const char* backgroundColor,  const char* action, const char* arg1, const char* arg2, bool arg3)
{    
    int posSize = strlen("{\"row\":,\"rowSpan\":,\"col\":,\"colSpan\":}")+json_data.intStrSize(row)+json_data.intStrSize(rowSpan)+json_data.intStrSize(col)+json_data.intStrSize(colSpan)+1;
    char* posTemp = new char[posSize];
    json_data.initJson(posTemp);
    json_data.addPair2JsonInt(posTemp, "row", row);
    json_data.addPair2JsonInt(posTemp, "rowSpan", rowSpan);
    json_data.addPair2JsonInt(posTemp, "col", col);
    json_data.addPair2JsonInt(posTemp, "colSpan", colSpan);

    int typeSize = strlen("{\"tileType\":\"icon\",\"iconName\":\"\",\"iconColor\":\"\",\"backgroundColor\":\"\"}")+strlen(iconName)+strlen(iconColor)+strlen(backgroundColor)+1;
    char* typeTemp = new char[typeSize];
    json_data.initJson(typeTemp);
    json_data.addPair2JsonStr(typeTemp, "tileType", "icon");
    json_data.addPair2JsonStr(typeTemp, "iconName", iconName);
    json_data.addPair2JsonStr(typeTemp, "iconColor", iconColor);
    json_data.addPair2JsonStr(typeTemp, "backgroundColor", backgroundColor);

    int actionSize = strlen(actionJson(action,arg1,arg2,arg3));

    int size = strlen("{\"refName\":\"\",\"title\":\"\",\"position\":,\"type\":,\"action\":}")+strlen(refName)+strlen(title)+posSize+typeSize+actionSize+1;
    char* temp = new char[size];
    json_data.initJson(temp);
    json_data.addPair2JsonStr(temp, "refName", refName);
    json_data.addPair2JsonStr(temp, "title", title);
	json_data.add2JsonArray(temp,"position",posTemp);
	json_data.add2JsonArray(temp,"type",typeTemp);
	json_data.add2JsonArray(temp,"action",actionJson(action,arg1,arg2,arg3));
    
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
    json_data.add2Json(jsonArray,temp);
}

/* Function: DcTileView.addPhotoTile

    Add a new photo tile to the tile view.Each tile view can be positioned in this matrix by defining its row and column properties.
    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)

    Prototype:
        void DcTileView::addPhotoTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* uuid,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);

   Parameters:
        refName - defines an internal custom reference name to identify the tile for further updates
        title - defines a display title to show at the bottom of the tile itself
        row - the row position of the tile
        rowSpan - the row span of the tile
        col - the col position of the tile
        colSpan - the column span of the tile
        uuid - the uuid of the photo file
        action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
        arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
        arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
        arg3 - openInForeground(response)
        
   Returns:
      void
*/
void DcTileView::addPhotoTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* uuid,  const char* action, const char* arg1, const char* arg2, bool arg3)
{    
    int posSize = strlen("{\"row\":,\"rowSpan\":,\"col\":,\"colSpan\":}")+json_data.intStrSize(row)+json_data.intStrSize(rowSpan)+json_data.intStrSize(col)+json_data.intStrSize(colSpan)+1;
    char* posTemp = new char[posSize];
    json_data.initJson(posTemp);
    json_data.addPair2JsonInt(posTemp, "row", row);
    json_data.addPair2JsonInt(posTemp, "rowSpan", rowSpan);
    json_data.addPair2JsonInt(posTemp, "col", col);
    json_data.addPair2JsonInt(posTemp, "colSpan", colSpan);

    int typeSize = strlen("{\"tileType\":\"photo\",\"photo\":\"\"}")+strlen(uuid)+1;
    char* typeTemp = new char[typeSize];
    json_data.initJson(typeTemp);
    json_data.addPair2JsonStr(typeTemp, "tileType", "photo");
    json_data.addPair2JsonStr(typeTemp, "photo", uuid);

    int actionSize = strlen(actionJson(action,arg1,arg2,arg3));

    int size = strlen("{\"refName\":\"\",\"title\":\"\",\"position\":,\"type\":,\"action\":}")+strlen(refName)+strlen(title)+posSize+typeSize+actionSize+1;
    char* temp = new char[size];
    json_data.initJson(temp);
    json_data.addPair2JsonStr(temp, "refName", refName);
    json_data.addPair2JsonStr(temp, "title", title);
	json_data.add2JsonArray(temp,"position",posTemp);
	json_data.add2JsonArray(temp,"type",typeTemp);
	json_data.add2JsonArray(temp,"action",actionJson(action,arg1,arg2,arg3));
    
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
    json_data.add2Json(jsonArray,temp);
}

/* Function: DcTileView.addPhotoUrlTile

    Add a new photo url tile to the tile view.Each tile view can be positioned in this matrix by defining its row and column properties.
    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)

    Prototype:
        void DcTileView::addPhotoUrlTile(const char* refName, const char* title,int row, int rowSpan, int col, int colSpan, const char* photoUrl, const char* action, const char* arg1, const char* arg2="", bool arg3=false);

   Parameters:
        refName - defines an internal custom reference name to identify the tile for further updates
        title - defines a display title to show at the bottom of the tile itself
        row - the row position of the tile
        rowSpan - the row span of the tile
        col - the col position of the tile
        colSpan - the column span of the tile
        photoUrl - the url of the photo 
        action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
        arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
        arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
        arg3 - openInForeground(response)
        
   Returns:
      void
*/
void DcTileView::addPhotoUrlTile(const char* refName, const char* title,int row, int rowSpan, int col, int colSpan, const char* photoUrl, const char* action, const char* arg1, const char* arg2, bool arg3)
{    
    int posSize = strlen("{\"row\":,\"rowSpan\":,\"col\":,\"colSpan\":}")+json_data.intStrSize(row)+json_data.intStrSize(rowSpan)+json_data.intStrSize(col)+json_data.intStrSize(colSpan)+1;
    char* posTemp = new char[posSize];
    json_data.initJson(posTemp);
    json_data.addPair2JsonInt(posTemp, "row", row);
    json_data.addPair2JsonInt(posTemp, "rowSpan", rowSpan);
    json_data.addPair2JsonInt(posTemp, "col", col);
    json_data.addPair2JsonInt(posTemp, "colSpan", colSpan);

    int typeSize = strlen("{\"tileType\":\"photourl\",\"photoUrl\":\"\"}")+strlen(photoUrl)+1;
    char* typeTemp = new char[typeSize];
    json_data.initJson(typeTemp);
    json_data.addPair2JsonStr(typeTemp, "tileType", "photourl");
    json_data.addPair2JsonStr(typeTemp, "photoUrl", photoUrl);

    int actionSize = strlen(actionJson(action,arg1,arg2,arg3));

    int size = strlen("{\"refName\":\"\",\"title\":\"\",\"position\":,\"type\":,\"action\":}")+strlen(refName)+strlen(title)+posSize+typeSize+actionSize+1;
    char* temp = new char[size];
    json_data.initJson(temp);
    json_data.addPair2JsonStr(temp, "refName", refName);
    json_data.addPair2JsonStr(temp, "title", title);
	json_data.add2JsonArray(temp,"position",posTemp);
	json_data.add2JsonArray(temp,"type",typeTemp);
	json_data.add2JsonArray(temp,"action",actionJson(action,arg1,arg2,arg3));
    
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
    json_data.add2Json(jsonArray,temp);
}

/* Function: DcTileView.addWebUrlTile

    Add a new web url tile to the tile view.Each tile view can be positioned in this matrix by defining its row and column properties.
    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)

    Prototype:
        void DcTileView::addWebUrlTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* url,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);

   Parameters:
        refName - defines an internal custom reference name to identify the tile for further updates
        title - defines a display title to show at the bottom of the tile itself
        row - the row position of the tile
        rowSpan - the row span of the tile
        col - the col position of the tile
        colSpan - the column span of the tile
        url - the web url 
        action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
        arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
        arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
        arg3 - openInForeground(response)
        
   Returns:
      void
*/
void DcTileView::addWebUrlTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* url,  const char* action, const char* arg1, const char* arg2, bool arg3)
{    
    int posSize = strlen("{\"row\":,\"rowSpan\":,\"col\":,\"colSpan\":}")+json_data.intStrSize(row)+json_data.intStrSize(rowSpan)+json_data.intStrSize(col)+json_data.intStrSize(colSpan)+1;
    char* posTemp = new char[posSize];
    json_data.initJson(posTemp);
    json_data.addPair2JsonInt(posTemp, "row", row);
    json_data.addPair2JsonInt(posTemp, "rowSpan", rowSpan);
    json_data.addPair2JsonInt(posTemp, "col", col);
    json_data.addPair2JsonInt(posTemp, "colSpan", colSpan);

    int typeSize = strlen("{\"tileType\":\"weburl\",\"webUrl\":\"\"}")+strlen(url)+1;
    char* typeTemp = new char[typeSize];
    json_data.initJson(typeTemp);
    json_data.addPair2JsonStr(typeTemp, "tileType", "weburl");
    json_data.addPair2JsonStr(typeTemp, "webUrl", url);

    int actionSize = strlen(actionJson(action,arg1,arg2,arg3));

    int size = strlen("{\"refName\":\"\",\"title\":\"\",\"position\":,\"type\":,\"action\":}")+strlen(refName)+strlen(title)+posSize+typeSize+actionSize+1;
    char* temp = new char[size];
    json_data.initJson(temp);
    json_data.addPair2JsonStr(temp, "refName", refName);
    json_data.addPair2JsonStr(temp, "title", title);
	json_data.add2JsonArray(temp,"position",posTemp);
	json_data.add2JsonArray(temp,"type",typeTemp);
	json_data.add2JsonArray(temp,"action",actionJson(action,arg1,arg2,arg3));
    
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
    json_data.add2Json(jsonArray,temp);
}

/* Function: DcTileView.addLiveWebUrlTile

    Add a new live web url tile to the tile view.Each tile view can be positioned in this matrix by defining its row and column properties.
    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)

    Prototype:
        void DcTileView::addLiveWebUrlTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* url,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);

   Parameters:
        refName - defines an internal custom reference name to identify the tile for further updates
        title - defines a display title to show at the bottom of the tile itself
        row - the row position of the tile
        rowSpan - the row span of the tile
        col - the col position of the tile
        colSpan - the column span of the tile
        url - the web url 
        action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
        arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
        arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
        arg3 - openInForeground(response)
        
   Returns:
      void
*/
void DcTileView::addLiveWebUrlTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* url,  const char* action, const char* arg1, const char* arg2, bool arg3)
{    
    int posSize = strlen("{\"row\":,\"rowSpan\":,\"col\":,\"colSpan\":}")+json_data.intStrSize(row)+json_data.intStrSize(rowSpan)+json_data.intStrSize(col)+json_data.intStrSize(colSpan)+1;
    char* posTemp = new char[posSize];
    json_data.initJson(posTemp);
    json_data.addPair2JsonInt(posTemp, "row", row);
    json_data.addPair2JsonInt(posTemp, "rowSpan", rowSpan);
    json_data.addPair2JsonInt(posTemp, "col", col);
    json_data.addPair2JsonInt(posTemp, "colSpan", colSpan);

    int typeSize = strlen("{\"tileType\":\"liveweburl\",\"liveWebUrl\":\"\"}")+strlen(url)+1;
    char* typeTemp = new char[typeSize];
    json_data.initJson(typeTemp);
    json_data.addPair2JsonStr(typeTemp, "tileType", "liveweburl");
    json_data.addPair2JsonStr(typeTemp, "liveWebUrl", url);

    int actionSize = strlen(actionJson(action,arg1,arg2,arg3));

    int size = strlen("{\"refName\":\"\",\"title\":\"\",\"position\":,\"type\":,\"action\":}")+strlen(refName)+strlen(title)+posSize+typeSize+actionSize+1;
    char* temp = new char[size];
    json_data.initJson(temp);
    json_data.addPair2JsonStr(temp, "refName", refName);
    json_data.addPair2JsonStr(temp, "title", title);
	json_data.add2JsonArray(temp,"position",posTemp);
	json_data.add2JsonArray(temp,"type",typeTemp);
	json_data.add2JsonArray(temp,"action",actionJson(action,arg1,arg2,arg3));
    
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
    json_data.add2Json(jsonArray,temp);
}

/* Function: DcTileView.addResourceTile

    Add a new tile for viewing and interacting with a resource or a tunnel in the tile view.
    Each tile view can be positioned in this matrix by defining its row and column properties.
    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)

    Prototype:
        void DcTileView::addResourceTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan,
 const char* resourceId, const char* subPath,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);

   Parameters:
        refName - defines an internal custom reference name to identify the tile for further updates
        title - defines a display title to show at the bottom of the tile itself
        row - the row position of the tile
        rowSpan - the row span of the tile
        col - the col position of the tile
        colSpan - the column span of the tile
        resourceId - property takes a resource Id or a tunnel Id to be accessed. 
        subPath - is for appending additional navigation to the main URL of the resource. Example: "/dashboard"
        action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
        arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
        arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
        arg3 - openInForeground(response)
        
   Returns:
      void
*/
void DcTileView::addResourceTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* resourceId, const char* subPath,  const char* action, const char* arg1, const char* arg2, bool arg3)
{    
    int posSize = strlen("{\"row\":,\"rowSpan\":,\"col\":,\"colSpan\":}")+json_data.intStrSize(row)+json_data.intStrSize(rowSpan)+json_data.intStrSize(col)+json_data.intStrSize(colSpan)+1;
    char* posTemp = new char[posSize];
    json_data.initJson(posTemp);
    json_data.addPair2JsonInt(posTemp, "row", row);
    json_data.addPair2JsonInt(posTemp, "rowSpan", rowSpan);
    json_data.addPair2JsonInt(posTemp, "col", col);
    json_data.addPair2JsonInt(posTemp, "colSpan", colSpan);

    int typeSize = strlen("{\"tileType\":\"resource\",\"resourceId\":\"\",\"subPath\":\"\"}")+strlen(resourceId)+strlen(subPath)+1;
    char* typeTemp = new char[typeSize];
    json_data.initJson(typeTemp);
    json_data.addPair2JsonStr(typeTemp, "tileType", "resource");
    json_data.addPair2JsonStr(typeTemp, "resourceId", resourceId);
    json_data.addPair2JsonStr(typeTemp, "subPath", subPath);

    int actionSize = strlen(actionJson(action,arg1,arg2,arg3));

    int size = strlen("{\"refName\":\"\",\"title\":\"\",\"position\":,\"type\":,\"action\":}")+strlen(refName)+strlen(title)+posSize+typeSize+actionSize+1;
    char* temp = new char[size];
    json_data.initJson(temp);
    json_data.addPair2JsonStr(temp, "refName", refName);
    json_data.addPair2JsonStr(temp, "title", title);
	json_data.add2JsonArray(temp,"position",posTemp);
	json_data.add2JsonArray(temp,"type",typeTemp);
	json_data.add2JsonArray(temp,"action",actionJson(action,arg1,arg2,arg3));
    
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
    json_data.add2Json(jsonArray,temp);
}

/* Function: DcTileView.addSlideshowTile

    Add a tile to display an automatic slideshow with default images provided by semilimes in the tile view.
    Each tile view can be positioned in this matrix by defining its row and column properties.
    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)

    Prototype:
        void DcTileView::addSlideshowTile(const char* refName, const char* title,int row, int rowSpan, int col, int colSpan, const char* action, const char* arg1, const char* arg2="", bool arg3=false);

   Parameters:
        refName - defines an internal custom reference name to identify the tile for further updates
        title - defines a display title to show at the bottom of the tile itself
        row - the row position of the tile
        rowSpan - the row span of the tile
        col - the col position of the tile
        colSpan - the column span of the tile
        action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
        arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
        arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
        arg3 - openInForeground(response)
        
   Returns:
      void
*/
void DcTileView::addSlideshowTile(const char* refName, const char* title,int row, int rowSpan, int col, int colSpan, const char* action, const char* arg1, const char* arg2, bool arg3)
{    
    int posSize = strlen("{\"row\":,\"rowSpan\":,\"col\":,\"colSpan\":}")+json_data.intStrSize(row)+json_data.intStrSize(rowSpan)+json_data.intStrSize(col)+json_data.intStrSize(colSpan)+1;
    char* posTemp = new char[posSize];
    json_data.initJson(posTemp);
    json_data.addPair2JsonInt(posTemp, "row", row);
    json_data.addPair2JsonInt(posTemp, "rowSpan", rowSpan);
    json_data.addPair2JsonInt(posTemp, "col", col);
    json_data.addPair2JsonInt(posTemp, "colSpan", colSpan);

    int typeSize = strlen("{\"tileType\":\"slideshow\"}")+1;
    char* typeTemp = new char[typeSize];
    json_data.initJson(typeTemp);
    json_data.addPair2JsonStr(typeTemp, "tileType", "slideshow");

    int actionSize = strlen(actionJson(action,arg1,arg2,arg3));

    int size = strlen("{\"refName\":\"\",\"title\":\"\",\"position\":,\"type\":,\"action\":}")+strlen(refName)+strlen(title)+posSize+typeSize+actionSize+1;
    char* temp = new char[size];
    json_data.initJson(temp);
    json_data.addPair2JsonStr(temp, "refName", refName);
    json_data.addPair2JsonStr(temp, "title", title);
	json_data.add2JsonArray(temp,"position",posTemp);
	json_data.add2JsonArray(temp,"type",typeTemp);
	json_data.add2JsonArray(temp,"action",actionJson(action,arg1,arg2,arg3));
    
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
    json_data.add2Json(jsonArray,temp);
}

/* Function: DcTileView.addFormTile

    Add a Form in the tile view. Each tile view can be positioned in this matrix by defining its row and column properties.
    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)

    Prototype:
        void DcTileView::addFormTile(const char* refName, const char* title,int row, int rowSpan, int col, int colSpan, const char* form,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);

   Parameters:
        refName - defines an internal custom reference name to identify the tile for further updates
        title - defines a display title to show at the bottom of the tile itself
        row - the row position of the tile
        rowSpan - the row span of the tile
        col - the col position of the tile
        colSpan - the column span of the tile
        form - the form json to embed
        action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
        arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
        arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
        arg3 - openInForeground(response)
        
   Returns:
      void
*/
void DcTileView::addFormTile(const char* refName, const char* title,int row, int rowSpan, int col, int colSpan, const char* form,  const char* action, const char* arg1, const char* arg2, bool arg3)
{    
    int posSize = strlen("{\"row\":,\"rowSpan\":,\"col\":,\"colSpan\":}")+json_data.intStrSize(row)+json_data.intStrSize(rowSpan)+json_data.intStrSize(col)+json_data.intStrSize(colSpan)+1;
    char* posTemp = new char[posSize];
    json_data.initJson(posTemp);
    json_data.addPair2JsonInt(posTemp, "row", row);
    json_data.addPair2JsonInt(posTemp, "rowSpan", rowSpan);
    json_data.addPair2JsonInt(posTemp, "col", col);
    json_data.addPair2JsonInt(posTemp, "colSpan", colSpan);

    int typeSize = strlen("{\"tileType\":\"form\",\"form\":\"\"}")+strlen(form)+1;
    char* typeTemp = new char[typeSize];
    json_data.initJson(typeTemp);
    json_data.addPair2JsonStr(typeTemp, "tileType", "form");
    json_data.addPair2Json(typeTemp, "form", form);

    int actionSize = strlen(actionJson(action,arg1,arg2,arg3));

    int size = strlen("{\"refName\":\"\",\"title\":\"\",\"position\":,\"type\":,\"action\":}")+strlen(refName)+strlen(title)+posSize+typeSize+actionSize+1;
    char* temp = new char[size];
    json_data.initJson(temp);
    json_data.addPair2JsonStr(temp, "refName", refName);
    json_data.addPair2JsonStr(temp, "title", title);
	json_data.add2JsonArray(temp,"position",posTemp);
	json_data.add2JsonArray(temp,"type",typeTemp);
	json_data.add2JsonArray(temp,"action",actionJson(action,arg1,arg2,arg3));
    
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
    json_data.add2Json(jsonArray,temp);
}

/* Function: DcTileView.appendTiles

    Append the selected tiles

    Prototype:
        void DcTileView::void DcTileView::appendTiles();

    Parameters:

    Returns:
        void
*/
void DcTileView::appendTiles()
{ 
    if(jsonArray!=nullptr)
    {
        int size = strlen(",\"tiles\":[]")+strlen(json)+strlen(jsonArray)+1;   //add byte '\0'
        json_data.arrayResize(json,size);
        json_data.add2JsonArray(json,"tiles",jsonArray);
    }
}

/* Function: DcTileView.get

    return the json script

    Prototype:
        void DcTileView::get();

    Parameters:

    Returns:
        char*
*/
char* DcTileView::get()
{
    return json;
}
