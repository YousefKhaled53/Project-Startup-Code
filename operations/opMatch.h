#pragma once
#include <fstream>
#include<iostream>
#include"operation.h"
#include"../Shapes/Shape.h"
#include"../controller.h"
#include "../Shapes/Graph.h"
#include "../GUI/GUI.h"
class opMatch : public operation {
private:


public:
	opMatch(controller* pcont);
	virtual ~opMatch();
	virtual void Execute();

};