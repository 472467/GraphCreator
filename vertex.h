#pragma warning
#ifndef VERTEX_H
#define VERTEX_H

#include <string.h>
#include <iostream>
#include <vector>
//#include "path.h"


class Vertex
{
	private:
		int id;
		char* label;
		float runningDistance;
		Vertex** bestPath;
	
	public:
		Vertex(int, char*);
		Vertex();
		int getID();
		char* getLabel();
		float getRunningDistance();
		void setRunningDistance(float);
		
		Vertex** getBestPath();
		void setBestPath(Vertex**);
	
};

#endif