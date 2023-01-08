#include "opStickImage.h"
#include"../controller.h"
opStickImage::opStickImage(controller* pCont) :operation(pCont) {};
void opStickImage::Execute() {

	GUI* pUI = pControl->GetUI();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Choose shape to stick image");
	shape* sh = pControl->getGraph()->GetSelected();
	pControl->getGraph()->StickImage(sh);

}