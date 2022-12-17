#include "opAddline.h"
#include "../shapes/line.h"

#include "../controller.h"

#include "../GUI\GUI.h"

opAddline::opAddline(controller* pCont) :operation(pCont)
{}
opAddline::~opAddline()
{}

//Execute the operation
void opAddline::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Line: Click at first corner");

	while (true) {
		pUI->GetPointClicked(P1.x, P1.y);
		if (!line::InDrawArea(P1))
			pUI->PrintMessage(" Corner is out of the drawing area, click again");
		else
			break;

	}


	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);


	while (true) {
		pUI->GetPointClicked(P2.x, P2.y);
		if (!line::InDrawArea(P2))
			pUI->PrintMessage(" Corner is out of the drawing area, click again");
		else
			break;

	}
	pUI->ClearStatusBar();

	//Preapre all line parameters
	GfxInfo lineGfxInfo;

	//get drawing, filling colors and pen width from the interface
	lineGfxInfo.DrawClr = pUI->getCrntDrawColor();
	lineGfxInfo.FillClr = pUI->getCrntFillColor();
	lineGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	lineGfxInfo.isFilled = false;	//default is not filled
	lineGfxInfo.isSelected = false;	//defualt is not selected


	//Create a line with the above parameters
	line* L = new line(P1, P2, lineGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the line to the list of shapes
	pGr->Addshape(L);

}
