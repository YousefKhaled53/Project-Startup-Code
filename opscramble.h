#pragma once
#include"controller.h"
#include"operations/operation.h"
class opscramble : public operation 
{
public :
	opscramble(controller* pCont);
	virtual void Execute();
};

