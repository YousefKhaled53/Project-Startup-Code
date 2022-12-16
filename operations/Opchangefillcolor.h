#pragma once
#include"../operations/operation.h"
class Opchangefillcolor : public operation
{
public:
	Opchangefillcolor(controller* pCont);
	virtual void Execute();

};

