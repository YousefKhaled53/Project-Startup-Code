#include "IrrPolygon.h"
#include<iostream>
#include<fstream>
#include <cmath>
#include <corecrt_math_defines.h>
IrrPolygon::IrrPolygon(Point *P1, int x, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Point1 = P1;
	Vertices_num = x;

	for (int i = 0; i < Vertices_num; i++) {
		ArrX[i] = Point1[i].x;
		ArrY[i] = Point1[i].y;
	}

}

IrrPolygon::~IrrPolygon()
{}

void IrrPolygon::Draw(GUI* pUI) const
{
	
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawIrrPolygon(ArrX, ArrY, Vertices_num, ShpGfxInfo);
}
void IrrPolygon::Save(ofstream& OutFile , int id) {
	OutFile << "irreg pol with  no of sides : " << Vertices_num << endl;
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
	if (shape::getisfilled() == true) {
		OutFile << shape::getfillclr().getucred() << "  ";
		OutFile << shape::getfillclr().getucgreen() << "  ";
		OutFile << shape::getfillclr().getucblue() << "  ";
		OutFile << endl;
	}
	else
	{
		OutFile << "no fill" << endl;
	}*/
	OutFile << endl << "-----------------------------------------------------------------------";
}
bool IrrPolygon::is_in_fig(int x, int y) {
	for (int i = 0; i < Vertices_num; i++) {
		//if (ArrX[i] <= x+1 || ArrX[i] >= x - 1 && ArrY[i] <= y+1 && ArrY[i] >= y -1 ) {
		if (ArrX[i] == x && ArrY[i] == y ){
		     return true;
		}
		else {
			return false;
		}
	}
}
string IrrPolygon::printforselection() {

	string msg = "selecteed shape is Irregular Polygon with  (" +to_string(Vertices_num) + ")Vertices";
	return msg;
}