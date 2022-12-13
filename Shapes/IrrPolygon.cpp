/*#include "IrrPolygon.h"
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
<<<<<<< Updated upstream
	pUI->DrawIrrPolygon(Arrx, Arry, Vertices_num; ShpGfxInfo);
}*/
=======
	pUI->DrawIrrPolygon(ArrX, ArrY, Vertices_num, ShpGfxInfo);
}
>>>>>>> Stashed changes
