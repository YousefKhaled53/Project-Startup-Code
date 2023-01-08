#pragma once
#include "Shape.h"
class Oval :
    public shape
{
private:
	Point Point1;
	Point Point2;
	bool ishiden = false;
	int ShapeID;
	bool isingroup = false;
public:
	Oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Oval();
	virtual void Save(ofstream& OutFile , int id);
	virtual void Draw(GUI* pUI) const;
	bool is_in_fig(int x, int y);
	virtual string printforselection();
	void Move(Point P1, Point P2);
	virtual void scramble();
	void Resize(double r);
	void Rotate();
	void hide(GUI* pUI);
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
		return isingroup;
	}
 
	 void ZOOM(double s);
 

};


