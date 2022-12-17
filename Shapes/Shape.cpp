#include "shape.h"
int shape::ID = 0;
shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
	ID = ID + 1;
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
void shape::bordercolor(color Bclr)
{
	ShpGfxInfo.DrawClr = Bclr;
	ShpGfxInfo.isSelected = false;
}
void shape::changeborderwidth(int bw){
	ShpGfxInfo.BorderWdth = bw;
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
void shape::setisfilled() {
	ShpGfxInfo.isFilled=true;
}
int shape::getid() {
	return ID;
}
void shape::setid(int i) {
	ID = i;
}
bool shape::InDrawArea(Point P) {
	return (P.x >= 0 && P.x <= 1300 && P.y >= 50 && P.y <= 550);
}

