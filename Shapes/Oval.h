#pragma once
#include "Shape.h"
class Oval :
    public shape
{
private:
	Point Point1;
	Point Point2;
public:
	Oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Oval();
	virtual void Save(ofstream& OutFile , int id);
	virtual void Draw(GUI* pUI) const;
	bool is_in_fig(int x, int y);
	virtual string printforselection();
	virtual void scramble();
<<<<<<< Updated upstream
	void Resize(double r);
	void Rotate();
=======
	void hide(GUI* pUI);
	virtual void setishidentrue();
	virtual void setishidenfalse();

>>>>>>> Stashed changes
};


