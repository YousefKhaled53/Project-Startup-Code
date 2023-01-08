#include "opZoomIn.h"
#include "..\controller.h"
#include "operation.h"
#include "..\GUI\GUI.h"
opZoomIn::opZoomIn(controller* pCont) :operation(pCont)
{}
opZoomIn::~opZoomIn()
{}
void opZoomIn::Execute() {
	GUI* pUI = pControl->GetUI();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Zoom in is working now");
	pControl->GetUI()->ZOOM(10);
}