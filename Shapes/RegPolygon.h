#pragma once
#include "../shapes/Shape.h"
class RegPolygon :
	public shape 
{
private:
	Point Center;
	Point* Point1;
	int distance;
	int Vertices_num = 0;
	int arrdiffinx[200]; 
	int arrdiffiny[200];
	int* ArrX = new int[2000];
	int* ArrY=new int[2000];
	int vertixx;
	int vertixy;
public:
	RegPolygon(Point, Point*, int, GfxInfo shapeGfxInfo);
	virtual ~RegPolygon();
	virtual void Draw(GUI* pUI) const;
	void Resize(double r);
	void Rotate();
	virtual void Save(ofstream& OutFile , int id);
	bool is_in_fig(int x, int y);
	virtual string printforselection();
	virtual void scramble();
	void hide(GUI* pUI);
	virtual void setishidentrue();
	virtual void setishidenfalse();


};

