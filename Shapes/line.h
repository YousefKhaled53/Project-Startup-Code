#pragma once

#include "Shape.h"
class line :public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~line();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& OutFile , int id);
	void Resize(double r);
	bool is_in_fig(int x, int y);
	virtual void scramble();
	virtual string printforselection();
	void Rotate();
	virtual void hide(GUI* pUI);
	virtual void setishidentrue();
	virtual void setishidenfalse();
};