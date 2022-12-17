#include "Oval.h"

#include<iostream>
#include<fstream>
#include <cmath>
#include <corecrt_math_defines.h>
Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}

Oval::~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawOval to draw a Oval on the screen	
	pUI->DrawOval(Point1, Point2, ShpGfxInfo);{}
}
void Oval::Save(ofstream& OutFile) {
	OutFile << "OVAL" << " " << getid() << " " << Point1.x << " " << Point1.y << " " << Point2.x << " " << Point2.y << " ";

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
bool Oval::is_in_fig(int x, int y) {
	double h = (Point1.x + Point2.x)/2;
	double k = (Point1.y + Point2.y)/2;
	double a = sqrt(pow((Point1.x - h), 2));
	double b = sqrt(pow((Point1.y - k), 2));
	if ((pow((x - h), 2) / pow(a, 2)) + (pow((y - k), 2) / pow(b, 2)) <= 1) {
		return true;
	}
	else {
		return false;
	}
}
string Oval::printforselection() {
	int h = (Point1.x + Point2.x) / 2;
	int k = (Point1.y + Point2.y) / 2;
	int a = sqrt(pow((Point1.x - h), 2));
	int b = sqrt(pow((Point1.y - k), 2));
	string msg = "selecteed shape is Oval with center (" + to_string(h) + " ," + to_string(k) + ") and axis(" + to_string(a) + ") and (" + to_string(b) + ")";
	return msg;
}


