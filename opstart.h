#pragma once
#include"controller.h"
#include"operations/operation.h"
class opstart : public operation
{
private :
	int i = 0;
public:
	opstart(controller* pCont);
	~opstart();
	virtual void Execute();
};

