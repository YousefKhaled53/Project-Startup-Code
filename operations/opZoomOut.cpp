#include "opZoomOut.h"
#include "..\controller.h"

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
opZoomOut::opZoomOut(controller* pCont) :operation(pCont)
{}
opZoomOut::~opZoomOut()
{}
void opZoomOut::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Zoom out is working now");
	pGr->ZOOMING(0.5);
}