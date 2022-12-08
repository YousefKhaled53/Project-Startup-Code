#pragma once
#include "shapes/Shape.h"
class IrrPolygon :
    public shape
{
	private:
		Point Corner1;
		Point Corner2;
	public:
		IrrPolygon(Point, Point, GfxInfo shapeGfxInfo);
		virtual ~IrrPolygon();
		virtual void Draw(GUI* pUI) const;
};

