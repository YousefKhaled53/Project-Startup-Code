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
	OutFile << Corner1.x << Corner1.y;
	OutFile << Corner2.x << Corner2.y;
	OutFile << Corner3.y << Corner3.y;
	OutFile << getid();
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