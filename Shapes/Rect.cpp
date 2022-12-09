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