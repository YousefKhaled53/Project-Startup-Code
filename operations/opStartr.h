#pragma once
#include"operation.h"
#include"../controller.h"
class opStartr : public operation
{
private:
public:
	opStartr(controller* pCont);
	~opStartr();
	virtual void Execute();
};

