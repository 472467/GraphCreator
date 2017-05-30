#pragma warning
#ifndef PATH_H
#define PATH_H

#include <string.h>
#include <iostream>
#include <vector>
#include "vertex.h"


class Path
{
	private:
		Vertex** path;
	
	public:
		Path(Vertex**);
		
		Vertex** getPath();
		//float getTotalDistance();
		
};

#endif