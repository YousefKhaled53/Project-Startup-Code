#include "opAddRect.h"
#include "..\shapes\Rect.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddRect::opAddRect(controller * pCont):operation(pCont)
{}
opAddRect::~opAddRect()
{

} 

//Execute the operation
void opAddRect::Execute() 
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();


	pUI->PrintMessage("New rectangle: Click at first corner");

	while (true) {
		pUI->GetPointClicked(P1.x, P1.y);
		if (!Rect::InDrawArea(P1))
			pUI->PrintMessage(" Corner is out of the drawing area, click again");
		else
			break;

	}


	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);


	while (true) {
		pUI->GetPointClicked(P2.x, P2.y);
		if (!Rect::InDrawArea(P2))
			pUI->PrintMessage(" Corner is out of the drawing area, click again");
		else
			break;

	}
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo RectGfxInfo;
	
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RectGfxInfo.FillClr = pUI->getCrntFillColor();
	RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	pUI->PrintMessage("do you want to be filled ?");
	string t = pUI->GetSrting();
	if (t == "yes") {
		RectGfxInfo.isFilled = true;
		RectGfxInfo.isSelected = false;//default is not filled
	}
	else 
	{

		RectGfxInfo.isFilled = false;
		RectGfxInfo.isSelected = false;//defualt is not selected

	}

	//Create a rectangle with the above parameters
	Rect *R=new Rect(P1, P2, RectGfxInfo);
	

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}

