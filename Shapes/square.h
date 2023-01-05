#pragma once
#include "Shape.h"

class square :
    public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~square();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& OutFile , int id);
	bool is_in_fig(int x, int y);
	void Resize(double r);
	void Rotate(); 
	void Move(Point P1, Point P2) {}

	virtual string printforselection();
	virtual void scramble();
	void hide(GUI* pUI);
	virtual void setishidentrue();
	virtual void setishidenfalse();

};

