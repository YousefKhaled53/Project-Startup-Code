#include "opdublicate.h"
#include"fstream"
opdublicate::opdublicate(controller* pCont) :operation(pCont) {};
void opdublicate::Execute() {
	GUI* pUI = pControl->GetUI();
	pControl->getGraph()->dublicate();
<<<<<<< Updated upstream
=======
	
>>>>>>> Stashed changes
}
