#include "../Shapes/RegPolygon.h"
RegPolygon::RegPolygon(Point C, Point* P, int x, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = C;
	Point1 = P;
	Vertices_num = x;
	distance = sqrt(pow(Point1.x - Center.x)+pow(Point1.y-Center.y))
	for (int i = 0; i < x; i++) {
		vertixx = distance * cos(i * 360 / x);
		vertixy = distance * sin(i * 360 / x);
		ArrX[i] = vertixx;
		Arry[i] = vertixy;
	}
}

RegPolygon::~RegPolygon()
{}

void RegPolygon::Draw(GUI* pUI) const
{
	//Call Output::DrawRegPolygon to draw a regular Polygon on the screen	
	pUI->DrawRegPolygon(Center, Point1, ShpGfxInfo);
}