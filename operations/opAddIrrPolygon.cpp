#include "opAddIrrPolygon.h"
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

	pUI->PrintMessage("New irregular Polygon: Enter number of vertices");
	string x = pUI->GetSrting();
	Point* array = new Point[stoi(x)];
	string msg = "Your vertices are (" + x + " )";
	msg += " ... Click on your vertices";
	pUI->PrintMessage(msg);
	for (int i = 0; i < stoi(x); i++) {
		pUI->PrintMessage(" Enter vertix");
		while (true) {
			
			pUI->GetPointClicked(array[i].x, array[i].y);
			if (!IrrPolygon::InDrawArea(array[i]))
				pUI->PrintMessage(" Vertix is out of the drawing area, click again");
			else
				break;

		}


		pUI->ClearStatusBar();
	}
	//Preapre all Irregular Polygon parameters
	GfxInfo IrrPolygonGfxInfo;

	//get drawing, filling colors and pen width from the interface
	IrrPolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
	IrrPolygonGfxInfo.FillClr = pUI->getCrntFillColor();
	IrrPolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	pUI->PrintMessage("do you want to be filled ?");
	string t = pUI->GetSrting();
	if (t == "yes") {
		IrrPolygonGfxInfo.isFilled = true;
		IrrPolygonGfxInfo.isSelected = false;//default is not filled
	}
	else 
	{
		IrrPolygonGfxInfo.isFilled = false;
		IrrPolygonGfxInfo.isSelected = false;//defualt is not selected

	}

	//Create an Irregular Polygon with the above parameters
	IrrPolygon* I = new IrrPolygon(array, stoi(x), IrrPolygonGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Circle to the list of shapes
	pGr->Addshape(I);



}
