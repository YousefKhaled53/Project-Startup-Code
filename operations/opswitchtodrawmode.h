#pragma once
#include"../GUI/GUI.h"
#include"operation.h"
#include "../controller.h"

class opswitchtodrawmode : public operation {
public:
	opswitchtodrawmode(controller* pcont) :operation(pcont) {};
	~opswitchtodrawmode() {};
	virtual void Execute() {
		GUI* pUI = pControl->GetUI();
		pUI->CreateDrawToolBar();
		pUI->CreateDrawToolBar2();

	}
};

