#include "../Shapes/RegPolygon.h"
#include<iostream>
#include<fstream>

#include <corecrt_math_defines.h>
#include <cmath>
RegPolygon::RegPolygon(Point C, Point *P, int x, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = C;
	Point1 = P;
	Vertices_num = x;
		
	distance = sqrt(pow((Point1->x - Center.x), 2) + pow((Point1->y - Center.y), 2));
	
	for (int i = 0; i < x; i++) {
		vertixx = Center.x+ distance * cos(i *2* M_PI / x);
		vertixy = Center.y+distance * sin(i * 2*M_PI / x);
		ArrX[i] = vertixx;
		ArrY[i] = vertixy;
	}
}

RegPolygon::~RegPolygon()
{}

void RegPolygon::Draw(GUI* pUI) const
{
	//Call Output::DrawRegPolygon to draw a regular Polygon on the screen	
	pUI->DrawRegPolygon(ArrX, ArrY, Vertices_num, ShpGfxInfo);
}


void RegPolygon::Save(ofstream& OutFile , int id) {

	OutFile << "REGULAR" << " " << id << " " << Center.x << " " << Center.y << " " << Point1->x << " " << Point1->y << " "<<Vertices_num<<" ";

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
bool RegPolygon::is_in_fig(int x, int y) {
	double RadiusLength = sqrt(pow((Point1->x - Center.x), 2) + pow((Point1->y - Center.y), 2));
	double ClickLength = sqrt(pow((x - Center.x), 2) + pow((y - Center.y), 2));
	if (ClickLength <= RadiusLength) {
		return true;
	}
	else {
		return false;
	}
	return false;
}
string RegPolygon::printforselection() {

	string msg = "selecteed shape is Regular Polygon with  (" + to_string(Vertices_num) + ") Vertices";
	return msg;
}