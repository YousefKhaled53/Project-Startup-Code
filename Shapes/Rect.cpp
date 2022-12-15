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
	OutFile << endl;

	OutFile << "RECT ID: " << getid() <<endl ;
	OutFile << "corner1" << Corner1.x << " " << Corner1.y << endl;
	OutFile << "corner2" << Corner2.x << " " << Corner2.y << endl;

	OutFile <<"border width is " << shape::getborderwidth() << endl;
	OutFile << " draw colors rgb intensities are :" << endl;
	OutFile << "red intensity is " << shape::getdrawclr().getucred() << "	";
	OutFile << "blue intensity is " << shape::getdrawclr().getucblue() << "	";
	OutFile << "green intensity is " << shape::getdrawclr().getucgreen() << endl;
	OutFile << "fill color rgb intesities are:" << endl;
	if (shape::getisfilled() == true) {
		OutFile << shape::getfillclr().getucred()<<"  ";
		OutFile << shape::getfillclr().getucgreen()<<"  ";
		OutFile << shape::getfillclr().getucblue()<<"  ";
		OutFile << endl;
	}
	else
	{
		OutFile << "no fill"<<endl;
	}
	OutFile<< endl;
	OutFile<< "-------------------------------------------------------------------------------------------------------------" << endl;

}
bool Rect::is_in_fig(int x, int y) {
	if ((x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}