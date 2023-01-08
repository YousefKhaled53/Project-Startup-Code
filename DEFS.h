#ifndef DEFS_H
#define DEFS_H


//This file contais some global constants and definitions to be used in the project.
enum operationType //The operations supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_SQUARE,	//Draw Square
	DRAW_CIRC,		//Draw Circle
	DRAW_OVAL,		//Draw Oval
	DRAW_IRRPOLYGON,	//Draw IRRPolygon
	DRAW_REGPOLYGON,
	Pen_Width,
	Border_width,
	BORDER_COLOR_SINGLE,
	BORDER_COLOR_GENERAL,
	Border_color,
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	DEL,			//Delete a shape(s)
	MOVE,			//Move a shape(s)
	RESIZE,			//Resize a shape(s)
	ROTATE,			//Rotate a shape(s)
	SEND_BACK,		//Send a shape to the back of all shapes
	BRNG_FRNT,		//Bring a shape to the front of all shapes
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	BRUSH_SINGLE,
	BRUSH_GENERAL,
	BORDER_SINGLE,
	SELECT,         //select and unselect the shapes 
	MultiSelect,
	ZOOM_IN,
	ZOOM_OUT,
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	  
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,			//Switch interface to Play mode
	hide,
	scramble,
	duplicate,
	COPY,
	PASTE,
	MULTIDELTE,
	sendtoback,
	start,
	restart,

	todraw,
	GROUP,
	UNGROUP,
	undo,
	redo,
	cut,
	stick,

	///TODO: Add more operation types (if needed)
	//colors

};

#endif