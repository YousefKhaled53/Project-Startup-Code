#pragma once
#include "Shape.h"
class triangle : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	bool ishiden = false;
	int ShapeID;
	bool isingroup = false;
public:
	triangle(Point, Point, Point, GfxInfo shapeGfxInfo);
	virtual ~triangle();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& OutFile, int id);
	bool is_in_fig(int x, int y);
	virtual string printforselection();
	virtual void scramble();
	void Resize(double r);
	void Move(Point P1, Point P2);
	void Rotate();
	void hide(GUI* pUI);
	virtual void setishidentrue();
	virtual void setishidenfalse();
	virtual bool getishiden();
	void setid(int i);
	int getid();
 
 
 
	shape* copy();

	Point getP1();

	Point getP2();

	Point getP3();

	GfxInfo GetGfxInfo();
 

	virtual void setisingroup(bool b) {
		isingroup = b;
	}
	virtual bool getisingroup() {
		return isingroup;
	}
 
	 void ZOOM(double s);
	 //virtual void StickImage(GUI* pUI);
 
};

