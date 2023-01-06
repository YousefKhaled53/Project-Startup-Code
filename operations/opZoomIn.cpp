#include "opZoomIn.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"
opZoomIn::opZoomIn(controller* pCont) :operation(pCont)
{}
opZoomIn::~opZoomIn()
{}
void opZoomIn::Execute() {
	pControl->GetUI()->ZOOM(10);
}