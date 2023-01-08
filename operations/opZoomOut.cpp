#include "opZoomOut.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"
opZoomOut::opZoomOut(controller* pCont) :operation(pCont)
{}
opZoomOut::~opZoomOut()
{}
void opZoomOut::Execute() {
	GUI* pUI = pControl->GetUI();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Zoom out is working now");
	pControl->GetUI()->ZOOM(.5);
}