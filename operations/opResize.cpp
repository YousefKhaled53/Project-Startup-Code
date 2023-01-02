#include "../operations/opResize.h"

opResize::opResize(controller* pcont) :operation(pcont) {}
opResize :: ~opResize(){}
void opResize::Execute() {
	ratio = 2;
	GUI* pUI = pControl->GetUI(); // getting a pointer from gui so that i can call print message and call selectshape
	Graph* pGr = pControl->getGraph(); // getting a pointer of grapg so that i can call delete shape and getshape (but what does getshape do ??)
	pGr->Resize(pGr->GetSelected(), ratio); // is done after making select function 
	pUI->PrintMessage("change size");

}
