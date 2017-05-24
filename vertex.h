#pragma warning
#ifndef VERTEX_H
#define VERTEX_H

#include <string.h>
#include <iostream>
#include <vector>


class Vertex
{
	private:
		int id;
		char* label;
		
	
	public:
		Vertex(int, char*);
		Vertex();
		int getID();
		char* getLabel();
	
};

#endif