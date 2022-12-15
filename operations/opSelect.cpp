#include "opSelect.h"
#include "..\shapes\Rect.h"
#include "..\shapes\line.h"
#include "..\shapes\square.h"
#include "..\shapes\Oval.h"
#include "..\shapes\IrrPolygon.h"
#include "..\shapes\Circle.h"
#include "..\shapes\RegPolygon.h"
#include "..\shapes\triangle.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"

opSelect::opSelect(controller* pCont) :operation(pCont)
{}
opSelect::~opSelect()
{}

//Execute the operation
void opSelect::Execute()
{
	Point P1;
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Click At The Figure You want to select");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);
	shape* sel = pGraph->Getshape(P1.x, P1.y);
	if (sel) {
		if (pGraph->GetSelected()) {
			sel->SetSelected(true);
			pGraph->GetSelected()->SetSelected(false);
			pGraph->SetSelected(sel);
		}
		else {
			sel->SetSelected(true);
			pGraph->SetSelected(sel);
		}
	}


}
