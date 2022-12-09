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
	OutFile << Point1.x << Point1.y;
	OutFile << Point2.x << Point2.y;
	OutFile << getid();
	OutFile << shape::getborderwidth();
	/*outfile << shape::getdrawclr();  // why error 
	if (shape::getisfilled() == true) {
		outfile << shape::getfillclr();
	}
	else
	{
		OutFile << "no fill";
	}*/
}



