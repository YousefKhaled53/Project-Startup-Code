#include "Circle.h"
#include<iostream>
#include<fstream>
#include <cmath>
#include <corecrt_math_defines.h>
Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = P1;
	radius = P2;
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawCircle(Center, radius, ShpGfxInfo);
}
void Circle::Save(ofstream& OutFile) {

	OutFile << "CIRCLE" << " " << getid() << " " << Center.x << " " << Center.y << " " << radius.x << " " << radius.y << " ";

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
bool Circle::is_in_fig(int x, int y) {
	double RadiusLength = sqrt(pow((radius.x - Center.x), 2) + pow((radius.y - Center.y), 2));
	double ClickLength = sqrt(pow((x - Center.x), 2) + pow((y - Center.y), 2));
	if (ClickLength <= RadiusLength) {
		return true;
	}
	else {
		return false;
	}
	return false;
}