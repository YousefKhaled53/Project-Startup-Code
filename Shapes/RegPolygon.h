#pragma once
#include "../shapes/Shape.h"
class RegPolygon :
	public shape 
{
private:
	Point Center;
	Point* Point1;
	int distance;
	int Vertices_num ;
	int arrdiffinx[200]; 
	int arrdiffiny[200];
	int* ArrX = new int[2000];
	int* ArrY=new int[2000];
	int vertixx;
	int vertixy;
	bool ishiden = false;
	int ShapeID;
	bool isingroup = false;
public:
	RegPolygon(Point, Point*, int, GfxInfo shapeGfxInfo);
	virtual ~RegPolygon();
	virtual void Draw(GUI* pUI) const;
	void Resize(double r);
	void Move(Point P1, Point P2);
	void Rotate();
	virtual void Save(ofstream& OutFile , int id);
	bool is_in_fig(int x, int y);
	virtual string printforselection();
	virtual void scramble();
	void hide(GUI* pUI);
	virtual void setishidentrue();
	virtual void setishidenfalse();
	virtual bool getishiden();
	void setid(int i);
	int getid();
	//virtual void StickImage(GUI* pUI);


 
 
	shape* copy() ;
 

	virtual void setisingroup(bool b) {
		isingroup = b;
	}
	virtual bool getisingroup() {
		return isingroup;
	}
 
	 void ZOOM(double s);
 
};

