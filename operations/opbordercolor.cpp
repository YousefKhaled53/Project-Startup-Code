#include "opbordercolor.h"
#include "../controller.h"
#include"../GUI/GUI.h"
#include"../Shapes/Graph.h"
opbordercolor::opbordercolor(controller* pCont) : operation(pCont) {}
void opbordercolor::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("write red intensity ");
	int r = stoi(pUI->GetSrting());
	pUI->PrintMessage("write green intensity ");
	int g = stoi(pUI->GetSrting());
	pUI->PrintMessage("write blue intensity ");
	int b = stoi(pUI->GetSrting());
	color c(r, b, g);
	pGr->bordercolor(pGr->GetSelected(), c);
}