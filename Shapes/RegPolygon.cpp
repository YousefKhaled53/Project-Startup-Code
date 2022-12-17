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

<<<<<<< Updated upstream
void RegPolygon::Save(ofstream& OutFile , int id) {
	OutFile << "reg pol with  no of sides : " << Vertices_num << endl;
	OutFile << "center is  : " <<Center.x<<" "<<Center.y << endl;
	for (int i = 0; i < Vertices_num; i++) {
		OutFile << "point " << i << ": x coordinates of point : " << ArrX[i] << " y coordinates of point : " << ArrY[i] << endl;
	}
	/*
	OutFile << "border width is " << shape::getborderwidth() << endl;
	OutFile << " draw colors rgb intensities are :" << endl;
	OutFile << "red intensity is " << shape::getdrawclr().getucred() << "	";
	OutFile << "blue intensity is " << shape::getdrawclr().getucblue() << "	";
	OutFile << "green intensity is " << shape::getdrawclr().getucgreen() << endl;
	OutFile << "fill color rgb intesities are:" << endl;
=======
void RegPolygon::Save(ofstream& OutFile) {

	OutFile << "REGULAR" << " " << getid() << " " << Center.x << " " << Center.y << " " << Point1->x << " " << Point1->y << " ";

	OutFile << shape::getdrawclr().getucred() << " ";
	OutFile << shape::getdrawclr().getucgreen() << " ";
	OutFile << shape::getdrawclr().getucblue() << " ";
>>>>>>> Stashed changes
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