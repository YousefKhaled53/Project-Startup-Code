#include "opZoomIn.h"
#include "..\controller.h"
#include "operation.h"
#include "..\GUI\GUI.h"
#include "..\shapes\Rect.h"
#include "..\shapes\line.h"
#include "..\shapes\square.h"
#include "..\shapes\Oval.h"
#include "..\shapes\IrrPolygon.h"
#include "..\shapes\Circle.h"
#include "..\shapes\RegPolygon.h"
#include "..\shapes\triangle.h"
#include "..\controller.h"
#include"../Shapes/Graph.h"
opZoomIn::opZoomIn(controller* pCont) :operation(pCont)
{}
opZoomIn::~opZoomIn()
{}
void opZoomIn::Execute() {
	GUI* pUI = pControl->GetUI();    
	Graph* pGr = pControl->getGraph();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Zoom in is working now");
	pGr->ZOOMING(2);
}