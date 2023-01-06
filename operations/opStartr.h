#pragma once
#include"operation.h"
#include"../controller.h"
class opStartr : public operation
{
private:
	int i = 0;
public:
	opStartr(controller* pCont);
	~opStartr();
	virtual void Execute();
};

