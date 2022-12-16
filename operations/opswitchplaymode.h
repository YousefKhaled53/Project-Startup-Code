#pragma once
#include"../GUI/GUI.h"
#include"operation.h"
#include "../controller.h"

class opswitchlaymode : public operation {
public:
	opswitchlaymode(controller *pcont) :operation(pcont) {};
	~opswitchlaymode() {};
	virtual void Execute() {
		GUI* pUI = pControl->GetUI();
		
		//pUI->ClearStatusBar();
		//pUI->ClearDrawToolBar();
		pUI->CreatePlayToolBar();
		//what should be written here ??
	} // the function which will be responsible for changing to play mode
};

