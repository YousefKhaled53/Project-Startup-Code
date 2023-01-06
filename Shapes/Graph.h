#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>

using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes	
	vector <shape*> multishapesselected;
	shape* selectedShape;	//pointer to the currently selected shape
public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y); //Search for a shape given a point inside the shape
	void borderwidth(shape* pFig, int bw);
	void bordercolor(shape* pFig, color newcolor);
	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
	void deleteshape(shape* pFig); // deletes a shape
	color changestringtoints(int r, int b, int g); // changes the string into color components
	shape* GetSelected();
	void SetSelected(shape* s);
	void changefillcolor(shape* pFig,color newcolor);
	int getsizeofvector();
	void scramble();
	void Match(GUI* pUI);
	void dublicate();
	void sendtoback(shape* pShp);
	void multiselect(int arrx[], int arry[],int size);
	void multidelete();
	void hide(GUI* pUI);
	void hide2(GUI* pUI);
	void Unhide(Point* P1);
	//void Move(shape* pFig, Point P1, Point P2);
	void Resize(shape* pFig , double ratio);
	//void move(shape* pFig, Point P1, Point P2);
	void Rotate(shape* pFig);
	void deleteall();

	

};
