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
	OutFile << endl;

	OutFile << "TRI ID: " << getid() << endl;
	OutFile << "corner1" << Corner1.x << " " << Corner1.y << endl;
	OutFile << "corner2" << Corner2.x << " " << Corner2.y << endl;
	OutFile << "corner2" << Corner3.x << " " << Corner3.y << endl;


	OutFile << "border width is " << shape::getborderwidth() << endl;
	OutFile << " draw colors rgb intensities are :" << endl;
	OutFile << "red intensity is " << shape::getdrawclr().getucred() << "	";
	OutFile << "blue intensity is " << shape::getdrawclr().getucblue() << "	";
	OutFile << "green intensity is " << shape::getdrawclr().getucgreen() << endl;
	OutFile << "fill color rgb intesities are:" << endl;
	if (shape::getisfilled() == true) {
		OutFile << shape::getfillclr().getucred() << "  ";
		OutFile << shape::getfillclr().getucgreen() << "  ";
		OutFile << shape::getfillclr().getucblue() << "  ";
		OutFile << endl;
	}
	else
	{
		OutFile << "no fill" << endl;
	}
	OutFile << endl;
	OutFile << "-------------------------------------------------------------------------------------------------------------" << endl;
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