#pragma once
#pragma once
#include"operation.h"
class opUnhide : public operation
{
public:
	opUnhide(controller* pCont);
	virtual void Execute();
};
