#pragma once
#include"operations/operation.h"
class opsendtoback:public operation
{
public:
	opsendtoback(controller* pCont);
	virtual void Execute();
};

