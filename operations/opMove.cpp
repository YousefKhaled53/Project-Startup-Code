#include "opMove.h"
opMove::opMove(controller* pcont) :operation(pcont) {}
opMove :: ~opMove() {}
void opMove::Execute() {
	Point P1;
	Point P2;
	GUI* pUI = pControl->GetUI(); // getting a pointer from gui so that i can call print message and call selectshape
	Graph* pGr = pControl->getGraph(); // getting a pointer of grapg so that i can call delete shape and getshape (but what does getshape do ??)
	pUI->PrintMessage("click and start dragging");
	pUI->GetPointClicked(P1.x, P1.y);
	pUI->GetPointClicked(P2.x, P2.y);
//	pWind->WaitMouseClick(P2.x, P2.y);
	while (pUI->Drag(P2)) {
		if (pGr->GetSelected()) {
			pGr->GetSelected()->Move(P1, P2); // is done after making select function 
			
		}
	Sleep(16);
	}

}
