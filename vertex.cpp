#include "vertex.h"
#include "path.h"
#include <stdlib.h>

Vertex::Vertex(int i, char* l){
	label = new char[30];
	strcpy(label, l);
	id = i;
	runningDistance = 0;
	bestPath = new int[20];
	for(int x = 0; x< 20; x++){
		bestPath[x] = -1;
	}
	
}

Vertex::Vertex(){
	label = NULL;
	id = -1;
	
}

int Vertex::getID(){
	return id;
}

char* Vertex::getLabel(){
	return label;
}

float Vertex::getRunningDistance(){
	return runningDistance;
}

void Vertex::setRunningDistance(float d){
	runningDistance = d;
}

int* Vertex::getBestPath(){
	return bestPath;
}

void Vertex::setBestPath(int* bestP){
	for(int x= 0; x< 20; x++){
		bestPath[x] = bestP[x];
	}
}




