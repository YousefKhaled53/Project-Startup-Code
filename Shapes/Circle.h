#pragma once
#include "Shape.h"
#include "../controller.h"

class Circle :
    public shape
{
private:
	Point Center;
	Point radius;
	bool ishiden = false;

public:
	Circle(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& OutFile , int id);
	void Resize(double r);
	virtual string printforselection();
	void Rotate();
	void Move(Point P1, Point P2) {}
	bool is_in_fig(int x, int y);
	virtual void scramble();
	virtual void hide(GUI* pUI);
	virtual void setishidentrue();
	virtual void setishidenfalse();
	


};

