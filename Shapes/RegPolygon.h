#pragma once
#include "../shapes/Shape.h"
class RegPolygon :
	public shape 
{
private:
	Point Center;
	Point* Point1;
	int distance;
	int Vertices_num;
	int* ArrX=new int;
	int* ArrY=new int;
	int vertixx;
	int vertixy;
public:
	RegPolygon(Point, Point*, int, GfxInfo shapeGfxInfo);
	virtual ~RegPolygon();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& OutFile);
	bool is_in_fig(int x, int y);

};

