#include "edge.h"
#include <stdlib.h>

Edge::Edge(int i, int sId, int eId, float w){
	
	startId = sId;
	endId = eId;
	id = i;
	weight = w;
	runningDistance = 0;
	
}


int Edge::getStartId(){
	return startId;
}
int Edge::getEndId(){
	return endId;
}

int Edge::getID(){
	return id;
}

float Edge::getWeight(){
	return weight;
}

float Edge::getCurrentDistance(){
	return runningDistance;
}

void Edge::setCurrentDistance(float d){
	runningDistance = d;
}