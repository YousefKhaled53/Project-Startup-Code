#include "opdublicate.h"
#include"fstream"
opdublicate::opdublicate(controller* pCont) :operation(pCont) {};
void opdublicate::Execute() {
	GUI* pUI = pControl->GetUI();
	pControl->getGraph()->dublicate();
	ofstream myfile;
	myfile.open("temp.txt");
	pControl->getGraph()->Save(myfile);
	myfile.close();

	pControl->getGraph()->deleteall();

	ifstream file("temp.txt");
	pControl->getGraph()->load(file);
	myfile.close();
	remove("temp.txt");	
}
