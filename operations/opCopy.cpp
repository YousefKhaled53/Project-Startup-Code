#include "opCopy.h"
#include"../Shapes/Graph.h"
#include"../controller.h"
#include"../operations/operation.h"
#include "../Shapes/Shape.h"


opCopy::opCopy(controller* pCont) : operation(pCont) {}

void opCopy::Execute()
{
    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();
    pUI->PrintMessage("Please select Before copy");
    pGr->copy();
    pUI->PrintMessage("Copied");
    
}
