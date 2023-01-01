#pragma once

#include "../operations/operation.h"
class opPest:
	public operation
{
public:
	opPest(controller* pCont);

	virtual void Execute();
};

