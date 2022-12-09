#include "Circle.h"
#include<iostream>
#include<fstream>
Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = P1;
	radius = P2;
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawCircle(Center, radius, ShpGfxInfo);
}
void Circle::Save(ofstream& OutFile) {
	OutFile << radius.x << radius.y;
	OutFile << Center.x << Center.y;
	OutFile << getid();
	/*OutFile << shape::getborderwidth();
	outfile << shape::getdrawclr();  // why error
	if (shape::getisfilled() == true) {
		outfile << shape::getfillclr();

	}
	else
	{
		OutFile << "no fill";
	}*/
}