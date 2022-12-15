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
	
	OutFile << "LINE" << " " << getid() << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";

	OutFile << shape::getdrawclr().getucred() << " ";
	OutFile << shape::getdrawclr().getucgreen() << " ";
	OutFile << shape::getdrawclr().getucblue() << " ";
	OutFile << shape::getborderwidth() << " ";
	OutFile << "///" << " ";
}
bool line::is_in_fig(int x, int y) {
	//if ((x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y))
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}
	return false;
}