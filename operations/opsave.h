#pragma once
#include <fstream>
#include<iostream>
#include"operation.h"
#include"../Shapes/Shape.h"
#include"../controller.h"
#include "../Shapes/Graph.h"
class opsave : public operation
{
public:
	opsave(controller* pcont) :operation(pcont) {}
	~opsave() {}
	virtual void Execute() {
		GUI* pUI = pControl->GetUI();
		pUI->PrintMessage("write file name");
		ofstream savingfile(pUI->GetSrting()); // shouldn't get string return a string to be used by the program ? why does it use printmessage function
		pControl->getGraph()->Save(savingfile); // how to call save all function 
		pUI->PrintMessage("saved !");

	};

};

