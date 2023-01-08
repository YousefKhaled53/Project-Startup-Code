#pragma once
#include "../shapes/Shape.h"
class IrrPolygon :
    public shape
{
	private:
		Point* Point1;
		int Vertices_num=0;
		int arrdiffinx[200];
		int arrdiffiny[200];
		int *ArrX = new int[1000];
		int *ArrY = new int[1000];
		bool ishiden = false;
		int ShapeID;
		bool isingroup = false;
	public:
		IrrPolygon(Point*, int, GfxInfo shapeGfxInfo);
		virtual ~IrrPolygon();
		virtual void Draw(GUI* pUI) const;
		virtual void Save(ofstream& OutFile , int id);
		void Resize(double r) {
			double Rad=2;
			
			Point1->x = Rad;
			Point1->y = Rad;

		}
		void Rotate();
		void Move(Point P1, Point P2) {}
		bool is_in_fig(int x, int y);
		virtual string printforselection();
		virtual void scramble();
		virtual void hide(GUI* pUI);
		virtual void setishidentrue();
		virtual void setishidenfalse();
		virtual bool getishiden();
		void setid(int i);
		int getid();
 
 


		shape* copy();

		virtual void setisingroup(bool b) {
			isingroup = b;
		}
		virtual bool getisingroup() {
			return isingroup;
		}

 
		 void ZOOM(double s);
 
};

