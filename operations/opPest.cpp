#include "opPest.h"
#include"../Shapes/Graph.h"
#include "../controller.h"
#include "../Shapes/Shape.h"  

void opPest::Execute()
{
        GUI* pUI = pControl->GetUI();
        pUI->PrintMessage("Please select a location to paste the shape");
        int x, y;
        pUI->GetPointClicked(x, y);        
        pUI->PrintMessage("Shape pasted successfully");
    }
