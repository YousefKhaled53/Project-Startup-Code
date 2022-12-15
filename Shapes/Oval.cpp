#include "Oval.h"

#include<iostream>
#include<fstream>
Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}

Oval::~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawOval to draw a Oval on the screen	
	pUI->DrawOval(Point1, Point2, ShpGfxInfo);{}
}
void Oval::Save(ofstream& OutFile) {
	OutFile << endl;

	OutFile << "oval ID: " << getid() << endl;
	OutFile << "point1" << Point1.x << " " << Point1.y << endl;
	OutFile << "corner2" << Point2.x << " " << Point2.y << endl;

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
bool Oval::is_in_fig(int x, int y) {
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


