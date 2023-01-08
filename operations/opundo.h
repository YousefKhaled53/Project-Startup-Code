#pragma once
#include"operation.h"
#include"../controller.h"
class opundo:public operation
{
public:
	opundo(controller* pCont);
	~opundo();
	virtual void Execute();


};
