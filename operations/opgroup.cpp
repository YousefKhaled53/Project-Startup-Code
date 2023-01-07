#include "opgroup.h"
#include"../controller.h"
#include<windows.h>  
opgroup::opgroup (controller* pCont) : operation(pCont) {};
void opgroup::Execute() {

	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("write number of shapes to be grouped ");
	int n = stoi(pUI->GetSrting());
	pUI->PrintMessage("now click on the shapes ");
	int* arrx = new int[n];
	int* arry = new int[n];

	for (int i = 0; i < n; i++) {
		pUI->GetPointClicked(arrx[i], arry[i]);
	}
	pControl->getGraph()->multiselectforgrouping(arrx, arry, n);
	pControl->UpdateInterface();
	pUI->PrintMessage("the selcted shapes are highlighted and grouped ");
	Sleep(3000);
	pControl->getGraph()->makeallunselected();
	pControl->UpdateInterface();
	pControl->getGraph()->addtoagroup(n);
	//pControl->getGraph()->clearmultiselectedvector();
}