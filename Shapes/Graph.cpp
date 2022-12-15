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
#include"../Shapes/square.h"
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
	int zz = shapesList.size();
	for (int i = 0; i < zz; i++) {
		shapesList[i]->Save(outfile); 

	}
}
color Graph::changestringtoints(string colorstring) {
	if (colorstring == "black") {
		color c(0, 0, 0);
		return c;
	}
	if (colorstring == "white") {
		color c(255,255,255);
		return c;
	}
	if (colorstring == "gray") {
		color c(128, 128, 128);
		return c;
	}

	if (colorstring == "yellow") {
		color c(255,255, 0);
		return c;
	}

	if (colorstring == "green") {
		color c(0, 255, 0);
		return c;
	}
	if (colorstring == "purple") {
		color c(160, 32, 255);
		return c;
	}
	if (colorstring == "blue") {
		color c(0,0, 255);
		return c;
	}
	if (colorstring == "orange") {
		color c(255, 165, 0);
		return c;
	}
	if (colorstring == "red") {
		color c(255, 0, 0);
		return c;
	}
	if (colorstring == "brown") {
		color c(160, 128, 96);
		return c;
	}

	// and do more colors 
}
void Graph::load(ifstream& inputfile) { // how to initialize the ID of each shape and is my code enough or there are somthings i need to implement more
	string arr[4]; // an array that has 0 : current draw color , 1 : fill color , 2 : current pen width , 3: number of shapes 
	getline(inputfile, arr[0], ' ');
	getline(inputfile, arr[1], ' ');
	getline(inputfile, arr[2]);
	getline(inputfile, arr[3]);
	//setborderwidth(stoi(arr[2])); // to set border width
	int size = stoi(arr[3]); // to get no of files as an int 
	
	string arr2[100];

	for (int i = 0; i < (size * 11); i++) {
		getline(inputfile, arr2[i], ' ');

	}
	for (int i = 0; i < (size * 11); i++) {
		if (arr2[i] == "RECT") {
			Point p1, p2;
			GfxInfo shapeGfxinfo;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2.x = stoi(arr2[i + 4]);
			p2.y = stoi(arr2[i + 5]);
			shapeGfxinfo.DrawClr = changestringtoints(arr2[i + 6]); // to initialize the draw color
			if (arr2[i + 7] == "NO_FILL") {
				shapeGfxinfo.isFilled = FALSE; // to make the fillcolor white
			}
			else
				shapeGfxinfo.FillClr = changestringtoints(arr2[i + 7]); //to initialize the fill color
			shapeGfxinfo.BorderWdth = stoi(arr2[i + 8]);
			//shapeGfxinfo.isFilled = FALSE;
			shapeGfxinfo.isSelected = FALSE;
			Rect* R = new Rect(p1, p2, shapeGfxinfo);
			R->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(R);
		}
		if (arr2[i] == "TRIANGLE") {
			Point p1, p2, p3;
			GfxInfo shapeGfxinfo;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2.x = stoi(arr2[i + 4]);
			p2.y = stoi(arr2[i + 5]);
			p3.x = stoi(arr2[i + 6]);
			p3.y = stoi(arr2[i + 7]);
			shapeGfxinfo.DrawClr = changestringtoints(arr2[i + 8]); // to initialize the draw color
			if (arr2[i + 9] == "NO_FILL") {
				shapeGfxinfo.isFilled = FALSE; // to make the fillcolor white
			}
			else
				shapeGfxinfo.FillClr = changestringtoints(arr2[i + 9]); //to initialize the fill color
			shapeGfxinfo.BorderWdth = stoi(arr2[i + 10]);
			shapeGfxinfo.isSelected = FALSE;
			triangle* t = new triangle(p1, p2, p3, shapeGfxinfo);
			t->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(t);
		}
		if (arr2[i] == "LINE") {
			Point p1, p2;
			GfxInfo shapeGfxinfo;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2.x = stoi(arr2[i + 4]);
			p2.y = stoi(arr2[i + 5]);
			shapeGfxinfo.DrawClr = changestringtoints(arr2[i + 6]); // to initialize the draw color
			shapeGfxinfo.BorderWdth = stoi(arr2[i + 7]);
			shapeGfxinfo.isFilled = FALSE;
			shapeGfxinfo.isSelected = FALSE;
			line* l = new line(p1, p2, shapeGfxinfo);
			l->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(l);
		}
		if (arr2[i] == "CIRCLE") {
			Point p1, p2;
			GfxInfo shapeGfxinfo;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2.x = stoi(arr2[i + 4]);
			p2.y = stoi(arr2[i + 5]);
			shapeGfxinfo.DrawClr = changestringtoints(arr2[i + 6]); // to initialize the draw color
			if (arr2[i + 7] == "NO_FILL") {
				shapeGfxinfo.isFilled = FALSE; // to make the fillcolor white
			}
			else
				shapeGfxinfo.FillClr = changestringtoints(arr2[i + 7]); //to initialize the fill color
			shapeGfxinfo.BorderWdth = stoi(arr2[i + 8]);
			shapeGfxinfo.isSelected = FALSE;
			Circle* c=new Circle(p1,p2,shapeGfxinfo);
			c->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(c);
		}
		if (arr2[i] == "OVAL") {
			Point p1, p2;
			GfxInfo shapeGfxinfo;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2.x = stoi(arr2[i + 4]);
			p2.y = stoi(arr2[i + 5]);
			shapeGfxinfo.DrawClr = changestringtoints(arr2[i + 6]); // to initialize the draw color
			if (arr2[i + 7] == "NO_FILL") {
				shapeGfxinfo.isFilled = FALSE; // to make the fillcolor white
			}
			else
				shapeGfxinfo.FillClr = changestringtoints(arr2[i + 7]); //to initialize the fill color
			shapeGfxinfo.BorderWdth = stoi(arr2[i + 8]);
			shapeGfxinfo.isSelected = FALSE;
			Oval* R = new Oval(p1, p2, shapeGfxinfo);
			R->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(R);
		}
		if (arr2[i] == "SQUARE") {
			Point p1, p2;
			GfxInfo shapeGfxinfo;
			p1.x = stoi(arr2[i + 2]);
			p1.y = stoi(arr2[i + 3]);
			p2.x = stoi(arr2[i + 4]);
			p2.y = stoi(arr2[i + 5]);
			shapeGfxinfo.DrawClr = changestringtoints(arr2[i + 6]); // to initialize the draw color
			if (arr2[i + 7] == "NO_FILL") {
				shapeGfxinfo.isFilled = FALSE; // to make the fillcolor white
			}
			else
				shapeGfxinfo.FillClr = changestringtoints(arr2[i + 7]); //to initialize the fill color
			shapeGfxinfo.BorderWdth = stoi(arr2[i + 8]);
			//shapeGfxinfo.isFilled = FALSE;
			shapeGfxinfo.isSelected = FALSE;
			square* s = new square(p1, p2, shapeGfxinfo);
			s->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
			Addshape(s);
		}
	}
	inputfile.close();
}
