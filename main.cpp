#include "vertex.h"
#include "edge.h"
//#include "path.h"

#include <iostream>
#include <fstream> 
#include <ctype.h>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#include <vector>
#include <string>

using namespace std;

void translateInput(char*, int**&, Vertex**&, vector<Edge*>&);
void printShit(int**, Vertex**, vector<Edge*>&);
void addVertex(int**&, Vertex**&, char*);
void removeVertex(int**&, Vertex**&, char*);
void addEdge(int**&, Vertex**&, vector<Edge*>&, char*, char*, char*);
void removeEdge(int**&, Vertex**&, vector<Edge*>&, char*, char*);
void findPath(int**&, Vertex**&, vector<Edge*>&, char*, char*);
void recursivePath(int**&, Vertex**&, vector<Edge*>&, int*&, Vertex*, Vertex*);



int main(){
	
	int** adjTable = new int*[20];
	Vertex** vertices = new Vertex*[20];
	vector<Edge*> edges;
	
	for(int x = 0; x < 20; x++){
		adjTable[x] = new int[20];
		vertices[x] = new Vertex();
		for(int y = 0; y < 20; y++){
			adjTable[x][y] = -1;
		}
	}
	cout << "Avoid using the same label multiple times, it will likely cause errors.\n";
	cout << "Typed commands will give further instructions.\n";
	
	//TreeNode* head = NULL;
	
	while(true){//infinite loop closed by entering q
		char* input = new char[10];
		cout << "\n(AV)Add-Vertex // (RV) Remove-vertex // (AE) Add-Edge // (RE) Remove-Edge \n(FP) Find-Path // (P) Print // (Q) Quit";
		cout << "\nEnter command:" ;
		cin.getline(input, 10);
		
		translateInput(input, adjTable, vertices, edges);
	}
}

void translateInput(char* input, int**& adjTable, Vertex**& vertices, vector<Edge*>& edges){//converts input into commands
	char* input2 = new char[40];
	if(strcasecmp(input, "AV") == 0 || strcasecmp(input, "Add-Vertex") == 0){
		cout << "Enter label for vertex to add:\n";
		cin.getline(input2, 40);
		addVertex(adjTable, vertices, input2);
		
	}else if(strcasecmp(input, "RV") == 0 || strcasecmp(input, "Remove-Vertex") == 0){
		cout << "Enter label of vertex to remove:";
		cin.getline(input2, 40);
		removeVertex(adjTable, vertices, input2);
		
	}else if(strcasecmp(input, "AE") == 0 || strcasecmp(input, "Add-Edge") == 0){
		char* input3 = new char[40];
		char* input4 = new char[40];
		cout << "Enter start label of edge to add:";
		cin.getline(input2, 40);
		cout << "\nEnter end label of edge to add:";
		cin.getline(input3, 40);
		cout << "\nEnter weight of edge to add:";
		cin.getline(input4, 40);
		
		addEdge(adjTable, vertices, edges, input2, input3, input4);
		
	}else if(strcasecmp(input, "RE") == 0 || strcasecmp(input, "Remove-Edge") == 0){
		char* input3 = new char[40];
		cout << "Enter start label of edge to remove:";
		cin.getline(input2, 40);
		cout << "\nEnter end label of edge to remove:";
		cin.getline(input3, 40);
		
		removeEdge(adjTable, vertices, edges, input2, input3);
		
	}else if(strcasecmp(input, "FP") == 0 || strcasecmp(input, "Find-Path") == 0){
		char* input3 = new char[40];
		cout << "Enter start label of vertex to find:";
		cin.getline(input2, 40);
		cout << "\nEnter end label of vertex to find:";
		cin.getline(input3, 40);
		
		findPath(adjTable, vertices, edges, input2, input3);
		
	}else if(strcasecmp(input, "P") == 0 || strcasecmp(input, "Print") == 0){
		printShit(adjTable, vertices, edges);
		
	}else if(strcasecmp(input, "Q") == 0 || strcasecmp(input, "Quit") == 0){
		exit(101);
		
	}else{
		cout << "\nCommand unrecognized.\n";
	}
}

void findPath(int**& adjTable, Vertex**& vertices, vector<Edge*>& edges, char* labelStart, char* labelEnd){
	Vertex* source = NULL;
	Vertex* fin = NULL;
	char** visitedVertices = new char*[20];
	char** bestPath = new char*[edges.size()];
	for(int x = 0; x< 20; x++){
		visitedVertices[x] = "!";
	}
	
	for(int x = 0; x < 20; x++){
		if(vertices[x]->getID() != -1){
			if(strcasecmp(vertices[x]->getLabel(), labelStart) == 0){
				source = vertices[x];
			}else if(strcasecmp(vertices[x]->getLabel(), labelEnd) == 0){
				fin = vertices[x];
			}
		}else{
			x = 21;
		}
	}
	
	if(source != NULL && fin != NULL){
		if(edges.size() == 0 || true){
			//int*&, Vertex*, Vertex*
			int* visitedEdges = new int[40];
			recursivePath(adjTable, vertices, edges, visitedEdges, source, fin);
			
			if(fin->getRunningDistance() == -1){
				cout << "\nNo path to vertex!\n";
			}else{
				cout << "\nShortest Path: " << fin->getRunningDistance() << endl;
			}
		}else{
			cout << "Error! No edges\n ";
		}
		
		
	}else{
		cout << "Error! ";
		if(source  == NULL){
			cout << "Source not found ";
		}
		
		if(fin == NULL){
			cout << "End not found or same label name as source";
		}
		cout<< endl;
	}
	
}

void recursivePath(int**& adjTable, Vertex**& vertices, vector<Edge*>& edges, int*& visitedEdges, Vertex* current, Vertex* fin){
	
	int currentVisited = 0;
	
	if(true){
		Edge** outgoingEdges = new Edge*[20];
		Vertex** outgoingVertices = new Vertex*[20];
		for(int x  = 0; x < 20; x++){
			outgoingEdges[x] = NULL;
			outgoingVertices[x] = new Vertex();
		}
		int currentEdgeNum = 0;
		for(vector<Edge*>::iterator it = edges.begin(); it != edges.end(); ++it){
			if(vertices[(*it)->getStartId()]->getLabel() == current->getLabel()){
				outgoingEdges[currentEdgeNum] = (*it);
				for(int x= 0; x< 20; x++){
					outgoingVertices[currentEdgeNum] = vertices[outgoingEdges[currentEdgeNum]->getEndId()];
				}
				currentEdgeNum++;
			}
		}
		
		if(outgoingEdges[0] == NULL){
		}else{
			for(int x = 0; x < currentEdgeNum; x++){
				bool visited = false;
				int endVisited = -1;
				
				for(int z = 0; z < 40; z++){
					if(visitedEdges[z] == -1){
						endVisited = z;
						z = 41;
					}else{
						if(outgoingEdges[x]->getID() == visitedEdges[z]){
							visited = true;
						}
					}
				}
				if(!visited){
					if(outgoingVertices[x]->getRunningDistance() == -1){
						outgoingVertices[x]->setRunningDistance(current->getRunningDistance() + outgoingEdges[x]->getWeight());
					}else{
						float newDistance = current->getRunningDistance() + outgoingEdges[x]->getWeight();
						if(newDistance < outgoingVertices[x]->getRunningDistance()){
							outgoingVertices[x]->setRunningDistance(current->getRunningDistance() + newDistance);
						}
					}
					visitedEdges[endVisited] = outgoingEdges[x]->getID();
					
					for(int w = 0; w < currentEdgeNum; w++){
						current = outgoingVertices[w];
						recursivePath(adjTable, vertices, edges, visitedEdges, current, fin);
					}
				}
			}
		}
	}
	
}

void addEdge(int**& adjTable, Vertex**& vertices, vector<Edge*>& edges, char* labelStart, char* labelEnd, char* weight){
	//check if vertices exist
	//then check if edge already exists
	
	bool startValid = false;
	int startId = -1;
	bool endValid = false;
	int endId = -1;
	
	for(int x = 0; x < 20; x++){
		if(vertices[x]->getID() != -1){
			if(strcasecmp(labelStart, vertices[x]->getLabel()) == 0 && !startValid){
				startValid = true;
				startId = x;
			}else if(strcasecmp(labelEnd, vertices[x]->getLabel()) == 0 && !endValid){
				endValid = true;
				endId = x;
			}
			
		}else{
			x = 21;
		}
	}
	if(startValid && endValid){
		bool existsAlready = false;
		for(vector<Edge*>::iterator it = edges.begin(); it != edges.end(); ++it){
			if(startId == (*it)->getStartId() && endId == (*it)->getEndId()){
				cout << "Error! Edge already exists!";
				existsAlready = true;
			}
		}
		
		if(!existsAlready){
			float f = atof(weight);
			adjTable[startId][endId] = 1; 
			edges.push_back(new Edge(edges.size(), startId, endId, f));
		}
		
	}else{
		cout << "\nerror! ";
		if(!startValid){
			cout << "start vertex not found!\n\n";
		}
		
		if(!endValid){
			cout << "end vertex not found!\n\n";
		}
	}
	
}

void removeEdge(int**& adjTable, Vertex**& vertices, vector<Edge*>& edges, char* labelStart, char* labelEnd){
	bool startValid = false;
	int startId = -1;
	bool endValid = false;
	int endId = -1;
	
	for(int x = 0; x < 20; x++){
		if(vertices[x]->getID() != -1){
			if(strcasecmp(labelStart, vertices[x]->getLabel()) == 0 && !startValid){
				startValid = true;
				startId = x;
			}else if(strcasecmp(labelEnd, vertices[x]->getLabel()) == 0 && !endValid){
				endValid = true;
				endId = x;
			}
			
		}else{
			x = 21;
		}
	}
	if(startValid && endValid){
		bool existsAlready = false;
		int edgeId = -1;
		int count  = 0;
		for(vector<Edge*>::iterator it = edges.begin(); it != edges.end(); ++it){
			if(startId == (*it)->getStartId() && endId == (*it)->getEndId()){
				//cout << "Error! Edge already exists!";
				existsAlready = true;
				edgeId = count;
			}
			count++;
		}
		
		if(existsAlready){
			adjTable[startId][endId] = 0; 
			edges.erase(edges.begin() + edgeId);
		}
		
	}else{
		cout << "\nerror! ";
		if(!startValid){
			cout << "start vertex not found!\n\n";
		}
		
		if(!endValid){
			cout << "end vertex not found!\n\n";
		}
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
				if(x == num && y <= num){
					adjTable[x][y] = 0;
				} 
				
				if(y == num && x <= num){
					adjTable[x][y] = 0;
				}
			}
			
		}
	}else{
		cout << "Table FUll!";
	}
}



void removeVertex(int**& adjTable, Vertex**& vertices, char* label){
	int num = -1;
	for(int x = 0; x < 20; x++){
		if(vertices[x]->getID() != -1){
			if(strcasecmp(vertices[x]->getLabel(), label) == 0){
				num = x;
				
				if(x + 1 < 20){
					if(vertices[x+1]->getID() == -1){
						vertices[x] = new Vertex();
					}else{
						vertices[x] = new Vertex();
						for(int z = num; z < 20; z++){
							if(vertices[z+1]->getID() != -1 && z+1 < 20){
								vertices[z] = vertices[z+1];
								vertices[z+1] = new Vertex();
							}else{
								z = 21;
							}
						}
					}
				}
				x = 21;
			}
		}else{
			x = 21;
		}
	}
	
	if(num == -1){
		cout << "vertex not found sry\n";
	}else{
		/*
		0 1 0 0 0 0 0 1 
		1 1 1 1 1 1 1 1 
		0 1 x 0 0 0 0 1 
		0 1 0 x 0 0 0 1
		0 1 0 0 x 0 0 1 
		0 1 0 0 0 x 0 1 
		0 1 0 0 0 0 x 1 
		1 1 1 1 1 1 1 1  
		*/
		
		for(int x = 0; x < 20; x++){
			for(int y = 0; y < 20; y++){
				if(y == num){
					adjTable[x][y] = -1;
				}else if(x == num){
					adjTable[x][y] = -1;
				}
			}
		}
		if(num + 1 < 20){
			if(adjTable[num+1][num+1] != -1){//means that the whole table is currently fucked
				for(int x = num; x < 20; x++){//fix xLine 
					if(adjTable[x+1][0] != -1){
						adjTable[x][0] = adjTable[x+1][0];
						adjTable[x+1][0] = -1;
					}else{
						x = 21;
					}
				}
				
				for(int y = num; y < 20; y++){//fix yLine 
					if(adjTable[0][y+1] != -1){
						adjTable[0][y] = adjTable[0][y+1];
						adjTable[0][y+1] = -1;
					}else{
						y = 21;
					}
				}
				
				for(int x = num+1; x < 20; x++){//move square 
					for(int y = num+1; y < 20; y++){
						adjTable[x-1][y-1] = adjTable[x][y];
					}
				}
				
			}
		}
		
		
	}
}

void printShit(int** adjTable, Vertex** vertices, vector<Edge*>& edges){
	if(adjTable[0][0] == -1){
		cout << "Nothing to print!\n";
	}else{
		cout << "\nvertices: \n";
		for(int x = 0; x < 20; x++){//print adj Labels
			if(vertices[x]->getID() == -1){
				x = 21;
			}else{
				cout << "[" << x << "] "<<vertices[x]->getLabel() << " // ";
			}
		}
		cout << "\n\nedges: \n";
		int count  = 0;
		for(vector<Edge*>::iterator it = edges.begin(); it != edges.end(); ++it){
			cout << "["<<count << "] ("<< vertices[(*it)->getStartId()]->getLabel() << ", " << vertices[(*it)->getEndId()]->getLabel() << ") " << "w = '" << (*it)->getWeight() <<"' // ";
			count++;
		}
	
		cout << "\n\nadjTable: \n";
	
		for(int x = 0; x < 20; x++){//print Adjacency table
			for(int y = 0; y < 20; y++){     
				cout << adjTable[x][y] << " ";
				
			}
			if(adjTable[x][0] == -1){
				x = 21;
			}
			cout << "\n";
		}
		
		
	}
	
}









