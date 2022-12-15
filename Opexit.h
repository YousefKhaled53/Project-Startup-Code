#pragma once
#include"controller.h"
#include"operations/opsave.h"
#include"operations/operation.h"
#include<fstream>
class Opexit : public operation
{
public:
	Opexit(controller* pCont) :operation(pCont) {}
	virtual void Execute(){
		
		GUI* pUI = pControl->GetUI();
		pUI->PrintMessage("do you like to save ");
		
		string ask = pUI->GetSrting();
		if (ask == "yes") {
			pUI->PrintMessage("write file name");
			ofstream savingfile(pUI->GetSrting()); // shouldn't get string return a string to be used by the program ? why does it use printmessage function
			pControl->getGraph()->Save(savingfile); // how to call save all function 
			pUI->PrintMessage("saved !");
		}
	}
};

