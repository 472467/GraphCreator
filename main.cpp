#include "vertex.h"
#include "edge.h"

#include <iostream>
#include <fstream> 
#include <ctype.h>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#include <vector>

using namespace std;

void translateInput(char*, int**&, Vertex**&);
void printShit(int**, Vertex**);
void addVertex(int**&, Vertex**&, char*);

int main(){
	
	int** adjTable = new int*[20];
	Vertex** vertices = new Vertex*[20];
	
	
	for(int x = 0; x < 20; x++){
		adjTable[x] = new int[20];
		vertices[x] = new Vertex();
		for(int y = 0; y < 20; y++){
			adjTable[x][y] = -1;
		}
	}
	
	cout << "Typed commands will give further instructions.\n";
	
	//TreeNode* head = NULL;
	
	while(true){//infinite loop closed by entering q
		char* input = new char[10];
		cout << "\n(AV)Add-Vertex // (RV) Remove-vertex // (AE) Add-Edge // (RE) Remove-Edge \n(FP) Find-Path // (P) Print // (Q) Quit";
		cout << "\nEnter command:" ;
		cin.getline(input, 10);
		
		translateInput(input, adjTable, vertices);
	}
}

void translateInput(char* input, int**& adjTable, Vertex**& vertices){//converts input into commands
	char* input2 = new char[40];
	if(strcasecmp(input, "AV") == 0 || strcasecmp(input, "Add-Vertex") == 0){
		cout << "Enter label for Vertex:\n";
		cin.getline(input2, 40);
		addVertex(adjTable, vertices, input2);
		
	}else if(strcasecmp(input, "RV") == 0 || strcasecmp(input, "Remove-Vertex") == 0){
		
		
	}else if(strcasecmp(input, "AE") == 0 || strcasecmp(input, "Add-Edge") == 0){
		
		
	}else if(strcasecmp(input, "RE") == 0 || strcasecmp(input, "Remove-Edge") == 0){
		
		
	}else if(strcasecmp(input, "FP") == 0 || strcasecmp(input, "Find-Path") == 0){
		
		
	}else if(strcasecmp(input, "P") == 0 || strcasecmp(input, "Print") == 0){
		printShit(adjTable, vertices);
		
	}else if(strcasecmp(input, "Q") == 0 || strcasecmp(input, "Quit") == 0){
		exit(101);
		
	}else{
		cout << "\nCommand unrecognized.\n";
	}
}

void addVertex(int**& adjTable, Vertex**& vertices, char* label){
	int num = -1;
	for(int x = 0; x < 20; x++){
		if(vertices[x]->getID() == -1){
			vertices[x] = new Vertex(x, label);
			num = x;
			x = 21;
		}
	}
	
	if(num != -1){
		for(int x = 0; x < 20; x++){//sets things up in the adjTable
			for(int y = 0; y < 20; y++){
				if(x == num || y == num){
					adjTable[x][y] = 0;
				}
			}
			
		}
	}else{
		cout << "Table FUll!";
	}
}

void printShit(int** adjTable, Vertex** vertices){
	if(adjTable[0][0] == -1){
		cout << "Nothing to print!\n";
	}else{
		for(int x = 0; x < 20; x++){//print adj Labels
			if(vertices[x]->getID() == -1){
				x = 21;
			}else{
				cout << x << " = " << vertices[x]->getLabel() << " // ";
			}
		}
	
		cout << endl;
	
		for(int x = 0; x < 20; x++){//print Adjacency table
			for(int y = 0; y < 20; y++){
				if(adjTable[x][y] != -1){
					cout << adjTable[x][y] << " ";
				}
			}
			cout << "\n";
		}
	}
	
}









