#include "opstart.h"
opstart::opstart(controller* pCont) : operation(pCont) {};
opstart::~opstart() {};
void opstart::Execute() {
	GUI* pUI = pControl->GetUI();

	pControl->getGraph()->dublicate();
	pControl->getGraph()->hide(pUI);
	pControl->getGraph()->scramble();


}