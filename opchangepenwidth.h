#pragma once
#include"controller.h"
#include"operations/operation.h"
#include"../Project-Startup-Code/operations/operation.h"
class opchangepenwidth : public operation
{	public:

	opchangepenwidth(controller* pCont) :operation(pCont) {}
	virtual void Execute() {
		GUI* pUI = pControl->GetUI();
		pUI->PrintMessage("write the penwidth");
		int pw;
		pw = stoi(pUI->GetSrting());
		pUI->Setpenwidth(pw);
	}

};

