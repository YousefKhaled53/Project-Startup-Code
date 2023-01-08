#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"


//Base class for all shapes
class shape
{
protected:
	static int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	
	/// Add more parameters if needed.

public:
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(GUI* pUI) const  =0  ;		//Draw the shape
	
	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color
	color getdrawclr();
	color getfillclr();
	void bordercolor(color Bclr);
	void changeborderwidth(int bw);
	int getborderwidth();
	bool getisfilled();
	void setisfilled();
	virtual void setid(int i)=0;
	virtual int getid() = 0;
	virtual void Resize(double ratio) = 0;
	virtual void Rotate() = 0;
	virtual void Move(Point P1, Point P2) = 0;
	virtual bool is_in_fig(int x, int y) = 0;
	virtual string printforselection()=0;
	static bool InDrawArea(Point P);
	virtual void hide(GUI* pUI)=0;
	virtual void setishidentrue()=0;
	virtual void setishidenfalse()=0;
	virtual bool getishiden() = 0;
	virtual void setisingroup(bool b)=0;
	virtual bool getisingroup() = 0;

	///The following functions should be supported by the shape class	
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the shape
	//virtual void Resize() = 0;	//Resize the shape
	//virtual void Move() = 0;		//Move the shape
	virtual void scramble() =0 ;
	virtual void Save(ofstream &OutFile , int id) = 0;	//Save the shape parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the shape parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all shape info on the status bar
};

