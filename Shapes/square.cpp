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
	//Call Output::DrawRect to draw a square on the screen	
	pUI->Drawsquare(Corner1, Corner2, ShpGfxInfo);
}
void square::Save(ofstream& Outfile) {
	Outfile << Corner1.x << Corner1.x;
	Outfile << Corner2.x << Corner2.x;
	Outfile << getid();
	Outfile<< " draw colors rgb intensities are :" << "	";
	Outfile << "red intensity is " << shape::getdrawclr().getucred() << "	";
	Outfile << "blue intensity is " << shape::getdrawclr().getucblue() << "	";
	Outfile << "green intensity is " << shape::getdrawclr().getucgreen() << endl;
	Outfile << "fill color rgb intesities are:" << "	";
	if (shape::getisfilled() == true) {
		Outfile << shape::getfillclr().getucred();
		Outfile << shape::getfillclr().getucgreen();
		Outfile << shape::getfillclr().getucblue();
	}
	else
	{
		Outfile << "no fill";
	}

}