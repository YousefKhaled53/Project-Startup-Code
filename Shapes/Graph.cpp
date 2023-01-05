#include "Graph.h"
#include "../GUI/GUI.h"
#include<fstream>
#include"Shape.h"
#include"Rect.h"
#include <iostream>
#include <string>
#include"Shape.h"
#include"../Shapes/line.h"
#include"../Shapes/triangle.h"
#include"../Shapes/Circle.h"
#include "../Shapes/Oval.h"
#include"../CMUgraphicsLib/colors.h"
#include"../Shapes/square.h"
#include"Circle.h"
#include"line.h"
#include"square.h"
#include"../controller.h"
#include"RegPolygon.h"
#include "../GUI/GUI.h"
#include<algorithm>

Graph::Graph()
{
	selectedShape = nullptr;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{	
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);

	//pUI->CreateDrawToolBar2();
	//pUI->CreateDrawToolBar();
	//pUI->CreateStatusBar();

}


void Graph::deleteshape(shape* pShp) {
	shapesList.erase(find(shapesList.begin(), shapesList.end(), pShp));
}

void Graph::Rotate(shape* pFig) {
	for (int i = 0; i < shapesList.size(); i++) {
		if (shapesList[i]->IsSelected()) {
			shapesList[i]->Rotate();
		}
	}
}

void Graph::Resize(shape* pFig, double ratio) {
	for (int i = 0; i < shapesList.size(); i++) {
		if (shapesList[i]->IsSelected()) {
			shapesList[i]->Resize(ratio);
		}
	}
};


void Graph::Save(ofstream & outfile) {
		int zz = shapesList.size();
		outfile << "blue green 5" << endl;
		outfile << shapesList.size() << endl;
		outfile << "FORMAT : SHAPE	NAME	 ID x,y for n points	redintensityfordrawcolor	greenintensityfordrawcolor	blueintensityfordrawcolor	greenintensityforfillcolor	blueintensityforfillcolor	redintensityforfillcolor	penwidth" << endl;
		for (int i = 0; i < zz; i++) {

			shapesList[i]->Save(outfile, i + 1);

		}
	};
//void Graph::move(shape* pFig, Point P1, Point P2) {
	//pWind->WaitMouseClick(P2.x, P2.y);
	//while (pWind->GetButtonState(LEFT_BUTTON, P2.x, P2.y)) {
	//if (pGr->GetSelected()) {
		//pGr->GetSelected()->move(P1, P2); // is done after making select function 
		//Sleep(16);
	//}
//}
//};

color Graph::changestringtoints(int r, int g, int b) {
	color c(r, g, b);
	return c;

}
void Graph::load(ifstream& inputfile) { // how to initialize the ID of each shape and is my code enough or there are somthings i need to implement more
	string arr[5];  
	getline(inputfile, arr[0], ' ');
	getline(inputfile, arr[1], ' ');
	getline(inputfile, arr[2]);
	getline(inputfile, arr[3]);
	getline(inputfile, arr[4]);

	int size = stoi(arr[3]); // to get no of files as an int 
	
	string* arr2 = new string[size * 20];

	for (int i = 0; i < (size *30 ); i++) {
		getline(inputfile, arr2[i], ' ');

	}
	for (int i = 0; i < (size * 20); i++) {
		if (arr2[i] == "RECT") {
			Point p1, p2;
			GfxInfo shapeGfxinfo;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2.x = stoi(arr2[i + 4]);
			p2.y = stoi(arr2[i + 5]);
			shapeGfxinfo.DrawClr = changestringtoints(stoi(arr2[i + 6]), stoi(arr2[i + 7]),stoi(arr2[i + 8])); // to initialize the draw color
			if (arr2[i +9] == "NO_FILL") {
				shapeGfxinfo.isFilled = FALSE; // to make the fillcolor white
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 10]);
			}
			else{
				shapeGfxinfo.FillClr = changestringtoints(stoi(arr2[i + 9]), stoi(arr2[i + 10]), stoi(arr2[i + 11])); //to initialize the fill color
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 12]);
			}
			shapeGfxinfo.isSelected = FALSE;
			Rect* R = new Rect(p1, p2, shapeGfxinfo);
			R->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(R);
		}
		if (arr2[i] == "CIRCLE") {
			Point p1, p2;
			GfxInfo shapeGfxinfo;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2.x = stoi(arr2[i + 4]);
			p2.y = stoi(arr2[i + 5]);
			shapeGfxinfo.DrawClr = changestringtoints(stoi(arr2[i + 6]), stoi(arr2[i + 7]), stoi(arr2[i + 8])); // to initialize the draw color
			if (arr2[i + 9] == "NO_FILL") {
				shapeGfxinfo.isFilled = FALSE; // to make the fillcolor white
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 10]);
			}
			else {
				shapeGfxinfo.FillClr = changestringtoints(stoi(arr2[i + 9]), stoi(arr2[i + 10]), stoi(arr2[i + 11])); //to initialize the fill color
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 12]);
			}
			shapeGfxinfo.isSelected = FALSE;
			Circle* c= new Circle(p1, p2, shapeGfxinfo);
			c->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(c);
		}
		if (arr2[i] == "LINE") {
			Point p1, p2;
			GfxInfo shapeGfxinfo;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2.x = stoi(arr2[i + 4]);
			p2.y = stoi(arr2[i + 5]);
			shapeGfxinfo.DrawClr = changestringtoints(stoi(arr2[i + 6]), stoi(arr2[i + 7]), stoi(arr2[i + 8])); // to initialize the draw color
			shapeGfxinfo.BorderWdth = stoi(arr2[i + 9]);
			shapeGfxinfo.isFilled = false;
			shapeGfxinfo.isSelected = FALSE;
			line* l = new line(p1, p2, shapeGfxinfo);
			l->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(l);
		}
		if (arr2[i] == "OVAL") {
			Point p1, p2;
			GfxInfo shapeGfxinfo;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2.x = stoi(arr2[i + 4]);
			p2.y = stoi(arr2[i + 5]);
			shapeGfxinfo.DrawClr = changestringtoints(stoi(arr2[i + 6]), stoi(arr2[i + 7]), stoi(arr2[i + 8])); // to initialize the draw color
			if (arr2[i + 9] == "NO_FILL") {
				shapeGfxinfo.isFilled = FALSE; // to make the fillcolor white
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 10]);
			}
			else {
				shapeGfxinfo.FillClr = changestringtoints(stoi(arr2[i + 9]), stoi(arr2[i + 10]), stoi(arr2[i + 11])); //to initialize the fill color
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 12]);
			}
			shapeGfxinfo.isSelected = FALSE;
			Oval* o = new Oval(p1, p2, shapeGfxinfo);
			o->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(o);
		}
		if (arr2[i] == "SQUARE") {
			Point p1, p2;
			GfxInfo shapeGfxinfo;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2.x = stoi(arr2[i + 4]);
			p2.y = stoi(arr2[i + 5]);
			shapeGfxinfo.DrawClr = changestringtoints(stoi(arr2[i + 6]), stoi(arr2[i + 7]), stoi(arr2[i + 8])); // to initialize the draw color
			if (arr2[i + 9] == "NO_FILL") {
				shapeGfxinfo.isFilled = FALSE; // to make the fillcolor white
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 10]);
			}
			else {
				shapeGfxinfo.FillClr = changestringtoints(stoi(arr2[i + 9]), stoi(arr2[i + 10]), stoi(arr2[i + 11])); //to initialize the fill color
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 12]);
			}
			shapeGfxinfo.isSelected = FALSE;
			square* s = new square(p1, p2, shapeGfxinfo);
			s->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(s);

		}
		if (arr2[i] == "TRIANGLE") {
			Point p1, p2,p3;
			GfxInfo shapeGfxinfo;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2.x = stoi(arr2[i + 4]);
			p2.y = stoi(arr2[i + 5]);
			p3.x = stoi(arr2[i + 6]);
			p3.y = stoi(arr2[i + 7]);
			shapeGfxinfo.DrawClr = changestringtoints(stoi(arr2[i + 8]), stoi(arr2[i + 9]), stoi(arr2[i + 10])); // to initialize the draw color
			if (arr2[i + 11] == "NO_FILL") {
				shapeGfxinfo.isFilled = FALSE; // to make the fillcolor white
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 12]);
			}
			else {
				shapeGfxinfo.FillClr = changestringtoints(stoi(arr2[i + 11]), stoi(arr2[i + 12]), stoi(arr2[i + 13])); //to initialize the fill color
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 14]);
			}
			shapeGfxinfo.isSelected = FALSE;
			triangle* t = new triangle(p1, p2,p3, shapeGfxinfo);
			t->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(t);
		}
		if (arr2[i] == "REGULAR") {
			Point p1;
			Point* p2=new Point;
			int num;
			GfxInfo shapeGfxinfo;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2->x = stoi(arr2[i + 4]);
			p2->y = stoi(arr2[i + 5]);
			num = stoi(arr2[i + 6]);
			shapeGfxinfo.DrawClr = changestringtoints(stoi(arr2[i + 7]), stoi(arr2[i + 8]), stoi(arr2[i + 9])); // to initialize the draw color
			if (arr2[i + 10] == "NO_FILL") {
				shapeGfxinfo.isFilled = FALSE; // to make the fillcolor white
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 11]);
			}
			else {
				shapeGfxinfo.FillClr = changestringtoints(stoi(arr2[i + 10]), stoi(arr2[i + 11]), stoi(arr2[i + 12])); //to initialize the fill color
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 13]);
			}
			shapeGfxinfo.isSelected = FALSE;
			RegPolygon* p = new RegPolygon(p1, p2, num, shapeGfxinfo);
			p->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(p);
		}
		/*if (arr2[i] == "IRREGULAR") {
			
			Point* p1 = new Point;
			int num;
			int* arrx = new int[num];
			int* arry = new int[num];
			GfxInfo shapeGfxinfo;
			num = stoi(arr[i + 2]);
			p1->x = stoi(arr2[i + 3]);
			p1->y = stoi(arr2[i + 4]);
			for (int i = 0; i < (num * 2); i++) {
			num = stoi(arr2[i + 6]);
			shapeGfxinfo.DrawClr = changestringtoints(stoi(arr2[i + 7]), stoi(arr2[i + 8]), stoi(arr2[i + 9])); // to initialize the draw color
			if (arr2[i + 10] == "NO_FILL") {
				shapeGfxinfo.isFilled = FALSE; // to make the fillcolor white
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 11]);
			}
			else {
				shapeGfxinfo.FillClr = changestringtoints(stoi(arr2[i + 10]), stoi(arr2[i + 11]), stoi(arr2[i + 12])); //to initialize the fill color
				shapeGfxinfo.BorderWdth = stoi(arr2[i + 13]);
			}
			shapeGfxinfo.isSelected = FALSE;
			RegPolygon* p = new RegPolygon(p1, p2, num, shapeGfxinfo);
			p->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(p);
		}*/

		

	}
	delete [] arr2;
	inputfile.close();
}
shape* Graph::GetSelected() {
	return selectedShape;
}
void Graph::changefillcolor(shape* pFig, color newcolor) {
	pFig->ChngFillClr(newcolor);
	pFig->setisfilled();	
}
void Graph::bordercolor(shape* pFig, color newcolor) {
	pFig->ChngDrawClr(newcolor);

}
void Graph::borderwidth(shape* pFig, int bw) {
	pFig->changeborderwidth(bw);
}

void Graph::SetSelected(shape* s) {
	selectedShape = s;
}
shape* Graph::Getshape(int x, int y)
{
	
	for (auto shapePointer : shapesList)
		if (shapePointer->is_in_fig(x, y)) {
			return shapePointer;
		}
	
	
	return nullptr;
}
int Graph::getsizeofvector() {
	return shapesList.size();
}
void Graph::scramble() {
	srand(time(0));
	int x = rand();
	for (int i = 0; i < shapesList.size(); i++) {
		
		shapesList[i]->scramble();
	}
}
void Graph::dublicate() {
	const int z = shapesList.size();
	/*GfxInfo line;
	line.BorderWdth = shapesList[0]->getborderwidth();
	line.DrawClr = shapesList[0]->getdrawclr();
	line.FillClr = shapesList[0]->getfillclr();
	line.isFilled = shapesList[0]->getisfilled();
	line.isSelected = false;
	POINT p1, p2;
	p1.x= shapesList[0]
		Circle* p = (Circle*)shapesList[i];
		if (Circle) {

		}
	*/
	for (int i = 0; i < z; i++) {
		shapesList.push_back(shapesList[i]);
		int currentreplicaindex = i + z;
		//int previd = shapesList[i]->getid();
		shapesList[currentreplicaindex]->setid(i);
	}
}
void Graph::sendtoback(shape* pShp) {
	for (int i = 0; i < shapesList.size(); i++) {
		shapesList.erase(find(shapesList.begin(), shapesList.end(), pShp));
		shapesList.insert(shapesList.begin(), pShp);
	}
}
void Graph::multiselect(int arrx[], int arry[], int size) {
	for (auto shapePointer : shapesList)
		for (int i = 0; i < size; i++) {
			if (shapePointer->is_in_fig(arrx[i], arry[i])) {
				shapePointer->SetSelected(true);
				multishapesselected.push_back(shapePointer);
			}
		}
}
void Graph::multidelete (){
	for (int i = 0; i < multishapesselected.size(); i++) {
	shapesList.erase(find(shapesList.begin(), shapesList.end(), multishapesselected[i]));
	}
}
void Graph::hide(GUI* pUI) {
	for (int i = 0; i < shapesList.size(); i++) {
		shapesList[i]->setishidentrue();
	}
}
void Graph::hide2(GUI* pUI) {
	for (int i = 0; i < shapesList.size(); i++) {
		shapesList[i]->hide(pUI);
	}
}
void Graph::deleteall() {
	for (int i = 0; i < shapesList.size(); i++) {
		shapesList.clear();
	}
}