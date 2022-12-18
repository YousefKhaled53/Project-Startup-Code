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
void line::Save(ofstream& OutFile , int id) {
	
	OutFile << "LINE" << " " << id << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";

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
	//double C1_x = Corner1.x;
	//double C2_x = Corner2.x;
	//double C1_y = Corner1.y;
	//double C2_y = Corner2.y;
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
string line::printforselection() {
	int LineLength = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	string msg = "selecteed shape is line with coordinates  (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")"
		" and (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")and Length ("+to_string(LineLength) + ")";
	return msg;
}
int* line::getparamters() {
	int* list = new int[4];
	list[0] = Corner1.x;
	list[1] = Corner2.y;
	list[2] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	list[3] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	return list;
}