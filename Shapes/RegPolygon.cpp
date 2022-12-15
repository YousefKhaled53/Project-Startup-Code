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

void RegPolygon::Save(ofstream& OutFile) {
	OutFile << "reg pol with  no of sides : " << Vertices_num << endl;
	for (int i = 0; i < (sizeof(ArrX) / sizeof(ArrX[0])); i++) {
		OutFile << "x coordinates of point : " << Point1->x << " y coordinates of point : " << Point1->y;
	}

	OutFile << "border width is " << shape::getborderwidth() << endl;
	OutFile << " draw colors rgb intensities are :" << endl;
	OutFile << "red intensity is " << shape::getdrawclr().getucred() << "	";
	OutFile << "blue intensity is " << shape::getdrawclr().getucblue() << "	";
	OutFile << "green intensity is " << shape::getdrawclr().getucgreen() << endl;
	OutFile << "fill color rgb intesities are:" << endl;
	if (shape::getisfilled() == true) {
		OutFile << shape::getfillclr().getucred() << "  ";
		OutFile << shape::getfillclr().getucgreen() << "  ";
		OutFile << shape::getfillclr().getucblue() << "  ";
		OutFile << endl;
	}
	else
	{
		OutFile << "no fill" << endl;
	}
}
bool RegPolygon::is_in_fig(int x, int y) {
	//	if ((x > Point1.x && x < Point2.x && y > Point1.y && y < Point2.y))
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	return false;
}