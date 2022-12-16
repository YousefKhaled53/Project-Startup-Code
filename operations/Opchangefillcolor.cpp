#include "Opchangefillcolor.h"
#include"../CMUgraphicsLib/CMUgraphics.h"
#include "../controller.h"
#include"../GUI/GUI.h"
#include"../Shapes/Graph.h"
Opchangefillcolor::Opchangefillcolor(controller* pCont) : operation(pCont) {}
void Opchangefillcolor::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	Point p1;
	pUI->getwind()->SetPen(BLACK );
	pUI->getwind()->DrawString(300,60,"the pallete ");
	pUI->getwind()->DrawImage("images\\MenuIcons\\p.jpg",300,100);
	pUI->PrintMessage("click on the needed color ");
	pUI->GetPointClicked(p1.x, p1.y);
	color c2=pUI->getwind()->GetColor(p1.x, p1.y);
	pGr->changefillcolor(pGr->GetSelected(),c2);
}