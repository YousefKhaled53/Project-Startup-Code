#include "square.h"
#include<iostream>
#include<fstream>
#include <cmath>
#include <corecrt_math_defines.h>
square::square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

square::~square()
{}

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