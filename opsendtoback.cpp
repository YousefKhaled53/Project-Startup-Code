#include "opsendtoback.h"
#include"controller.h"
opsendtoback::opsendtoback(controller* pCont) :operation(pCont) {}
void opsendtoback::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pControl->getGraph()->sendtoback(pGr->GetSelected());
	pControl->UpdateInterface();

}