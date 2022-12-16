#include "line.h"
#include<iostream>
#include<fstream>
#include <cmath>
#include <corecrt_math_defines.h>
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
	//int LineSlope = ((Corner2.y - Corner1.y) / (Corner2.x - Corner1.x));
	////double LineLength = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	//int Y_Intercept = (Corner1.y -(LineSlope * Corner1.x));
	//if ((y == (LineSlope * x) + Y_Intercept) /*&& min(Corner1.x, Corner2.x) <= x && x <= max(Corner1.x, Corner2.x)*/)
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}
	int LineLength = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	int Line1 = sqrt(pow((Corner1.x - x), 2) + pow((Corner1.y - y), 2));
	int Line2= sqrt(pow((x - Corner2.x), 2) + pow((y - Corner2.y), 2));
	if (Line1 + Line2 == LineLength) {
		return true;

	}
	else {
		return false;
	}
}