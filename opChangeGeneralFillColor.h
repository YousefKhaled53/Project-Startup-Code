#pragma once
#include "../Project-Startup-Code/operations/operation.h"
#include"controller.h"
class opChangeGeneralFillColor : public operation
{
public:
	opChangeGeneralFillColor(controller* pCont);
	~opChangeGeneralFillColor();
	virtual void Execute();

};

