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
	OutFile << "OVAL" << " " << getid() << " " << Point1.x << " " << Point1.y << " " << Point2.x << " " << Point2.y << " ";

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


