#include "Rect.h"
#include<iostream>
#include<fstream>

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}
void Rect::Save(ofstream& OutFile)
{
	OutFile << Corner1.x << Corner1.y;
	OutFile << shape::getborderwidth();
	OutFile << shape::getid();
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