#include "opdublicate.h"
opdublicate::opdublicate(controller* pCont) :operation(pCont) {};
void opdublicate::Execute() {
	GUI* pUI = pControl->GetUI();
	pControl->getGraph()->dublicate();
	
}
