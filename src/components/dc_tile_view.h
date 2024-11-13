#ifndef _fc_tile_view_
#define _fc_tile_view_

#include "../defines.h"

class DcTileView
{
private:
    SmeJson json_data;
    char* json = nullptr; 
    char* jsonArray = nullptr;

// Function: DcTileView.actionJson
//
//Prototype:
//    void DcTileView::actionJson(const char* action, const char* arg1, const char* arg2, bool arg3);
//
//Parameters:
///@param       action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
///@param       arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
///@param       arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
///@param       arg3 - openInForeground(response)
//
//Returns:
///@return    void
    char* actionJson(const char* action, const char* arg1, const char* arg2, bool arg3);

public:
//      indicates if the type of action to assign to a tile
//      opentile - This action opens a special bucket associated to the clicked tile.
//      openurl - This action enables the user to navigate to the specified URL upon clicking on the tile, whatever the tile type is
//      openbucket - This action enables the user to open a specified bucket (profile, channel, custom bucket).
//      openresource - This action enables the user to open a specified semilimes resource (tunnel, cloud).
//      response - This action triggers an automated message from the account where the tile resides to the account that clicks on the tile.
///@param        char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
    char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};

// Function: ~DcTileView

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~DcTileView()

//     Parameters:

//     Returns:
///@return         void
    ~DcTileView()
    {
        delete[] json;
        delete[] jsonArray;
        json = nullptr;
        jsonArray = nullptr;
    }

// Function: DcTileView.set
//
//    A message displaying a grid of tiles, customizable in position and size. Each tile can display different types of content. With this component you can define the height of the grid, and position the tiles accordingly.
//
//    Prototype:
//        void DcTileView::set(int row);
//
//    Parameters:
///@param        row - The tile view grid has N rows and 4 columns. The row and column indexes start from 0, and they are defined under the following display matrix (example: 0 1 means row0, col1):
//
//   Returns:
///@return        void
    void set(int grid);

// Function: DcTileView.addColorTile
//
//    Add a new color tile to the tile view.Each tile view can be positioned in this matrix by defining its row and column properties.
//    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)
//
//    Prototype:
//        void DcTileView::addColorTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* color,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);
//
//   Parameters:
///@param       refName - defines an internal custom reference name to identify the tile for further updates
///@param       title - defines a display title to show at the bottom of the tile itself
///@param       row - the row position of the tile
///@param       rowSpan - the row span of the tile
///@param       col - the column position of the tile
///@param       colSpan - the column span of the tile
///@param       color - the tile color
///@param       action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
///@param       arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
///@param       arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
///@param       arg3 - openInForeground(response)
//        
//   Returns:
///@return      void
    void addColorTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* color, const char* action, const char* arg1, const char* arg2="", bool arg3=false);

// Function: DcTileView.addIconTile
//
//    Add a new color tile to the tile view.Each tile view can be positioned in this matrix by defining its row and column properties.
//    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)
//
//    Prototype:
//        void DcTileView::addIconTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* color,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);
//
//   Parameters:
///@param       refName - defines an internal custom reference name to identify the tile for further updates
///@param       title - defines a display title to show at the bottom of the tile itself
///@param       row - the row position of the tile
///@param       rowSpan - the row span of the tile
///@param       col - the row position of the tile
///@param       colSpan - the column span of the tile
///@param       iconName - the name of the icon
///@param       iconColor - the color of the icon
///@param       backgroundColor - the background color of the icon
///@param       action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
///@param       arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
///@param       arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
///@param       arg3 - openInForeground(response)
//        
//   Returns:
///@return      void
    void addIconTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* iconName, const char* iconColor, const char* backgroundColor,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);

// Function: DcTileView.addPhotoTile
//
//    Add a new photo tile to the tile view.Each tile view can be positioned in this matrix by defining its row and column properties.
//    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)
//
//    Prototype:
//        void DcTileView::addPhotoTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* uuid,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);
//
//   Parameters:
///@param       refName - defines an internal custom reference name to identify the tile for further updates
///@param       title - defines a display title to show at the bottom of the tile itself
///@param       row - the row position of the tile
///@param       rowSpan - the row span of the tile
///@param       col - the col position of the tile
///@param       colSpan - the column span of the tile
///@param       uuid - the uuid of the photo file
///@param       action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
///@param       arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
///@param       arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
///@param       arg3 - openInForeground(response)
//        
//   Returns:
///@return      void
void addPhotoTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* uuid,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);

// Function: DcTileView.addPhotoUrlTile
//
//    Add a new photo url tile to the tile view.Each tile view can be positioned in this matrix by defining its row and column properties.
//    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)
//
//    Prototype:
//        void DcTileView::addPhotoUrlTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* photoUrl,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);
//
//   Parameters:
///@param       refName - defines an internal custom reference name to identify the tile for further updates
///@param       title - defines a display title to show at the bottom of the tile itself
///@param       row - the row position of the tile
///@param       rowSpan - the row span of the tile
///@param       col - the col position of the tile
///@param       colSpan - the column span of the tile
///@param       photoUrl - the url of the photo 
///@param       action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
///@param       arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
///@param       arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
///@param       arg3 - openInForeground(response)
//        
//   Returns:
///@return      void
void addPhotoUrlTile(const char* refName, const char* title,int row, int rowSpan, int col, int colSpan, const char* photoUrl, const char* action, const char* arg1, const char* arg2="", bool arg3=false);

// Function: DcTileView.addWebUrlTile
//
//    Add a new web url tile to the tile view.Each tile view can be positioned in this matrix by defining its row and column properties.
//    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)
//
//    Prototype:
//        void DcTileView::addWebUrlTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* url,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);
//
//   Parameters:
///@param       refName - defines an internal custom reference name to identify the tile for further updates
///@param       title - defines a display title to show at the bottom of the tile itself
///@param       row - the row position of the tile
///@param       rowSpan - the row span of the tile
///@param       col - the col position of the tile
///@param       colSpan - the column span of the tile
///@param       url - the web url 
///@param       action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
///@param       arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
///@param       arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
///@param       arg3 - openInForeground(response)
//        
//   Returns:
///@return      void
void addWebUrlTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* url,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);

// Function: DcTileView.addLiveWebUrlTile
//
//    Add a new live web url tile to the tile view.Each tile view can be positioned in this matrix by defining its row and column properties.
//    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)
//
//    Prototype:
//        void DcTileView::addLiveWebUrlTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* url,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);
//
//   Parameters:
///@param       refName - defines an internal custom reference name to identify the tile for further updates
///@param       title - defines a display title to show at the bottom of the tile itself
///@param       row - the row position of the tile
///@param       rowSpan - the row span of the tile
///@param       col - the col position of the tile
///@param       colSpan - the column span of the tile
///@param       url - the web url 
///@param       action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
///@param       arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
///@param       arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
///@param       arg3 - openInForeground(response)
//        
//   Returns:
///@return      void
void addLiveWebUrlTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* url,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);

// Function: DcTileView.addResourceTile
//
//    Add a new tile for viewing and interacting with a resource or a tunnel in the tile view.
//    Each tile view can be positioned in this matrix by defining its row and column properties.
//    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)
//
//    Prototype:
//        void DcTileView::addResourceTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* resourceId, const char* subPath,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);
//
//   Parameters:
///@param       refName - defines an internal custom reference name to identify the tile for further updates
///@param       title - defines a display title to show at the bottom of the tile itself
///@param       row - the row position of the tile
///@param       rowSpan - the row span of the tile
///@param       col - the col position of the tile
///@param       colSpan - the column span of the tile
///@param       resourceId - property takes a resource Id or a tunnel Id to be accessed. 
///@param       subPath - is for appending additional navigation to the main URL of the resource. Example: "/dashboard"
///@param       action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
///@param       arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
///@param       arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
///@param       arg3 - openInForeground(response)
//        
//   Returns:
///@return      void
void addResourceTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan,
 const char* resourceId, const char* subPath,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);
// Function: DcTileView.addSlideshowTile
//
//    Add a tile to display an automatic slideshow with default images provided by semilimes in the tile view.
//    Each tile view can be positioned in this matrix by defining its row and column properties.
//    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)
//
//    Prototype:
//        void DcTileView::addSlideshowTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);
//
//   Parameters:
///@param       refName - defines an internal custom reference name to identify the tile for further updates
///@param       title - defines a display title to show at the bottom of the tile itself
///@param       row - the row position of the tile
///@param       rowSpan - the row span of the tile
///@param       col - the col position of the tile
///@param       colSpan - the column span of the tile
///@param       action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
///@param       arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
///@param       arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
///@param       arg3 - openInForeground(response)
//        
//   Returns:
///@return      void
void addSlideshowTile(const char* refName, const char* title,int row, int rowSpan, int col, int colSpan, const char* action, const char* arg1, const char* arg2="", bool arg3=false);

// Function: DcTileView.addFormTile
//
//    Add a Form in the tile view. Each tile view can be positioned in this matrix by defining its row and column properties.
//    Additionally, you can define a rowSpan to make the tile occupy more rows (vertically), and a colSpan to make it occupy more columns (horizontally)
//
//    Prototype:
//        void DcTileView::addFormTile(const char* refName,const char* title,int row, int rowSpan, int col, int colSpan, const char* form,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);
//
//   Parameters:
///@param       refName - defines an internal custom reference name to identify the tile for further updates
///@param       title - defines a display title to show at the bottom of the tile itself
///@param       row - the row position of the tile
///@param       rowSpan - the row span of the tile
///@param       col - the col position of the tile
///@param       colSpan - the column span of the tile
///@param       form - the form json to embed
///@param       action - defines the type of action performed upon clicking on the tile. char actionType[5][13] = {"opentile", "openurl", "openbucket", "openresource", "response"};
///@param       arg1 - it depends on the selected action. It could be: dataComponents(opentile), webUrl(openurl), bucketId(openbucket), resourceId(openresource) or responseTemplateId(response)
///@param       arg2 - it depends on the selected action. It could be: subPath(openresource) or receiverId(response)
///@param       arg3 - openInForeground(response)
//        
//   Returns:
///@return      void
void addFormTile(const char* refName, const char* title,int row, int rowSpan, int col, int colSpan, const char* form,  const char* action, const char* arg1, const char* arg2="", bool arg3=false);

// Function: DcTileView.appendTiles

//     Append the selected tiles

//     Prototype:
//         void DcTileView::appendTiles();

//     Parameters:

//     Returns:
///@return         void
    void appendTiles();

// Function: DcTileView.get

//     return the json script

//     Prototype:
//         void DcTileView::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif