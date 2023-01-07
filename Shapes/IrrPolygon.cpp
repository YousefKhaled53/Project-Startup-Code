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
	ShapeID = ID;


}

IrrPolygon::~IrrPolygon()
{}
void IrrPolygon::Rotate() {
	Point C1;
	double addx = 0;
	double addy = 0;
	for (int i = 0; i < Vertices_num; i++) {
		addx += ArrX[i];
		addy += ArrY[i];
	}


	C1.x = addx / Vertices_num;
	C1.y = addy / Vertices_num;
	for (int i = 0; i < Vertices_num; i++) {
		ArrX[i] -= C1.x; ArrY[i] -= C1.y;
	}

	Point temp;
	for (int i = 0; i < Vertices_num; i++) {
		temp.x = ArrX[i]; temp.y = ArrY[i];
		ArrX[i] = -temp.y; ArrY[i] = temp.x;
	}
	for (int i = 0; i < Vertices_num; i++) {
		ArrX[i] += C1.x; ArrY[i] += C1.y;
	}

}
void IrrPolygon::Draw(GUI* pUI) const
{
	
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawIrrPolygon(ArrX, ArrY, Vertices_num, ShpGfxInfo);
}


void IrrPolygon::Save(ofstream& OutFile , int id) {
	OutFile << "IRREGULAR" << " " << ShapeID <<" "<<Vertices_num << " " << Point1->x << " " << Point1->y << " ";

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
		if (ArrX[i] == x && ArrY[i] == y) {
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
void IrrPolygon::scramble() {
	/*
	for (int i = 0; i < 1; i++) {
		arrdiffinx[i] = abs((Point1->x - ArrX[i+1]));
		arrdiffiny[i] = abs((Point1->y - ArrY[i+1]));

	}
	Point1->x = (rand() % 1300) ;
	Point1->y = 50 + ((rand()) % 600);
	for (int i = 0; i < 1; i++) {
		ArrX[i] = (Point1->x + arrdiffinx[i+1]);
		ArrY[i] = (Point1->y + arrdiffiny[i+1]);
	}*/
}
void IrrPolygon::hide(GUI* pUI) {

};
void IrrPolygon::setishidentrue() { ishiden = true; };
void IrrPolygon::setishidenfalse() { ishiden = false; };
bool IrrPolygon::getishiden() {
	return ishiden;
}
void IrrPolygon::setid(int i) {
	ShapeID = i;
};
int IrrPolygon::getid() {
	return ShapeID;
}