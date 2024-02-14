//This file contains the 'main' function. Program execution begins and ends there.


#include <stdio.h>
#include "graph.h"

int main()
{
	Graph g = createEmptyGraph();

	addVertex(&g, 18);
	addVertex(&g, 18);
	addVertex(&g, 18);
	printf("%d\n", g.size);
	printGraphID(g);
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

