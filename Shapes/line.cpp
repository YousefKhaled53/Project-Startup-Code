#include "line.h"
#include<iostream>
#include<fstream>
#include <cmath>

#include <time.h>
#include "../GUI/GUI.h"
#include "../controller.h"
#include "../operations/operation.h"
#include <corecrt_math_defines.h>
line::line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ShapeID = ID;

}

line::~line()
{}

void line::Draw(GUI* pUI) const
{
	//Call Output::Drawline to draw a line on the screen	
	pUI->Drawline(Corner1, Corner2, ShpGfxInfo);
}
void line::Save(ofstream& OutFile , int id) {
	
	OutFile << "LINE" << " " << ShapeID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";

	OutFile << shape::getdrawclr().getucred() << " ";
	OutFile << shape::getdrawclr().getucgreen() << " ";
	OutFile << shape::getdrawclr().getucblue() << " ";
	OutFile << shape::getborderwidth() << " ";
	OutFile << "///" << " ";
}
void line::scramble() {
	int diffinx = abs((Corner1.x - Corner2.x));
	int diffiny = abs((Corner1.y - Corner2.y));
	do
	{
		Corner1.x = ((rand() % 1300)) - diffinx;
		Corner1.y = (50 + ((rand()) % 600)) - diffiny;
	} while (Corner1.x > (1300 - diffinx) || Corner1.y > (550 - diffiny) || Corner1.x < 50 || Corner1.y < 50);


	Corner2.x = Corner1.x + diffinx;
	Corner2.y = Corner1.y + diffiny;
};
void line::Move(Point P1, Point P2) {
	
	Corner1.x = P2.x - P1.x + Corner1.x;
	Corner2.x = P2.x - P1.x + Corner2.x;
	Corner1.y = P2.y - P1.y + Corner1.y;
	Corner2.y = P2.y - P1.y + Corner2.y;
}

	void line::Resize(double r) {
		Point npoint1 = Corner1;
		Point npoint2 = Corner2;


		double Distance = abs(Corner2.x - Corner1.x);
		double x = Distance * r - Distance;
		if (npoint1.x > npoint2.x) {
			npoint1.x += x / 2;
			npoint2.x -= x / 2;
		}
		else {
			npoint1.x -= x / 2;
			npoint2.x += x / 2;
		}
		Distance = abs(Corner2.y - Corner1.y);
		x = Distance * r - Distance;
		if (npoint1.y > npoint2.y) {
			npoint1.y += x / 2;
			npoint2.y -= x / 2;
		}
		else {
			npoint1.y -= x / 2;
			npoint2.y += x / 2;
		}
		Corner1 = npoint1;
		Corner2 = npoint2;

	};
	void line::Rotate() {
		Point C1;
		C1.x = (Corner1.x + Corner2.x) / 2;
		C1.y = (Corner1.y + Corner2.y) / 2;
		Corner1.x -= C1.x; Corner1.y -= C1.y;
		Corner2.x -= C1.x; Corner2.y -= C1.y;
		Point temp;
		temp.x = Corner1.x; temp.y = Corner1.y;
		Corner1.x = -temp.y; Corner1.y = temp.x;

		temp.x = Corner2.x; temp.y = Corner2.y;
		Corner2.x = -temp.y; Corner2.y = temp.x;


		Corner1.x += C1.x; Corner1.y += C1.y;
		Corner2.x += C1.x; Corner2.y += C1.y;

	}

	shape* line::copy() 
	{
		line* newLine = new line(Corner1, Corner2, ShpGfxInfo);
		return newLine;
	}
	

	;
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
		int Line2 = sqrt(pow((x - Corner2.x), 2) + pow((y - Corner2.y), 2));
		if (Line1 + Line2 == LineLength) {
			return true;

		}
		else {
			return false;
		}
	};
string line::printforselection() {
	int LineLength = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	string msg = "selecteed shape is line with coordinates  (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")"
		" and (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")and Length ("+to_string(LineLength) + ")";
	return msg;
}
void line::hide(GUI* pUI) {
	if (ishiden == true) {

		int width = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner1.y), 2));
		int height = sqrt(pow((Corner1.x - Corner1.x), 2) + pow((Corner1.y - Corner2.y), 2));

		pUI->getwind()->DrawImage("images\\MenuIcons\\unoip.jpg", min(Corner1.x, Corner2.x), min(Corner1.y, Corner2.y), width, height);
	}
}; void line::setishidentrue() { ishiden = true; };
void line::setishidenfalse() { ishiden = false; };
bool line::getishiden() {
	return ishiden;
}
void line::setid(int i) {
	ShapeID = i;
};
int line::getid() {
	return ShapeID;
}
void line::ZOOM(double s) {
	int x = 1300 / 2;
	int y = 650 / 2;
	Corner1.x = (Corner1.x * s)-(s * x) + x;
	Corner1.y = (Corner1.y * s) - (s * y) + y;
	Corner2.x = (Corner2.x * s)- (s * x) + x;
	Corner2.y = (Corner2.y * s)- (s * y) + y;
}
//void line::StickImage(GUI* pUI) {
//	if (ishiden == true) {
//
//		int width = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner1.y), 2));
//		int height = sqrt(pow((Corner1.x - Corner1.x), 2) + pow((Corner1.y - Corner2.y), 2));
//
//		pUI->getwind()->DrawImage("images\\MenuIcons\\Menu_Load.jpg", min(Corner1.x, Corner2.x), min(Corner1.y, Corner2.y), width, height);
//	}
Point line::getP1() {
	return Corner1;
}
Point line::getP2() {
	return Corner2;
}
GfxInfo line::GetGfxInfo()
{
	return ShpGfxInfo;
}
