#pragma once

#include "DEFS.h"
#include "shapes/Graph.h"
#include "GUI\GUI.h"
#include "operations/opRotate.h"

class operation; //forward declaration

//Main class that manages everything in the application.
class controller
{
//	window* pWind;
	Graph* pGraph;	//pointe to the grapg
	GUI* pGUI;		//Pointer to UI class
	 // number of shapes created 

public:	
	controller(); 
	~controller();
	
	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	operationType GetUseroperation() const;
	operation* createOperation(operationType) ; //Creates an operation
	void Run();
	
	Graph* getGraph() const;
	
	// -- Interface Management Functions
	GUI *GetUI() const; //Return pointer to the UI
	void UpdateInterface() const;	//Redraws all the drawing window	

};

