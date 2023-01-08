#include"opundo.h"
opundo::opundo(controller* pCont) :operation(pCont) {}
opundo::~opundo() {};
void opundo::Execute() {
	GUI* pUI = pControl->GetUI();
	pControl->getGraph()->undo();
}

