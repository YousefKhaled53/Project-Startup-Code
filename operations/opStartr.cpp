#include"opStartr.h"
opStartr::opStartr(controller* pCont) : operation(pCont) {};
opStartr::~opStartr() {};
void opStartr::Execute() {
	GUI* pUI = pControl->GetUI();

	pControl->getGraph()->dublicate();
	pControl->getGraph()->hide(pUI);
	pControl->getGraph()->scramble();


}