#include"opborderwidth.h"
#include "../controller.h"
#include"../GUI/GUI.h"
#include"../Shapes/Graph.h"
opborderwidth::opborderwidth(controller* pCont) : operation(pCont) {}
void opborderwidth::Execute() {
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("write the width you need");
	int pw;
	pw = stoi(pUI->GetSrting());
	pGr->borderwidth(pGr->GetSelected(), pw);

}