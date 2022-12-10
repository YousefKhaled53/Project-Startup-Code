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
	OutFile << shape::getborderwidth();
	OutFile << " draw colors rgb intensities are :" << "	";
	OutFile << "red intensity is " << shape::getdrawclr().getucred() << "	";
	OutFile << "blue intensity is " << shape::getdrawclr().getucblue() << "	";
	OutFile << "green intensity is " << shape::getdrawclr().ucGreen << endl;
	OutFile << "fill color rgb intesities are:" << "	";
	if (shape::getisfilled() == true) {
		OutFile << shape::getfillclr().getucred();
		OutFile << shape::getfillclr().getucgreen();
		OutFile << shape::getfillclr().getucblue();
	}
	else
	{
		OutFile << "no fill";
	}
}