#pragma once
#include"operations/operation.h"
#include"controller.h"
class opdublicate :public operation
{
public:
	opdublicate(controller* pCont);
	virtual void Execute();

};

