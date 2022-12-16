
#pragma once
#include"../operations/operation.h"
class opbordercolor : public operation
{
public:
	opbordercolor(controller* pCont);
	virtual void Execute();

};

