#include "opStickImage.h"
#include"../controller.h"
#include "../operations/operation.h"
#include "../GUI/\GUI.h"

opStickImage::opStickImage(controller* pCont):operation(pCont){}
opStickImage::~opStickImage(){}
void opStickImage::Execute()
{
	GUI* pUI = pControl->GetUI();
	pControl->getGraph()->stickimage(pUI);
}