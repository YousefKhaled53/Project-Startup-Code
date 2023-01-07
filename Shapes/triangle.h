#pragma once
#include "Shape.h"
class triangle : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	bool ishiden = false;
<<<<<<< Updated upstream
	int ShapeID;

=======
>>>>>>> Stashed changes
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

};

