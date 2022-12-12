#pragma once
#include "shapes/Shape.h"
class IrrPolygon :
    public shape
{
	private:
		Point Point1;
		int Vertices_num;
		int* ArrX;
		int* Arry;
	public:
		IrrPolygon(Point*, int, GfxInfo shapeGfxInfo);
		virtual ~IrrPolygon();
		virtual void Draw(GUI* pUI) const;
};

