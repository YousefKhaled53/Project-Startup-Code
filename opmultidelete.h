#pragma once
#include"operations/operation.h"
class opmultidelete:public operation
{
public:
	opmultidelete(controller* pCont);
	virtual void Execute();
};

