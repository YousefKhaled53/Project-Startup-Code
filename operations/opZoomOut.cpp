#include "opZoomOut.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"
opZoomOut::opZoomOut(controller* pCont) :operation(pCont)
{}
opZoomOut::~opZoomOut()
{}
void opZoomOut::Execute() {
	pControl->GetUI()->ZOOM(.5);
}