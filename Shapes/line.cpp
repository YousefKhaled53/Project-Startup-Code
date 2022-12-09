#include "line.h"
#include<iostream>
#include<fstream>
line::line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

line::~line()
{}

void line::Draw(GUI* pUI) const
{
	//Call Output::Drawline to draw a line on the screen	
	pUI->Drawline(Corner1, Corner2, ShpGfxInfo);
}
void line::Save(ofstream& OutFile) {
	OutFile << Corner1.x << Corner1.y;
	OutFile << Corner2.x << Corner2.y;
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