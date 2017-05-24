#include "edge.h"
#include <stdlib.h>

Edge::Edge(){
	
	
	id = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100000));//for differentiating which nodes are which, checking by memory locations doesnt work
	
}