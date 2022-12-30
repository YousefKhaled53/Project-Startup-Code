#pragma once
#include"controller.h"
#include"operations/operation.h"
class opChangeGeneralFillColor : public operation
{
public:
	opChangeGeneralFillColor(controller* pCont);
	~opChangeGeneralFillColor();
	virtual void Execute();

};

