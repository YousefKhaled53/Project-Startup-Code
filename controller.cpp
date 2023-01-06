#include "controller.h"
#include "operations/opAddRect.h"
#include "operations/opAddline.h"
#include "operations/opAddtriangle.h"
#include "operations/opAddsquare.h"
#include "operations/opAddCircle.h"
#include "operations/opAddOval.h"
#include "operations/opdeleteshape.h"
#include "operations/opswitchplaymode.h"
#include "operations/opsave.h"
#include "operations/opsave.h"
#include "operations/opload.h"
#include "operations/opAddIrrPolygon.h"
#include"operations/opAddRegPolygon.h"
#include "operations/opSelect.h"
#include"opchangepenwidth.h"
#include"operations/opbordercolor.h"
#include"Opexit.h"
#include"operations/opborderwidth.h"
#include"operations/Opchangefillcolor.h"
#include"opCHangeGeneralDrawcolor.h"
#include"opchangepenwidth.h"
#include"opChangeGeneralFillColor.h"
#include"opCHangeGeneralDrawcolor.h"
#include"opCancelFillingGeneral.h"
#include"operations/Opchangefillcolor.h"
#include"./opchangepenwidth.h"
#include"./operations/opCopy.h"
#include"Opexit.h"
#include "opCancelFillingGeneral.h"
#include"operations/opdeleteshape.h"
#include"opscramble.h"
#include"opdublicate.h"
#include"opsendtoback.h"
#include "opmultidelete.h"
#include "operations/opMultiSelect.h"
#include "operations/opZoomIn.h"
#include "operations/opZoomOut.h"
#include "operations/opResize.h"
#include"ophide.h"
#include "operations/opMove.h"
#include"opstart.h"

#include"operations/opUnhide.h"
//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_LINE:
			//pOp = new ophide(this);
			
			//pOp = new opCancelFillingGeneral(this);
			pOp = new opAddline(this);
			break;

		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;

		case DRAW_TRI:
			pOp = new opAddtriangle(this);

			//pOp = new opmultidelete(this);
			
			//pOp = new opsendtoback(this);
			//pOp = new opAddtriangle(this);
			//pOp = new opMove(this);
			break;
			
		case DRAW_SQUARE:
			pOp = new opAddsquare(this);
			break;

		case DRAW_CIRC:
			pOp = new opAddCircle(this);
			break;

		case DRAW_OVAL:
			pOp = new opAddOval(this);
			break;

		case EXIT:
			pOp = new Opexit(this);
			break;
		case SAVE:
			pOp = new opsave(this);
			break;
		case BRUSH_SINGLE: 
			pOp = new Opchangefillcolor(this);
			break;
		case BORDER_COLOR_GENERAL:
			pOp = new opCHangeGeneralDrawcolor(this);
			break;
		case BORDER_COLOR_SINGLE:
			pOp = new opbordercolor(this); 
			break;
		case BRUSH_GENERAL: 
			pOp = new opChangeGeneralFillColor(this);
			
			break;
		case BORDER_SINGLE: 
			pOp = new opborderwidth(this);
			break;
		case MOVE:
			pOp = new opMove(this);
			break;
		case STATUS:	//a click on the status bar ==> no operation
			break;
		case DEL:
			//pOp = new opCancelFillingGeneral(this);
			pOp = new opdeleteshape(this);
			//break;
		case RESIZE:
			//pOp = new opCancelFillingGeneral(this);
			pOp = new opResize(this);
			break;
		case ROTATE:
			pOp = new opRotate(this);
			break;
	//	case TO_PLAY:
		//	pOp = new opswitchlaymode(this);
			//break;
		case TO_PLAY:

			pOp = new opswitchlaymode(this);
			//pOp = new opRotate(this);
			break;
		case LOAD:
			pOp = new opload(this);
			break;
		case DRAW_IRRPOLYGON:
			pOp = new opAddIrrPolygon(this);
			break;
		case DRAW_REGPOLYGON:
			pOp = new opAddRegPolygon(this);
			break;
		case SELECT:
			pOp = new opSelect(this);
			break;
		case Pen_Width:
			pOp = new opchangepenwidth(this);
			break;
		case MultiSelect:
			pOp = new opMultiSelect(this);
			break;
		case ZOOM_IN:
			pOp = new opZoomIn(this);
			break;
		case ZOOM_OUT:
			pOp = new opZoomOut(this);
			break;

		case hide:
			pOp = new ophide(this);
			break;
		case scramble:
		//	pOp = new opscramble(this);
			pOp = new opUnhide(this);
			break;
		case duplicate:
			pOp = new opdublicate(this);
			break;
		case COPY:
			pOp = new opAddline(this);
			break;
		case PASTE:
			pOp = new opAddRect(this);
			break;	
		case MULTIDELTE:
			pOp = new opmultidelete(this);
			break;
		case sendtoback: 
			pOp = new opsendtoback(this);
			break;
		case start:
			pOp = new opstart(this);
			break;
	}

	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	

	pGraph->Draw(pGUI);
	//pGraph->hide2(pGUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}

//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}