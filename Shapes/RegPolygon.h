#pragma once
#include "../shapes/Shape.h"
class RegPolygon :
	public shape 
{
private:
	Point Center;
	Point Point1;
	int distance;
	int Vertices_num;
	int* ArrX;
	int* Arry;
	int vertixx;
	int vertixy;
public:
	RegPolygon(Point, Point*, GfxInfo shapeGfxInfo);
	virtual ~RegPolygon();
	virtual void Draw(GUI* pUI) const;
};

