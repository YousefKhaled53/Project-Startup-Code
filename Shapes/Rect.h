#pragma once

#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
	int ShapeID;
public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& OutFile , int id);
	bool is_in_fig(int x, int y);
	virtual string printforselection();

};

