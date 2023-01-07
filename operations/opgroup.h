#pragma once
#include"operation.h"
class opgroup :public operation
{
public:
	opgroup (controller* pCont);
	virtual void Execute();
};

