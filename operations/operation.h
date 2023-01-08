#pragma once
#include "..\DefS.h"
#include "..\GUI\GUI.h"

class controller; //forward class declaration


//Base class for all possible operations
class operation
{
protected:
	controller *pControl;	//operations needs control to do their job

public:
	//bool ask =false;
	operation(controller *pCont) { pControl = pCont; }	//constructor
	virtual ~operation(){}

	//Execute operation (code depends on operation type)
	virtual void Execute() =0;
	//void setasktrue() { ask = true; };
	//void setaskfalse() { ask = false; };
	//bool getask() { return ask; }
	bool Abort(Point P) {
		return (P.x >= 1247 && P.x <= 1300);
	}

	//To undo this operation (code depends on operation type)
	//virtual void Undo()=0;

	//To redo this operation (code depends on operation type)
<<<<<<< Updated upstream
	//virtual void Redo()=0;
=======
//	virtual void Redo()=0;
>>>>>>> Stashed changes

};

