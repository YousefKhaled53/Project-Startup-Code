#pragma once
#include"operation.h"
class opungroup :public operation
{
public:
	opungroup(controller* pCont);
	virtual void Execute();
};

