#pragma once
#include "Shape.h"
#include "../controller.h"

class Circle :
    public shape
{
private:
	Point Center;
	Point radius;
	int ShapeID;
	bool ishiden = false;
	bool isingroup = false;
public:
	Circle(Point, Point, GfxInfo shapeGfxInfo);
	Circle( Circle* c1);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& OutFile , int id);
	void Resize(double r);
	virtual string printforselection();
	void Rotate();
	void Move(Point P1, Point P2);
	bool is_in_fig(int x, int y);
	virtual void scramble();
	virtual void hide(GUI* pUI);
	virtual void setishidentrue();
	virtual void setishidenfalse();
	virtual bool getishiden();
	void setid(int i);
	int getid();
	shape* copy();
	virtual void setisingroup(bool b) {
		isingroup = b;
	}
	virtual bool getisingroup() {
		return isingroup ;
	}

	void ZOOM(double  s);
 
	
 
};

