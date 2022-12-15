#include "triangle.h"
#include<iostream>
#include<fstream>
triangle::triangle (Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

triangle::~triangle()
{}

void triangle ::Draw(GUI* pUI) const
{
	//Call Output::Drawline to draw a line on the screen	
	pUI->Drawtriangle(Corner1, Corner2, Corner3, ShpGfxInfo);
}
void triangle::Save(ofstream& OutFile) {
	OutFile << "TRIANGLE" << " " << getid() << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " "<<Corner3.x<<" "<<Corner3.y<<" ";

	OutFile << shape::getdrawclr().getucred() << " ";
	OutFile << shape::getdrawclr().getucgreen() << " ";
	OutFile << shape::getdrawclr().getucblue() << " ";
	if (shape::getisfilled() == true) {
		OutFile << shape::getfillclr().getucred() << "  ";
		OutFile << shape::getfillclr().getucgreen() << "  ";
		OutFile << shape::getfillclr().getucblue() << "  ";
	}
	else
	{
		OutFile << "NO_FILL" << " ";
	}
	OutFile << shape::getborderwidth() << " ";
	OutFile << "///" << " ";
}
bool triangle::is_in_fig(int x, int y) {
	//	if ((x > Point1.x && x < Point2.x && y > Point1.y && y < Point2.y))
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	return false;
}