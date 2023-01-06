#include "opscramble.h"
opscramble::opscramble(controller* pCont) : operation(pCont) {};
void opscramble::Execute() {
	GUI* pUI = pControl->GetUI();
	pControl->getGraph()->scramble();
	pUI->CreatePlayToolBar();
	pUI->CreateStatusBar();
}