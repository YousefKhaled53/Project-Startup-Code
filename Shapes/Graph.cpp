#include "Graph.h"
#include "../GUI/GUI.h"
#include<fstream>
#include"Shape.h"
#include"Rect.h"
#include <iostream>
#include <string>
#include"Shape.h"

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
}


shape* Graph::Getshape(int x, int y) const
{
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL


	///Add your code here to search for a shape given a point x,y	

	return nullptr;
}
void Graph::deleteshape(shape* pShp) {
	shapesList.erase(find(shapesList.begin(), shapesList.end(), pShp));
}
void Graph::Save(ofstream& outfile) {
	for (int i = 0; i < (sizeof(shapesList) / sizeof(shapesList[0])); i++) {
	//	shapesList[i]->Save(ofstream & OutFile); //why error 	
	}
}
color Graph::changestringtoints(string colorstring) {
	if (colorstring == "Black") {
		color c(0, 0, 0);
	}
	// and do more colors ( about 10 ) 	
}
void Graph::load(ifstream& inputfile) { // how to initialize the ID of each shape and is my code enough or there are somthings i need to implement more
	string arr[4]; // an array that has 0 : current draw color , 1 : fill color , 2 : current pen width , 3: number of shapes 
	getline(inputfile, arr[0], ' ');
	getline(inputfile, arr[1], ' ');
	getline(inputfile, arr[2]);
	getline(inputfile, arr[3]);
	//setborderwidth(stoi(arr[2])); // to set border width
	int size = stoi(arr[3]); // to get no of files as an int 
	string arr2[11];

	for (int i = 0; i < (size * 11); i++) {
		getline(inputfile, arr2[i], ' ');
		if (arr2[i] == "RECT") {
			Point p1, p2;
			GfxInfo info;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2.x = stoi(arr2[i + 4]);
			p2.y = stoi(arr2[i + 5]);
			info.DrawClr = changestringtoints(arr2[i + 6]); // to initialize the draw color
			if (arr2[i + 7] == "NO_FILL") {
				info.FillClr = changestringtoints("white"); // to make the fillcolor white
			}
			else
				info.FillClr = changestringtoints(arr2[i + 7]); //to initialize the fill color
			info.BorderWdth = stoi(arr2[i + 8]);
			Rect* R = new Rect(p1, p2, info);
			R->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(R);

		}
	}
	inputfile.close();
}
