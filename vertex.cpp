#include "vertex.h"
#include "path.h"
#include <stdlib.h>

Vertex::Vertex(int i, char* l){
	label = new char[30];
	strcpy(label, l);
	id = i;
	runningDistance = 0;
	bestPath = NULL;
	
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

Vertex** Vertex::getBestPath(){
	return bestPath;
}

void Vertex::setBestPath(Vertex** bestP){
	bestPath = bestP;
}
/*
void Vertex::cloneBestPath(Vertex* amigo){
	if(amigo->getBestPath() != NULL){
		for(int x = 0; x< 20; x++){
			
		}
	}
}
*/
