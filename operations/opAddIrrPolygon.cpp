/*#include "opAddIrrPolygon.h"
#include "../shapes/IrrPolygon.h"
#include "../controller.h"
#include "../GUI/GUI.h"

opAddIrrPolygon::opAddIrrPolygon(controller* pCont) :operation(pCont)
{}
opAddIrrPolygon::~opAddIrrPolygon()
{}

//Execute the operation
void opAddIrrPolygon::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Irregular Polygon: Enter number of vertices");
	//Read number of vertices
	string x = pUI->GetSrting();
	Point *array = new Point[stoi(x)];
	string msg = "Your vertices are (" + x + " )";
	msg += " ... Click on your vertices";
	pUI->PrintMessage(msg);
	//Read Points
	for (int i = 0; i < stoi(x); i++) {
		pUI->GetPointClicked(array[i].x,array[i].y);
	}
	pUI->ClearStatusBar();

	//Preapre all Irregular Polygon parameters
	GfxInfo IrrPolygonGfxInfo;

	//get drawing, filling colors and pen width from the interface
	IrrPolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
	IrrPolygonGfxInfo.FillClr = pUI->getCrntFillColor();
	IrrPolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	IrrPolygonGfxInfo.isFilled = false;	//default is not filled
	IrrPolygonGfxInfo.isSelected = false;	//defualt is not selected


	//Create an Irregular Polygon with the above parameters
	IrrPolygon* I = new IrrPolygon(array, stoi(x), IrrPolygonGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Circle to the list of shapes
	pGr->Addshape(I);



}
*/