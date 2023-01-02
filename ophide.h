#pragma once
#include"operations/operation.h"
class ophide : public operation 
{
public:
	ophide(controller* pCont);
	virtual void Execute();
};

