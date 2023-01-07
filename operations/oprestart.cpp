#include"oprestart.h"
oprestart::oprestart(controller* pCont) : operation(pCont) {};
oprestart::~oprestart() {};
void oprestart::Execute() {
	GUI* pUI = pControl->GetUI();
	pControl->getGraph()->filloriginalfromtemporary();
	pControl->getGraph()->resetscore();
	pControl->getGraph()->dublicate();
	pControl->getGraph()->hide(pUI);
	pControl->getGraph()->scramble();
	pControl->UpdateInterface();
	while (pControl->getGraph()->getshapeslist() == true) {

		Point P1;
		pUI->PrintMessage("the game has started and your score is : " + to_string(pControl->getGraph()->getscore()));

		pUI->GetPointClicked(P1.x, P1.y);
		if (pUI->isinttoolbar(&P1) == true) {
			pControl->getGraph()->Unhide(&P1);
			pControl->getGraph()->Match(pUI);
			pUI->CreatePlayToolBar();
			pUI->CreateStatusBar();

			pControl->UpdateInterface();
		}
		else
		{
			break;
			pUI->PrintMessage("the play is stopped now click on the needed operation ");
			pControl->GetUseroperation();
		}
	}
	pUI->PrintMessage("congratulations you finished with score " + to_string(pControl->getGraph()->getscore()));
}