#pragma once
#include "Shape.h"
class triangle : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	triangle(Point, Point, Point, GfxInfo shapeGfxInfo);
	virtual ~triangle();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& OutFile, int id);
	bool is_in_fig(int x, int y);
	virtual string printforselection();
<<<<<<< Updated upstream
	virtual void scramble();
=======
	void Resize(double r);
	void Rotate();

>>>>>>> Stashed changes
};

