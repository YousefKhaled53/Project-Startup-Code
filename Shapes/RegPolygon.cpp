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
void RegPolygon::Resize(double r) {
	
	for (int i = 0; i < Vertices_num; i++) {
		while (i < Vertices_num - 1) {
			Point npoint1;
			npoint1.x = ArrX[i]; npoint1.y = ArrY[i];
			Point npoint2;
			npoint2.x = ArrX[i + 1]; npoint2.y = ArrY[i + 1];
			double Distance = abs(ArrX[i] - ArrX[i + 1]);
			double x = Distance * 2 - Distance;
			if (npoint1.x > npoint2.x) {
				npoint1.x += x / 2;
				npoint2.x -= x / 2;
			}
			else {
				npoint1.x -= x / 2;
				npoint2.x += x / 2;
			}
			Distance = abs(ArrY[i] - ArrY[i + 1]);
			if (npoint1.y > npoint2.y) {
				npoint1.y += x / 2;
				npoint2.y -= x / 2;
			}
			else {
				npoint1.y -= x / 2;
				npoint2.y += x / 2;
			}
			ArrX[i] = npoint1.x;
			ArrY[i] = npoint1.y;
			ArrX[i + 1] = npoint2.x;
			ArrX[i + 1] = npoint2.y;
		}break;

		}
	}
void RegPolygon::Rotate() {
	Point C1 = Center;
	double addx = 0;
	double addy = 0;
	for (int i = 0; i < Vertices_num; i++) {
		addx += ArrX[i];
		addy += ArrY[i];
	}

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

void RegPolygon::Draw(GUI* pUI) const
{
	//Call Output::DrawRegPolygon to draw a regular Polygon on the screen	
	pUI->DrawRegPolygon(ArrX, ArrY, Vertices_num, ShpGfxInfo);
}


void RegPolygon::Save(ofstream& OutFile , int id) {

	OutFile << "REGULAR" << " " << ID << " " << Center.x << " " << Center.y << " " << Point1->x << " " << Point1->y << " "<<Vertices_num<<" ";

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

void RegPolygon::scramble() {

	/*int diffinx = abs((Center.x - Point1->x));
	int diffiny = abs((Center.y - Point1->y));
	for (int i = 0; i < 2; i++) {
		arrdiffinx[i] = abs((Center.x - ArrX[i]));
		arrdiffiny[i] = abs((Center.y - ArrY[i]));
		
	}
	Center.x = (rand() % 1300) ;
	Center.y = 50 + ((rand()) % 600);
	Point1->x = Center.x + diffinx;
	Point1->y = Center.y + diffiny;

	for (int i = 0; i < 2; i++) {
		ArrX[i] = (Center.x + arrdiffinx[i]);
		ArrY[i] = (Center.y + arrdiffiny[i]);
	
	}*/
	
}