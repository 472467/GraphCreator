#include "vertex.h"
#include <stdlib.h>

Vertex::Vertex(int i, char* l){
	label = new char[30];
	strcpy(label, l);
	id = i;
	runningDistance = -1;
	
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