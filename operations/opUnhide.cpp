#include "opUnhide.h"
#include"../controller.h"
opUnhide::opUnhide(controller* pCont) :operation(pCont) {};
void opUnhide::Execute() {
	Point P1;
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("click on the shape you want to unhide");
	pUI->GetPointClicked(P1.x, P1.y);
	pControl->getGraph()->Unhide(&P1);

	pControl->UpdateInterface();

}