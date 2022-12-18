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
	OutFile << "IRREGULAR" << " " << id <<" "<<Vertices_num << " " << Point1->x << " " << Point1->y << " ";

	for (int i = 0; i < Vertices_num; i++) {
		OutFile << ArrX[i]<< " "<<ArrY[i] << " ";
	}
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
int* IrrPolygon::getparamters() {
	int* list = new int[4];
		list[0] = 0;
		list[1] = 0;
		list[2] = 0;
		list[3] = 0;
		return list;

}
