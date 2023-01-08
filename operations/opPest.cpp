#include "opPest.h"
#include"../Shapes/Graph.h"
#include "../controller.h"
#include"../Shapes/Rect.h"
#include"../Shapes/Circle.h"
#include "../Shapes/line.h"
#include"../Shapes/triangle.h"
#include"../Shapes/Oval.h"
#include"../Shapes/RegPolygon.h"
#include"../Shapes/square.h"
#include "../Shapes/Shape.h"  
opPest::opPest(controller* pCont) : operation(pCont) {}

void opPest::Execute()
{
	Point P;
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("Click On The Screen At A Point To Paste ");
	pUI->GetPointClicked(P.x, P.y);
	
	Graph* pGraph = pControl->getGraph();
	
	pUI->ClearStatusBar();
	vector<shape*> shapes = pGraph->getcopy();
	for (auto shapeToPaste : shapes)
	{
		Rect* Rectan = dynamic_cast<Rect*>(shapeToPaste);
		triangle* Tri = dynamic_cast<triangle*>(shapeToPaste);
		Circle* cir = dynamic_cast<Circle*>(shapeToPaste);
		line* Line = dynamic_cast<line*>(shapeToPaste);
		Oval* oval = dynamic_cast<Oval*>(shapeToPaste);
		square* Squ = dynamic_cast<square*>(shapeToPaste);
		RegPolygon* Regular = dynamic_cast<RegPolygon*>(shapeToPaste);
		//IrRegularPolygon* IrRegular = dynamic_cast<IrRegularPolygon*>(shapeToPaste);
		Point Po1, Po2, RefP,Po3;
		if (Rectan != NULL)
		{
			Po1 = Rectan->getP1();
			Po2 = Rectan->getP2();
			RefP.x = (Po1.x + Po2.x) / 2;
			RefP.y = (Po1.y + Po2.y) / 2;
			Point diff = { RefP.x - Po2.x,RefP.y - Po2.y };
			Point NewP2 = { P.x - diff.x,P.y - diff.y };
			Point Diff2 = { P.x - Po2.x, P.y - Po2.y };
			Point NewP1 = { Po1.x + Diff2.x - diff.x,Po1.y + Diff2.y - diff.y };
			GfxInfo PastingShapeInfo = Rectan->GetGfxInfo();
			Rect* R = new Rect(NewP2, NewP1, PastingShapeInfo);
			R->SetSelected(false);
			pGraph->Addshape(R);
			
			
		}
		if (Tri != NULL)
		{
			Po1 = Tri->getP1();
			Po2 = Tri->getP2();
			Po3 = Tri->getP3();
			RefP.x = (Po1.x + Po2.x + Po3.x) / 3;
			RefP.y = (Po1.y + Po2.y + Po3.y) / 3;
			Point diff = { RefP.x - Po2.x,RefP.y - Po2.y };
			Point NewP2 = { P.x - diff.x,P.y - diff.y };
			Point Diff2 = { P.x - Po2.x, P.y - Po2.y };
			Point NewP1 = { Po1.x + Diff2.x - diff.x,Po1.y + Diff2.y - diff.y };
			Point NewP3 = { Po3.x + Diff2.x - diff.x,Po3.y + Diff2.y - diff.y };
			GfxInfo PastingShapeInfo = Tri->GetGfxInfo();
			triangle* T = new triangle(NewP2, NewP1, NewP3, PastingShapeInfo);
			T->SetSelected(false);
			pGraph->Addshape(T);
		
			
		}
		else if (oval != NULL)
		{
			// Calculate new position for Oval shape
			Point P1 = oval->getPoint1();
			Point P2 = oval->getPoint2();
			RefP.x = (P1.x + P2.x) / 2;  // calculate reference point of Oval
			RefP.y = (P1.y + P2.y) / 2;
			Point diff = { RefP.x - P2.x, RefP.y - P2.y };
			Point NewP2 = { P.x - diff.x, P.y - diff.y };
			Point Diff2 = { P.x - P2.x, P.y - P2.y };
			Point NewP1 = { P1.x + Diff2.x - diff.x, P1.y + Diff2.y - diff.y };
			GfxInfo PastingShapeInfo = oval->GetGfxInfo();
			Oval* O = new Oval(NewP2, NewP1, PastingShapeInfo);
			O->SetSelected(false);
			pGraph->Addshape(O);
		}
		else if (Squ != NULL)
		{
			// Calculate new position for Square shape
			Point P1 = Squ->getP1();
			Point P2 = Squ->getP2();
			RefP.x = (P1.x + P2.x) / 2;  // calculate reference point of Square
			RefP.y = (P1.y + P2.y) / 2;
			Point diff = { RefP.x - P2.x, RefP.y - P2.y };
			Point NewP2 = { P.x - diff.x, P.y - diff.y };
			Point Diff2 = { P.x - P2.x, P.y - P2.y };
			Point NewP1 = { P1.x + Diff2.x - diff.x, P1.y + Diff2.y - diff.y };
			GfxInfo PastingShapeInfo = Squ->GetGfxInfo();
			square* S = new square(NewP2, NewP1, PastingShapeInfo);  // Create new Square object
			S->SetSelected(false);
			pGraph->Addshape(S);  // Add new Square to graph
		}
		else if (Line != NULL)
		{
			// Calculate new position for Line shape
			Point Start = Line->getP1();
			Point End = Line->getP2();
			RefP.x = (Start.x + End.x) / 2;  // calculate reference point of Line
			RefP.y = (Start.y + End.y) / 2;
			Point diff = { RefP.x - End.x, RefP.y - End.y };
			Point NewEnd = { P.x - diff.x, P.y - diff.y };
			Point Diff2 = { P.x - End.x, P.y - End.y };
			Point NewStart = { Start.x + Diff2.x - diff.x, Start.y + Diff2.y - diff.y };
			GfxInfo PastingShapeInfo = Line->GetGfxInfo();
			line* L = new line(NewStart, NewEnd, PastingShapeInfo);
			L->SetSelected(false);
			pGraph->Addshape(L);
		}
		
		if (cir != NULL) {

			RefP = cir->getCenter();
			Point center = cir->getReduis();
			int distance = cir->getdis();
			GfxInfo inf = cir->GetGfxInfo();
			Point diff = { RefP.x - center.x,RefP.y - center.y };
			Point Ncenter = { (P.x - diff.x), (P.y - diff.y) };
			Point Nradius = { Ncenter.x + distance,Ncenter.y };
			Circle* C = new Circle(Ncenter, Nradius, inf);
			C->SetSelected(false);
			pGraph->Addshape(C);
		}
	




		


	}
}