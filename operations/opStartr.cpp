#include"opStartr.h"
opStartr::opStartr(controller* pCont) : operation(pCont) {};
opStartr::~opStartr() {};
void opStartr::Execute() {
	GUI* pUI = pControl->GetUI();
	pControl->getGraph()->filltemporary();
	pControl->getGraph()->resetscore();
	pControl->getGraph()->dublicate();
	pControl->getGraph()->hide(pUI);
	pControl->getGraph()->scramble();
	pControl->UpdateInterface();
	while (pControl->getGraph()->getshapeslist()==true) {
		
		Point P1;
		pUI->PrintMessage("the game has started and your score is : "+ to_string(pControl->getGraph()->getscore()));
		
		pUI->GetPointClicked(P1.x, P1.y);
		if (pUI->isinttoolbar(&P1) == true) {
			pControl->getGraph()->Unhide(&P1);
			pControl->getGraph()->Match(pUI);
			pControl->UpdateInterface();
		}
		else
		{
			
			pUI->PrintMessage("game is stopped, you can now choose an operation ");
			Sleep(2000);
			break;
		
		}
		pUI->CreatePlayToolBar();
		pUI->CreateStatusBar();
		
	} 
	pUI->PrintMessage("congratulations you finished with score " + to_string(pControl->getGraph()->getscore()));
}
