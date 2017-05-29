#include "edge.h"
#include <stdlib.h>

Edge::Edge(int i, int sId, int eId, float w){
	
	startId = sId;
	endId = eId;
	id = i;
	weight = w;
	
	
}


int Edge::getStartId(){
	return startId;
}
int Edge::getEndId(){
	return endId;
}

float Edge::getWeight(){
	return weight;
}