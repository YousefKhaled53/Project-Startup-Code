#include "GUI.h"

GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1300;
	height = 650;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 60;

	DrawColor = BLUE;	//default Drawing color
	FillColor = GREEN;	//default Filling color
	MsgColor = BLACK;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
}


//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_RECT: return DRAW_RECT;
			case ICON_CIRC: return DRAW_CIRC;
			case ICON_EXIT: return EXIT;
			case ICON_OVAL: return DRAW_OVAL;
			case ICON_LINE: return DRAW_LINE;
			case ICON_SQUARE: return DRAW_SQUARE;
			case ICON_TRIANGLE: return DRAW_TRI;
			case ICON_SAVE: return SAVE;
			case ICON_SWITCH: return TO_PLAY;
			case ICON_IRRPOLYGON: return DRAW_IRRPOLYGON;
			case ICON_REG_POLYGON: return DRAW_REGPOLYGON;
			case ICON_LOAD: return LOAD;
			case ICON_PEN: return Pen_Width;
			case ICON_SELECT: return SELECT;
			case ICON_DEL: return DEL;
			case ICON_BRUSH_SIGNLE: return BRUSH_SINGLE;
			case ICON_BRUSH_GENERAL: return BRUSH_GENERAL;
			case ICON_BORDER_SINGLE:  return BORDER_SINGLE;
			case ICON_BORDER_COLOR_SINGLE: return BORDER_COLOR_SINGLE;
			case ICON_BORDER_COLOR_GENERAL: return BORDER_COLOR_GENERAL;
			case ICON_STICK_IMAGE: return STICK_IMAGE;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding operation
		return TO_PLAY;	//just for now. This should be updated
	}

}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
window* GUI::getwind() {
	return pWind;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
void GUI::ClearDrawToolBar() const {
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0,  width,ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{
	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\line.jpg";
	MenuIconImages[ICON_SQUARE] = "images\\MenuIcons\\Menu_square.jpg";
	MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\oval.jpg";
	MenuIconImages[ICON_TRIANGLE] = "images\\MenuIcons\\tri.jpg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\Menu_Save.jpg";
	MenuIconImages[ICON_SWITCH] = "images\\MenuIcons\\switch.jpg";
	MenuIconImages[ICON_IRRPOLYGON] = "images\\MenuIcons\\Menu_IrrPolygon.jpg";
	MenuIconImages[ICON_REG_POLYGON] = "images\\MenuIcons\\Menu_Reg.jpg";
	MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\Menu_Load.jpg";
	MenuIconImages[ICON_PEN] = "images\\MenuIcons\\Menu_Pen.jpg";
	MenuIconImages[ICON_SELECT] = "images\\MenuIcons\\Menu_SELECT.jfif";
	MenuIconImages[ICON_DEL] = "images\\MenuIcons\\Del.jpg";
	MenuIconImages[ICON_BRUSH_SIGNLE] = "images\\MenuIcons\\Menu_Brush1.jpg";
	MenuIconImages[ICON_BRUSH_GENERAL] = "images\\MenuIcons\\Menu_Brush2.jpg";
	MenuIconImages[ICON_BORDER_SINGLE] = "images\\MenuIcons\\Menu_Width.jpg";
<<<<<<< Updated upstream
	MenuIconImages[ICON_BORDER_COLOR_GENERAL] = "images\\MenuIcons\\Border_Color_General.jpg";
	MenuIconImages[ICON_BORDER_COLOR_SINGLE] = "images\\MenuIcons\\Border_Color_Single.jpg";
=======
	MenuIconImages[ICON_BORDER_COLOR_GENERAL] = "images\\MenuIcons\\Border_Color_General.jfif";
	MenuIconImages[ICON_BORDER_COLOR_SINGLE] = "images\\MenuIcons\\Border_Color_Single.jfif";
	MenuIconImages[ICON_STICK_IMAGE] = "images\\MenuIcons\\STICK_IMAGE.jpg";
>>>>>>> Stashed changes

	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar()
{
	InterfaceMode = MODE_PLAY;
	GUI::ClearStatusBar();
	GUI::ClearDrawToolBar();
	string MenuIconImages[PLAY_ICON_COUNT];
	MenuIconImages[ICON_hide] = "images\\MenuIcons\\unoip.jpg";
	MenuIconImages[ICON_un] = "images\\MenuIcons\\eye.jpg";
	MenuIconImages[ICON_Comingsoon] = "images\\MenuIcons\\soon.jpg";
	for (int i = 0; i < PLAY_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
	GUI::ClearStatusBar();
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}



//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::Drawline(Point P1, Point P2, GfxInfo lineGfxInfo) const
{
	color DrawingClr;
	if (lineGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = lineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, lineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (lineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(lineGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}

void GUI::Drawtriangle(Point P1, Point P2, Point P3, GfxInfo triangleGfxInfo) const
{
	color DrawingClr;
	if (triangleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = triangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, triangleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (triangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(triangleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle (P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void GUI::DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo) const
{
	color DrawingClr;
	if (CircleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y, sqrt(pow((P2.x-P1.x),2)+pow((P2.y-P1.y),2)), style);
	GUI::CreateStatusBar();
}

void GUI::DrawOval(Point P1, Point P2, GfxInfo OvalGfxInfo) const
{
	color DrawingClr;
	if (OvalGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = OvalGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, OvalGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (OvalGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(OvalGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);

}


void GUI::Drawsquare(Point P1, Point P2, GfxInfo SquareGfxInfo) const
{
	color DrawingClr;
	if (SquareGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SquareGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::DrawRegPolygon(int* Arrx, int* ArrY, int x, GfxInfo RegPolygonGfxInfo) const
{
	color DrawingClr;
	if (RegPolygonGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RegPolygonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RegPolygonGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RegPolygonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RegPolygonGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(Arrx, ArrY, x, style);
}
void GUI::setcrntfillcolor(color newcolor) {
	FillColor= newcolor;
}
void GUI::setcrntdrawcolor(color newcolor) {
	DrawColor = newcolor;
}


void GUI::DrawIrrPolygon(int* Arrx, int* Arry, int x, GfxInfo IrrPolygonGfxInfo) const
{
	color DrawingClr;
	if (IrrPolygonGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = IrrPolygonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, IrrPolygonGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (IrrPolygonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(IrrPolygonGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(Arrx, Arry, x, style);
}
void GUI::Setpenwidth(int n) {
	PenWidth = n;
}

/*void GUI::StickImage(string image, int x, int y, int width, int hight) const {
	pWind->DrawImage(image, x, y, width, hight);
}*/

//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

