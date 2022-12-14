#pragma once
#include"operation.h"
#include<iostream>
#include<fstream>
#include"../Shapes/Shape.h"
#include"../controller.h"
class opload : public operation
{
public:
	opload(controller* pCont) : operation(pCont) {};
	void Execute() {
		GUI* pUI = pControl->GetUI();
		pUI->PrintMessage("write file name.txt");
		ifstream loadingfile(pUI->GetSrting());
		pControl->getGraph()->load(loadingfile);

	}

};

