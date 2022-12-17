#include "triangle.h"
#include<iostream>
#include<fstream>
#include <cmath>
#include <corecrt_math_defines.h>
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
	OutFile << "TRIANGLE" << " " << getid() << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " "<<Corner3.x<<" "<<Corner3.y<<" ";

	OutFile << shape::getdrawclr().getucred() << " ";
	OutFile << shape::getdrawclr().getucgreen() << " ";
	OutFile << shape::getdrawclr().getucblue() << " ";
	if (shape::getisfilled() == true) {
		OutFile << shape::getfillclr().getucred() << "  ";
		OutFile << shape::getfillclr().getucgreen() << "  ";
		OutFile << shape::getfillclr().getucblue() << "  ";
	}
	else
	{
		OutFile << "NO_FILL" << " ";
	}
	OutFile << shape::getborderwidth() << " ";
	OutFile << "///" << " ";
}
bool triangle::is_in_fig(int x, int y) {
	
	double TriArea = abs((Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - Corner2.y)) / 2.0);
	double TriArea1 = abs((x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - y) + Corner3.x * (y - Corner2.y)) / 2.0);
	double TriArea2 = abs((Corner1.x * (y - Corner3.y) + x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - y)) / 2.0);
	double TriArea3 = abs((Corner1.x * (Corner2.y - y) + Corner2.x * (y - Corner1.y) + x * (Corner1.y - Corner2.y)) / 2.0);
	if (TriArea1 + TriArea2 + TriArea3 == TriArea) {
		return true;
	}
	else {
		return false;
	}
}
string triangle::printforselection() {

	string msg = "selecteed shape is triangle with corner coordinates  (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")  and  (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ") and (" + to_string(Corner3.x) + ", " + to_string(Corner3.y) + ")";
	return msg;
}