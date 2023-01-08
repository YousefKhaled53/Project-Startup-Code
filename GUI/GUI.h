#pragma once



#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
};




class GUI
{
	enum GUI_MODE	//Graphical user interface mode
	{
		MODE_DRAW,	//Drawing mode (startup mode)
		MODE_PLAY	//Playing mode
	};

	enum DrawMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_LINE,
		ICON_TRIANGLE,
		ICON_RECT,
		ICON_SQUARE,		//Recangle icon in menu
		ICON_CIRC,		//Circle icon in menu
		ICON_OVAL,
		ICON_REG_POLYGON,
		ICON_IRRPOLYGON,
		ICON_SAVE,
		ICON_LOAD,
		ICON_SWITCH,
		ICON_BORDER_SINGLE,
		ICON_PEN,
		ICON_BORDER_COLOR_SINGLE,
		ICON_BORDER_COLOR_GENERAL,
		ICON_BRUSH_SIGNLE,
		ICON_BRUSH_GENERAL,
		

		ICON_SELECT, 
		ICON_Multi_Select,
		ICON_STICK,
		//TODO: Add more icons names here
		ICON_DEL,

		ICON_EXIT,		//Exit icon

		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};
	enum ToolBar2 {
		ICON_ZOOM_IN,
		ICON_ZOOM_OUT,
		ICON_copy,
		ICON_CUT,
		ICON_paste,
		ICON_multidelete,
		ICON_sendtoback,
		ICON_MOVE,
		ICON_RESIZE,
		ICON_ROTATE,
		ICON_GROUP,
		ICON_UNGROUP,
		ICON_UNDO,
		ICON_REDO,
		ToolBar2
	};

	enum PlayMenuIcon //The icons of the Play menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here

		//TODO: Add more icons names here
		ICON_START,
		ICON_RESTART,
		ICON_hide,

		ICON_scramble,
		ICON_duplicate,
		ICON_TODRAW,
		ICON_EXIT2,
		PLAY_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};


	GUI_MODE InterfaceMode ;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color toolbarcolor;
	int PenWidth;			//width of the pen that draws shapes
	double Zoom; 
	Point ZoomMajor;
	/// Add more members if needed



	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	void GetButtonState();
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation
	buttonstate Drag(Point &P2);
	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	window* getwind();
	void CreateDrawToolBar() ;	//creates Draw mode toolbar & menu
	void CreateDrawToolBar2();
	void CreatePlayToolBar();	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearDrawToolBar() const;
	void Cleartoolbar2() const;	//Clears the drawing area

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void Drawline(Point P1, Point P2, GfxInfo LineGfxInfo) const;  //Draw a line
	void Drawtriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo) const; //Draw a triangle
	void Drawsquare(Point P1, Point P2, GfxInfo squareGfxInfo) const;  //Draw a square
	void DrawCircle(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a Circle
	void DrawOval(Point P1, Point P2, GfxInfo OvalGfxInfo) const; // Draw an Oval
	void DrawRegPolygon(int* Arrx, int* ArrY, int x, GfxInfo RegPolygonGfxInfo) const;
	void DrawIrrPolygon(int *Arrx, int *Arry, int x, GfxInfo IrrPolygonGfxInfo) const;
	void Setpenwidth(int n);
	void setcrntfillcolor(color newcolor);
	void setcrntdrawcolor(color newcolor);
	/*void ZOOM(double Z);*/
	


	
	///Make similar functions for drawing all other shapes.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	bool isinttoolbar(Point* p);

	~GUI();
};

