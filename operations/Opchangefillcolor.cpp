#include "Opchangefillcolor.h"
#include"../CMUgraphicsLib/CMUgraphics.h"
#include "../controller.h"
#include"../GUI/GUI.h"
#include"../Shapes/Graph.h"
Opchangefillcolor::Opchangefillcolor(controller* pCont) : operation(pCont) {}
void Opchangefillcolor::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	color c(255,255,0); 
	//window* pwind = pControl->getwind();
	//const int x = 111;
	//const int y = 111;
	//color c2 =pwind->GetColor(x,y);
	pGr->changefillcolor(pGr->GetSelected(),c );
}