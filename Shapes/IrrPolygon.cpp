#include "IrrPolygon.h"
#include<iostream>
#include<fstream>
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
void IrrPolygon::Save(ofstream& OutFile) {
	//OutFile << radius.x << radius.y;
	//OutFile << Center.x << Center.y;
	OutFile << getid();
	OutFile << shape::getborderwidth();
	OutFile << " draw colors rgb intensities are :" << "	";
	OutFile << "red intensity is " << shape::getdrawclr().getucred() << "	";
	OutFile << "blue intensity is " << shape::getdrawclr().getucblue() << "	";
	OutFile << "green intensity is " << shape::getdrawclr().getucgreen() << endl;
	OutFile << "fill color rgb intesities are:" << "	";
	if (shape::getisfilled() == true) {
		OutFile << shape::getfillclr().getucred();
		OutFile << shape::getfillclr().getucgreen();
		OutFile << shape::getfillclr().getucblue();
	}
	else
	{
		OutFile << "no fill";
	}
}