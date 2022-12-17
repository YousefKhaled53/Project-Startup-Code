#include "opAddRegPolygon.h"
#include "../shapes/RegPolygon.h"
#include "../controller.h"
#include "../GUI/GUI.h"

opAddRegPolygon::opAddRegPolygon(controller* pCont) :operation(pCont)
{}
opAddRegPolygon::~opAddRegPolygon()
{}

//Execute the operation
void opAddRegPolygon::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New regular Polygon: Enter number of vertices");
	//Read number of vertices
	Point Center;
	string x = pUI->GetSrting();
	Point* array = new Point[stoi(x)];
	string msg = "Your vertices are (" + x + " )";
	msg += " ... Click on your Centerx";
	pUI->PrintMessage(msg);
	pUI->GetPointClicked(Center.x, Center.y);

	msg += " ... Click on your First Vertex";
	pUI->PrintMessage(msg);
	//Read Points
	pUI->GetPointClicked(array[0].x, array[0].y);

	pUI->ClearStatusBar();

	//Preapre all Irregular Polygon parameters
	GfxInfo RegPolygonGfxInfo;

	//get drawing, filling colors and pen width from the interface
	RegPolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RegPolygonGfxInfo.FillClr = pUI->getCrntFillColor();
	RegPolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	pUI->PrintMessage("do you want to be filled ?");
	string t = pUI->GetSrting();
	if (t == "yes") {
		RegPolygonGfxInfo.isFilled = true;
		RegPolygonGfxInfo.isSelected = false;//default is not filled
	}
	else
	{

		RegPolygonGfxInfo.isFilled = false;
		RegPolygonGfxInfo.isSelected = false;//defualt is not selected

	}

	//Create an Irregular Polygon with the above parameters
	RegPolygon* I = new RegPolygon(Center ,array, stoi(x), RegPolygonGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Circle to the list of shapes
	pGr->Addshape(I);



}
