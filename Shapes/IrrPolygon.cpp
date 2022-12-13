/*#include "IrrPolygon.h"
#include<iostream>
#include<fstream>
IrrPolygon::IrrPolygon(Point *P1, int x, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Point1 = P1;
	Vertices_num = x;
	for (int i = 0; i < Vertices_num; i++) {
		Arrx[i] = Point1[i].x;
		Arry[i] = Point1[i].y;
	}

}

IrrPolygon::~IrrPolygon()
{}

void IrrPolygon::Draw(GUI* pUI) const
{
	
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawIrrPolygon(Arrx, Arry, Vertices_num; ShpGfxInfo);
}*/