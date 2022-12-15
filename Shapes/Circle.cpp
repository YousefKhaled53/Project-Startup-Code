#include "Circle.h"
#include<iostream>
#include<fstream>
Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = P1;
	radius = P2;
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawCircle(Center, radius, ShpGfxInfo);
}
void Circle::Save(ofstream& OutFile) {
	OutFile<< endl;
	OutFile << "CIRC ID: " << getid() << endl;
	OutFile << " radius is: " << radius.x << "  " << radius.y << endl;
	OutFile << " center :" << Center.x << "  " << Center.y << endl;
	OutFile << "border width is " << shape::getborderwidth() << endl;
	OutFile << " draw colors rgb intensities are :" << endl;
	OutFile << "red intensity is " << shape::getdrawclr().getucred() << "	";
	OutFile << "blue intensity is " << shape::getdrawclr().getucblue() << "	";
	OutFile << "green intensity is " << shape::getdrawclr().getucgreen() << endl;
	OutFile << "fill color rgb intesities are:" << endl;
	if (shape::getisfilled() == true) {
		OutFile << shape::getfillclr().getucred() << "  ";
		OutFile << shape::getfillclr().getucgreen() << "  ";
		OutFile << shape::getfillclr().getucblue() << "  ";
		OutFile << endl;
	}
	else
	{
		OutFile << "no fill" << endl;
	}
	OutFile<< endl;
	OutFile<< "-------------------------------------------------------------------------------------------------------------" << endl;
}
bool Circle::is_in_fig(int x, int y) {
	//if ((x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y))
	//{
		//	return true;
	//}
	//else
	//{
	//	return false;
	//}
	return false;
}