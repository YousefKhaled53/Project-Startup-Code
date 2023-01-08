#include"opredo.h"
opredo::opredo(controller* pCont) :operation(pCont) {}
opredo::~opredo() {};
void opredo::Execute() {
	GUI* pUI = pControl->GetUI();
	pControl->getGraph()->redo();
}

