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
	OutFile << "irreg pol with  no of sides : " << Vertices_num << endl;
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
	OutFile << endl << "-----------------------------------------------------------------------";
}
bool IrrPolygon::is_in_fig(int x, int y) {
	//if ((x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y))
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}
	return false;
}