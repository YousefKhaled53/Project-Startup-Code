#pragma once
#include "Shape.h"

class square :
    public shape
{
private:
	Point Corner1;
	Point Corner2;
	bool ishiden = false;
	int ShapeID;
	bool isingroup = false;
public:
	square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~square();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& OutFile , int id);
	bool is_in_fig(int x, int y);
	void Resize(double r);
	void Rotate(); 
	void Move(Point P1, Point P2);
	virtual string printforselection();
	virtual void scramble();
	void hide(GUI* pUI);
	virtual void setishidentrue();
	virtual void setishidenfalse();
	virtual bool getishiden();
	//virtual void    setisselectedfalse();
	void setid(int i);
	int getid();
 
 


	shape* copy();

	GfxInfo GetGfxInfo();

	Point getP1();

	Point getP2();
 

	virtual void setisingroup(bool b) {
		isingroup = b;
	}
	virtual bool getisingroup() {
		return isingroup;
	}
 
	 void ZOOM(double s);
	 //virtual void StickImage(GUI* pUI);

};

