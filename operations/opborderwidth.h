#pragma once
#include"../operations/operation.h"
class opborderwidth : public operation
{
public:
	opborderwidth(controller* pCont);
	virtual void Execute();

};

