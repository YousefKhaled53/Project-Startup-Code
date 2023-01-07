#include "opmultidelete.h"
#include"controller.h"
#include<windows.h>  
opmultidelete::opmultidelete(controller* pCont) : operation(pCont) {};
void opmultidelete::Execute() {
	
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("write number of shapes to be deleted ");
	int n =stoi( pUI->GetSrting());
	pUI->PrintMessage("now click on the shapes ");
	int* arrx = new int [n];
	int* arry= new int[n];
	
	for (int i = 0; i < n; i++) {
		pUI->GetPointClicked(arrx[i],arry[i]);
	}
	pControl->getGraph()->multiselect(arrx,arry,n);
	pControl->UpdateInterface();
	pUI->PrintMessage("the selcted shapes are highlighted ");
	Sleep(3000);
	pControl->getGraph()->multidelete();
	pUI->PrintMessage("shapes deleted succefully ");
	pControl->getGraph()->clearmultiselectedvector();
}