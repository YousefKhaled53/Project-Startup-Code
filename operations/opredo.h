#pragma once
#include"operation.h"
#include"../controller.h"
class opredo :public operation
{
public:
	opredo(controller* pCont);
	~opredo();
	virtual void Execute();


};
