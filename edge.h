#pragma warning
#ifndef EDGE_H
#define EDGE_H

#include <string.h>
#include <iostream>
#include <vector>


class Edge
{
	private:
		int id;
		int startId;
		int endId;
		float weight;
		float runningDistance;
	
	public:
		Edge(int, int, int, float);
	
		int getStartId();
		int getEndId();
		float getWeight();
		float getCurrentDistance();
		void setCurrentDistance(float);
		int getID();
};

#endif