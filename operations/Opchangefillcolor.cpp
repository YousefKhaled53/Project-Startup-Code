#include "Opchangefillcolor.h"

#include "../controller.h"
#include"../GUI/GUI.h"
#include"../Shapes/Graph.h"
Opchangefillcolor::Opchangefillcolor(controller* pCont) : operation(pCont) {}
void Opchangefillcolor::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	color c(255,255,0); 
	pGr->changefillcolor(pGr->GetSelected(),c);
}