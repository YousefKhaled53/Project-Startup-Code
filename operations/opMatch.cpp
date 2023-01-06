#include "opMatch.h"
opMatch::opMatch(controller* pcont) :operation(pcont) {}
opMatch :: ~opMatch() {}
void opMatch::Execute() {
	Point P1;
	Point P2;
	GUI* pUI = pControl->GetUI();
	pControl->getGraph()->Match(pUI);

}