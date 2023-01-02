#include "opdublicate.h"
#include"fstream"
opdublicate::opdublicate(controller* pCont) :operation(pCont) {};
void opdublicate::Execute() {
	GUI* pUI = pControl->GetUI();
	pControl->getGraph()->dublicate();
	ofstream myfile;
	myfile.open("temp.txt");
	//myfile.close();
	pControl->getGraph()->Save(myfile);
	ifstream myfile("temp.txt");
//	pControl->getGraph()->load(myfile);
	myfile.close();
	
}
