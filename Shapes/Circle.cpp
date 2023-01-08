#include "Circle.h"
#include<iostream>
#include<fstream>
#include <cmath>
#include <corecrt_math_defines.h>
#include "../operations/operation.h"
#include "../GUI\GUI.h"
#include "../controller.h"
#include "../operations/opAddCircle.h"
#include<Windows.h>
Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = P1;
	radius = P2;
	ShapeID = ID;
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawCircle(Center, radius, ShpGfxInfo);
}
//void Circle::GetRadius() {
//	double Rad;
//	Rad = sqrt(pow((Center.x + radius.x), 2) + pow((Center.y + radius.y), 2));
//	return Rad;
//}
void Circle::Resize(double r) {
	Point npoint1 =Center;
	Point npoint2 = radius;

	double Distance = abs(radius.x - Center.x);
	double x = Distance * r - Distance;
	if (npoint1.x > npoint2.x) {
		npoint2.x -= x;
	}
	else {
		npoint2.x += x ;
	}
	Distance = abs(radius.y - Center.y);
	 x = Distance * r - Distance;

	if (npoint1.y > npoint2.y) {
		npoint2.y -= x ;
	}
	else {
		npoint2.y += x ;
	}
	radius = npoint2;

}
void Circle::Rotate() {
	Point C1 = Center;
	radius.x -= C1.x; radius.y -= C1.y;
	Point temp;
	temp.x = radius.x; temp.y = radius.y;
	radius.x = -temp.y; radius.y = temp.x;

	radius.x += C1.x; radius.y += C1.y;
}
void Circle::Save(ofstream& OutFile , int id) {

	OutFile << "CIRCLE" << " " << ShapeID<< " " << Center.x << " " << Center.y << " " << radius.x << " " << radius.y << " ";

	OutFile << shape::getdrawclr().getucred() << " ";
	OutFile << shape::getdrawclr().getucgreen() << " ";
	OutFile << shape::getdrawclr().getucblue() << " ";
	if (shape::getisfilled() == true) {
		OutFile << shape::getfillclr().getucred() << " ";
		OutFile << shape::getfillclr().getucgreen() << " ";
		OutFile << shape::getfillclr().getucblue() << " ";
	}
	else
	{
		OutFile << "NO_FILL" << " ";
	}
	OutFile << shape::getborderwidth() << " ";
	OutFile << "///" << " ";
}
bool Circle::is_in_fig(int x, int y) {
	double RadiusLength = sqrt(pow((radius.x - Center.x), 2) + pow((radius.y - Center.y), 2));
	double ClickLength = sqrt(pow((x - Center.x), 2) + pow((y - Center.y), 2));
	if (ClickLength <= RadiusLength) {
		
		return true;
	}
	else {
		return false;
	}
	return false;

}
string Circle::printforselection() {
	int RadiusLength = sqrt(pow((radius.x - Center.x), 2) + pow((radius.y - Center.y), 2));
	string msg = "selecteed shape is circle with center coordinates  (" + to_string(Center.x) + ","+ to_string(Center.y) + ")"
		" and radius(" + to_string(radius.x) + ", "+ to_string(radius.y) + ")and raduis Length ("+to_string(RadiusLength)+")";
	return msg;
}

void Circle::scramble() {
	int diffinx = abs((Center.x - radius.x));
	int diffiny = abs((Center.y - radius.y));
	do
	{
		Center.x = (diffinx+(rand() % 1300)) - diffinx;
		Center.y = (diffiny + ((rand()) % 600)) - diffiny;
	} while (Center.x>(1300-diffinx) || Center .y>(550-diffiny) || Center.x < 50 || Center.y <50);
	
	radius.x = Center.x + diffinx;
	radius.x = Center.x + diffinx;
	radius.y = Center.y + diffiny;
}
void Circle::hide(GUI* pUI) {
	
	if (ishiden == true) {
		int diffx = sqrt(((Center.x - radius.x) * (Center.x - radius.x)) + ((Center.y - radius.y) * (Center.y - radius.y)));
		pUI->getwind()->DrawImage("images\\MenuIcons\\Menu_Load.jpg", (Center.x - diffx), (Center.y - diffx), 2 * diffx, 2 * diffx);
		
	}
	
	
}
void Circle::setishidentrue() { ishiden = true; };
void Circle::setishidenfalse() { ishiden = false; };
bool Circle::getishiden() {
	return ishiden;
}
void Circle::setid(int i) {
	ShapeID=i;
};
int Circle::getid() {
	return ShapeID;
}
<<<<<<< Updated upstream
void Circle::ZOOM(double s) {
	int x = 1300 / 2;
	int y = 650 / 2;
	radius.x = (radius.x * s)-(s*x)+x;
	radius.y = (radius.y * s) - (s * y) + y;
	Center.x = (Center.x * s) - (s * x) + x;
	Center.y = (Center.y * s) - (s * y) + y;
=======
shape* Circle::copy() {
	// Create a new Circle object with the same properties as "this" object
	Circle* newCircle = new Circle(Center, radius, ShpGfxInfo);
	return newCircle;
>>>>>>> Stashed changes
}