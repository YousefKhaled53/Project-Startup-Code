#include "square.h"
#include<iostream>
#include<fstream>
#include <cmath>
#include <corecrt_math_defines.h>
square::square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner2.y = Corner1.y + (Corner2.x - Corner1.x);

}

square::~square()
{}
void square::Resize(double r) {
	Point npoint1 = Corner1;
	Point npoint2 = Corner2;


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
	Corner1 = npoint1;
	Corner2 = npoint2;

}
void square::Rotate() {
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

void square::Draw(GUI* pUI) const
{
	//Call Output::Drawsquare to draw a square on the screen	
	pUI->Drawsquare(Corner1, Corner2, ShpGfxInfo);
}
void square::Save(ofstream& OutFile , int id) {
	OutFile << "SQUARE" << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";

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
bool square::is_in_fig(int x, int y) {
	if ((x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y))
	{
		return true;
	}
	else if ((x < Corner1.x && x > Corner2.x && y > Corner1.y && y < Corner2.y))
	{
		return true;
	}
	else if ((x < Corner1.x && x > Corner2.x && y < Corner1.y && y > Corner2.y))
	{
		return true;
	}
	else if ((x > Corner1.x && x < Corner2.x && y < Corner1.y && y > Corner2.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}
string square::printforselection() {
	double Length = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	string msg = "selecteed shape is square with side length (" + to_string(Length) + ")";
	return msg;
}
void square::scramble() {
	int diffinx = abs((Corner1.x - Corner2.x));
	int diffiny = abs((Corner1.y - Corner2.y));
	Corner1.x = (rand() % 1300)-diffinx;
	Corner1.y = (50 + ( (rand()) % 600))-diffiny;
	Corner2.x = Corner1.x + diffinx;
	Corner2.y = Corner1.y + diffiny;
}
void square::hide(GUI* pUI) {};
void square::setishidentrue() {};// ishiden = true; };
void square::setishidenfalse() { };//ishiden = false; };
