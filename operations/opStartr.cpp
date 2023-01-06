#include"opStartr.h"
opStartr::opStartr(controller* pCont) : operation(pCont) {};
opStartr::~opStartr() {};
void opStartr::Execute() {
	operation* pOp = nullptr;
	GUI* pUI = pControl->GetUI();
	pControl->getGraph()->dublicate();
	pControl->getGraph()->hide(pUI);
	pControl->getGraph()->scramble();
	pControl->UpdateInterface();
	while (pControl->getGraph()->getshapeslist()==true) {
		Point P1;
		pUI->PrintMessage("click on the shape you want to unhide");
		pUI->GetPointClicked(P1.x, P1.y);
		pControl->getGraph()->Unhide(&P1);
		pControl->getGraph()->Match(pUI);
		pControl->UpdateInterface();
	} 
	

}