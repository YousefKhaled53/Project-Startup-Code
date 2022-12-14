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

//#include "operations/"

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
			pOp = new opAddline(this);
			
			break;

		case DRAW_RECT:
			pOp = new opAddRect(this);
			//pOp = new opAddRect(this);
			//pOp = new opload(this);
			break;

		case DRAW_TRI:
			pOp = new opAddtriangle(this);
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
			///create Exitoperation here
			break;
		case SAVE:
			pOp = new opsave(this);
			break;

		case STATUS:	//a click on the status bar ==> no operation
			break;
		case DELTE:
			pOp = new opdeleteshape(this);
			break;
		case TO_PLAY:
			pOp = new opswitchlaymode(this);
			break;
		case LOAD:
			pOp = new opload(this);
			break;
		case DRAW_IRRPOLYGON:
			pOp = new opAddIrrPolygon(this);
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