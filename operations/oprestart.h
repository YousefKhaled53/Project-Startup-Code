#pragma once
#include"operation.h"
#include"../controller.h"
class oprestart: public operation
{
private:
public:
	oprestart(controller* pCont);
	~oprestart();
	virtual void Execute();
};