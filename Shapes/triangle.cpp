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
void triangle::Resize(double r) {
		Point npoint1 = Corner1;
		Point npoint2 = Corner2;
		Point npoint3 = Corner3;


		double Distance = abs(Corner2.x - Corner1.x);
		double x = Distance * 2 - Distance;
		if (npoint1.x > npoint2.x) {
			npoint1.x += x / 2;
			npoint2.x -= x / 2;
		}
		else {
			npoint1.x -= x / 2;
			npoint2.x += x / 2;
		}
		Distance = abs(Corner2.y - Corner1.y);
		if (npoint1.y > npoint2.y) {
			npoint1.y += x / 2;
			npoint2.y -= x / 2;
		}
		else {
			npoint1.y -= x / 2;
			npoint2.y += x / 2;
		}


		Distance = abs(Corner3.x - Corner2.x);
		x = Distance * 2 - Distance;
		if (npoint3.x > npoint2.x) {
			npoint3.x += x / 2;
		}
		else {
			npoint3.x -= x / 2;
		}
		Distance = abs(Corner2.y - Corner3.y);
		if (npoint3.y > npoint2.y) {
			npoint3.y += x / 2;
		}
		else {
			npoint3.y -= x / 2;
		}
		Corner1 = npoint1;
		Corner2 = npoint2;
		Corner3 = npoint3;
	}

void triangle::Rotate() {
	Point C1;
	C1.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	C1.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	Corner1.x -= C1.x; Corner1.y -= C1.y;
	Corner2.x -= C1.x; Corner2.y -= C1.y;
	Corner3.x -= C1.x; Corner3.y -= C1.y;
	Point temp;
	temp.x = Corner1.x; temp.y = Corner1.y;
	Corner1.x = -temp.y; Corner1.y = temp.x;

	temp.x = Corner2.x; temp.y = Corner2.y;
	Corner2.x = -temp.y; Corner2.y = temp.x;
	
	temp.x = Corner3.x; temp.y = Corner3.y;
	Corner3.x = -temp.y; Corner3.y = temp.x;


	Corner1.x += C1.x; Corner1.y += C1.y;
	Corner2.x += C1.x; Corner2.y += C1.y;
	Corner3.x += C1.x; Corner3.y += C1.y;
}
void triangle ::Draw(GUI* pUI) const
{
	//Call Output::Drawline to draw a line on the screen	
	pUI->Drawtriangle(Corner1, Corner2, Corner3, ShpGfxInfo);
}
void triangle::Save(ofstream& OutFile, int id) {
	OutFile << "TRIANGLE" << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " "<<Corner3.x<<" "<<Corner3.y<<" ";

	OutFile << shape::getdrawclr().getucred() << " ";
	OutFile << shape::getdrawclr().getucgreen() << " ";
	OutFile << shape::getdrawclr().getucblue() << " ";
	if (shape::getisfilled() == true) {
		OutFile << shape::getfillclr().getucred() << " ";
		OutFile << shape::getfillclr().getucgreen() << " ";
		OutFile << shape::getfillclr().getucblue() << " ";
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
void triangle::scramble() {

	int diffinx1 = abs((Corner1.x - Corner2.x));
	int diffiny1 = abs((Corner1.y - Corner2.y));
	int diffinx2 = abs((Corner1.x - Corner3.x));
	int diffiny2 = abs((Corner1.y - Corner3.y));
	Corner1.x = (rand() % 1300) - diffinx1;
	Corner1.y = (50 + ((rand()) % 600))-diffiny1;
	Corner2.x = Corner1.x + diffinx1;
	Corner2.y = Corner1.y + diffiny1;
	Corner3.x = Corner1.x + diffinx2;
	Corner3.y = Corner1.y + diffiny2;
}