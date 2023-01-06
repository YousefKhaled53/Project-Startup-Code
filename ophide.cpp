#include "ophide.h"
#include"controller.h"
ophide::ophide(controller* pCont) :operation(pCont) {};
void ophide::Execute() {

	GUI* pUI = pControl->GetUI();

	pControl->getGraph()->hide(pUI);
	

}