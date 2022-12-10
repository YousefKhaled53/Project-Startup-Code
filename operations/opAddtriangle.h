#pragma once
#include "operation.h"
class opAddtriangle :
    public operation
{
public:
	opAddtriangle(controller* pCont) : operation(pCont) {};
	virtual ~opAddtriangle();

	//Add line to the controller
	virtual void Execute();
};

