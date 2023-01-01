#include "opCopy.h"
#include"../Shapes/Graph.h"
#include"../controller.h"
#include"../operations/operation.h"
#include "../Shapes/Shape.h"


opCopy::opCopy(controller* pCont) : operation(pCont) {}

void opCopy::Execute()
{
    Point P1;
    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();
    pUI->PrintMessage("Please select a shape to copy");
    pUI->GetPointClicked(P1.x, P1.y);
    shape* sel = pGr->Getshape(P1.x, P1.y);
    shape*
    shapeIndex = pGr->GetSelected();
    pGr->Addshape(shapeIndex);
    pUI->PrintMessage("Shape copied successfully");
    
}
