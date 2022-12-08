#include "opdeleteshape.h"
#include "opdeleteshape.h"
#include "controller.h"
#include"GUI/GUI.h"
#include"Shapes/Graph.h"
opdeleteshape::opdeleteshape(controller* pcont) :operation(pcont) {};
void opdeleteshape::Execute() {
	GUI* pUI = pControl->GetUI(); // getting a pointer from gui so that i can call print message and call selectshape
	pUI->PrintMessage("choose the shape ");
	Graph* pGr = pControl->getGraph(); // getting a pointer of grapg so that i can call delete shape and getshape (but what does getshape do ??)
	pGr->deleteshape(pGr->Getshape(/*pUi.selectshape*/)); // is done after making select function 
}