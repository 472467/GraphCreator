#include "path.h"
#include "vertex.h"
#include <stdlib.h>

Path::Path(Vertex** p){
	path = p;
}
		
Vertex** Path::getPath(){
	return path;
}
