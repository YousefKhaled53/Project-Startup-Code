#include "opMultiSelect.h"
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

opMultiSelect::opMultiSelect(controller* pCont) :operation(pCont)
{}
opMultiSelect::~opMultiSelect()
{}

//Execute the operation
void opMultiSelect::Execute()
{
	Point P1;
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Welcome to Multi_Select, Click At The Figures You want to select/unselect");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);
	shape* msel = pGraph->Getshape(P1.x, P1.y);

	if (msel) {

		if (pGraph->GetSelected()) {
			msel->SetSelected(true);
			pUI->ClearStatusBar();
			pUI->PrintMessage(msel->printforselection());
			//pGraph->GetSelected()->SetSelected(false);
			pGraph->SetSelected(msel);

		}
		else {
			msel->SetSelected(true);
			pUI->ClearStatusBar(); //tring msg = "selecteed shape with width (" + to_string(sel->getborderwidth()) + ")";
//			pUI->PrintMessage(msel->printforselection());
			pGraph->SetSelected(msel);
		}
	}


}
