#pragma once
#include "../shapes/Shape.h"
class IrrPolygon :
    public shape
{
	private:
		Point* Point1;
		int Vertices_num=0;
		int *ArrX = new int[1000];
		int *ArrY = new int[1000];
	public:
		IrrPolygon(Point*, int, GfxInfo shapeGfxInfo);
		virtual ~IrrPolygon();
		virtual void Draw(GUI* pUI) const;
		virtual void Save(ofstream& OutFile , int id);
		bool is_in_fig(int x, int y);
		virtual string printforselection();
		int* getparamters();
};

