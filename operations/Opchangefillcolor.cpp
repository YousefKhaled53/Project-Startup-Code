#include "Opchangefillcolor.h"
#include"../CMUgraphicsLib/CMUgraphics.h"
#include "../controller.h"
#include"../GUI/GUI.h"
#include"../Shapes/Graph.h"
Opchangefillcolor::Opchangefillcolor(controller* pCont) : operation(pCont) {}
void Opchangefillcolor::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	
	//const int x = 111;
	//const int y = 111;
	//double r, g, b;
	pUI->PrintMessage("write red intensity ");
	int r = stoi(pUI->GetSrting());
	pUI->PrintMessage("write green intensity ");
	int g = stoi(pUI->GetSrting());
	pUI->PrintMessage("write blue intensity ");
	int b = stoi(pUI->GetSrting());
	pUI->PrintMessage("done");
	color c(r,g,b);
	pGr->changefillcolor(pGr->GetSelected(),c );
}