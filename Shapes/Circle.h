#pragma once
#include "Shape.h"
#include "../controller.h"

class Circle :
    public shape
{
private:
	Point Center;
	Point radius;

public:
	Circle(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& OutFile);
	virtual string printforselection();
	bool is_in_fig(int x, int y);

};

