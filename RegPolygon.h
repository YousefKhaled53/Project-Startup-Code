#pragma once
#include "shapes/Shape.h"
class RegPolygon :
    public shape
{
private:
	Point Center;
	Point Point1;
public:
	RegPolygon(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~RegPolygon();
	virtual void Draw(GUI* pUI) const;
};

