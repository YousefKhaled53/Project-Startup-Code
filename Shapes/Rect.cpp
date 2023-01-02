#include "Rect.h"
#include<iostream>
#include<fstream>

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ShapeID = ID;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}
void Rect::Save(ofstream& OutFile , int id)
{

	OutFile << "RECT" <<" " << ID<< " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
	
	OutFile << shape::getdrawclr().getucred() << " ";
	OutFile << shape::getdrawclr().getucgreen() << " ";
	OutFile << shape::getdrawclr().getucblue() << " ";
	if (shape::getisfilled() == true) {
		OutFile << shape::getfillclr().getucred()<<" ";
		OutFile << shape::getfillclr().getucgreen()<<" ";
		OutFile << shape::getfillclr().getucblue()<<" ";
	}
	else
	{
		OutFile << "NO_FILL" << " ";
	}
	OutFile << shape::getborderwidth() << " ";
	OutFile << "///"<<" ";
}
bool Rect::is_in_fig(int x, int y) {
	if ((x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y))
	{
		return true;
	}
	else if ((x < Corner1.x && x > Corner2.x && y > Corner1.y && y < Corner2.y))
	{
		return true;
	}
	else if ((x < Corner1.x && x > Corner2.x && y < Corner1.y && y > Corner2.y))
	{
		return true;
	}
	else if ((x > Corner1.x && x < Corner2.x && y < Corner1.y && y > Corner2.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}
string Rect::printforselection() {

	string msg = "selecteed shape is rectangle with corner coordinates  (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ") and (" + to_string(Corner2.x) + ", "+ to_string(Corner2.y) + ")";
	return msg;
}

void Rect::scramble() {

	int diffinx = ((Corner2.x - Corner1.x));
	int diffiny = ((Corner2.y - Corner1.y));
	Corner1.x = (rand() % 1300) - diffinx;
	Corner1.y = (50 + ((rand()) % 600))-diffiny;
	Corner2.x = Corner1.x + diffinx;
	Corner2.y = Corner1.y + diffiny;
}