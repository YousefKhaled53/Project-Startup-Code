#include "shape.h"


int shape::ID = 0;

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
	ID = ID + 1;
	setid(ID);
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}
color shape::getdrawclr() {
	return ShpGfxInfo.DrawClr;
}
color shape::getfillclr() {
	return ShpGfxInfo.FillClr;
}
int shape::getborderwidth() {
	return ShpGfxInfo.BorderWdth;
}
bool shape::getisfilled() {
	return ShpGfxInfo.isFilled;
}
int shape::getid() {
	return ID;
}
void shape::setid(int i) {
	ID = i;
}


