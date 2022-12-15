#include "square.h"
#include<iostream>
#include<fstream>
square::square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

square::~square()
{}

void square::Draw(GUI* pUI) const
{
	//Call Output::Drawsquare to draw a square on the screen	
	pUI->Drawsquare(Corner1, Corner2, ShpGfxInfo);
}
void square::Save(ofstream& OutFile) {
	OutFile << endl;

	OutFile << "SQUARE ID: " << getid() << endl;
	OutFile << "corner1" << Corner1.x << " " << Corner1.y << endl;
	OutFile << "corner2" << Corner2.x << " " << Corner2.y << endl;

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
bool square::is_in_fig(int x, int y) {
	if ((x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}