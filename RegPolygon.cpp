#include "RegPolygon.h"
RegPolygon::RegPolygon(Point C, Point P, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = C;
	Point1 = P;
}

RegPolygon::~RegPolygon()
{}

void RegPolygon::Draw(GUI* pUI) const
{
	//Call Output::DrawRegPolygon to draw a regular Polygon on the screen	
	pUI->DrawRegPolygon(Center, Point1, ShpGfxInfo);
}