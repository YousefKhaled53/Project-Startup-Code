#pragma once
#include "Operations/operation.h"
class opAddline :
    public operation
{
public:
	opAddline(controller* pCont);
	virtual ~opAddline();

	//Add line to the controller
	virtual void Execute();

};

