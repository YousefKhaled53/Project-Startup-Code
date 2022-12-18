#include "Circle.h"
#include<iostream>
#include<fstream>
#include <cmath>
#include <corecrt_math_defines.h>
#include "../operations/operation.h"
#include "../GUI\GUI.h"
#include "../controller.h"
#include "../operations/opAddCircle.h"
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
void Circle::Save(ofstream& OutFile , int id) {

	OutFile << "CIRCLE" << " " << id << " " << Center.x << " " << Center.y << " " << radius.x << " " << radius.y << " ";

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
string Circle::printforselection() {
	int RadiusLength = sqrt(pow((radius.x - Center.x), 2) + pow((radius.y - Center.y), 2));
	string msg = "selecteed shape is circle with center coordinates  (" + to_string(Center.x) + ","+ to_string(Center.y) + ")"
		" and radius(" + to_string(radius.x) + ", "+ to_string(radius.y) + ")and raduis Length ("+to_string(RadiusLength)+")";
	return msg;
}
int* Circle::getparamters() {
	int* list=new int[4];
	list[0] = Center.x;
	list[1] = Center.y;
	list[2] = 2*sqrt(pow((Center.x - radius.x), 2) + (pow((Center.y - radius.y), 2)));
	list[3] = 2 * sqrt(pow((Center.x - radius.x), 2) + (pow((Center.y - radius.y), 2)));
	return list;
}
int Circle::getx() { return Center.x; };
int Circle::gety() { return Center.y; };