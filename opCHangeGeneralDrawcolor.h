#pragma once
#include"controller.h";
#include"operations/operation.h"
class opCHangeGeneralDrawcolor: public operation
{
public:
	opCHangeGeneralDrawcolor(controller* pCont);
	~opCHangeGeneralDrawcolor();
	virtual void Execute();

};

