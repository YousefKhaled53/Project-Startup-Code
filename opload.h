#pragma once
#include"operations/operation.h"
#include<iostream>
#include<fstream>
#include"Shapes/Shape.h"
#include"controller.h"
class opload : public operation
{
public:
	opload(controller* pCont) : operation(pCont) {};
	void Execute() {
		GUI* pUI = pControl->GetUI();
		pUI->PrintMessage("write file name");
		ifstream loadingfile(pUI->GetSrting());
		pControl->getGraph()->load(loadingfile);

	}

};

