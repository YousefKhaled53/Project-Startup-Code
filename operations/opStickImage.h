#pragma once

#include "operation.h"

class opStickImage : public operation
{
public:
	opStickImage(controller* pCont);
	virtual ~opStickImage();
	//void StickImage();

	virtual void Execute();

};