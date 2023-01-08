#include "opungroup.h"
#include"../controller.h"
#include<windows.h>  
opungroup::opungroup(controller* pCont) : operation(pCont) {};
void opungroup::Execute() {

	GUI* pUI = pControl->GetUI();
	
	pControl->getGraph()->ungroup();
	pUI->PrintMessage("the shape group is cleared ");
}