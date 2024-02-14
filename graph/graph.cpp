
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "graph.h"
//#include "list.h"

// KLAR?
Graph createEmptyGraph() {
	Graph g;
	g.size = 0;
	g.listArray = NULL;
	return g;
}

//undersöker om grafen är tom och returnerar 1 om tom
int isGraphEmpty(Graph g) {
	if (g.size == 0)
		return 1;
	return 0;
}

//lägg till en nod till grafen med värdet value
//noden ska få ett ID automatiskt (size)
//IDt returneras
int addVertex(Graph* g, int value) {
	List* temp = (List*)realloc(g->listArray, (g->size + 1) * sizeof(List));
	
	if (temp) {
		g->listArray = temp;
		g->size++;
		return g->size - 1;
	}
	return - 1;
	// = value;
}

//tips: gör med hjälp av addDirectedEdge()
int addEdge(Graph g, int vertexID1, int vertexID2,  int edgeValue) {
	if (!isGraphEmpty(g)) {
		addDirectedEdge(g, vertexID1, vertexID2, edgeValue);
		addDirectedEdge(g, vertexID2, vertexID1, edgeValue);
		return 1;
	}
	else
		return 0;
}

//lägger till en riktad båge i grafen // FIXA edgeValue
int addDirectedEdge(Graph g, int startVertexID, int endVertexID, int edgeValue) {
	if (!isGraphEmpty(g)) {
		createEmptyList();
		//addFirst(&g.listArray[startVertexID], endVertexID);
		return 1;
	}
	else
		return 0;
}


//skriver ut alla noder i ID-ordning, och deras värden
// och alla utgående bågar och dess vikter.
void printGraphID(Graph g) {
	for (int i = 0; i < g.size; i++) {
		printf("ID %d: ", i);	// Print ID.
		//printf("%d\n", )		// Print value.
	}
}

//skriver ut alla bågar i valfri ordning, och deras värden
void printGraphEdge(Graph g) {}

//skriv ut alla noder i DFS-ordning, startar i en specifik nod
//tar nodens ID
//tips: använd graphDFS()
void printGraphDFS(Graph g, int startVertexID) {}

//skriv ut alla noder i BFS-ordning, startar i en specifik nod
//tar nodens ID
//tips: använd graphBFS()
void printGraphBFS(Graph g, int startVertexID) {}

//går igenom grafen i DFS-ordning, och applicerar func på varje nod
//samma funktionalitet som en map()
/*Graph graphDFS(Graph* g, int startVertexID, int (*func)()) {
	int index = startVertexID;
	if (!isEmpty(g->listArray[index])) {
		func(g->listArray[index].d);
		index++;
		graphDFS(g, index, func); // Måste se över BFS
	}
	return;
}*/

//går igenom grafen i BFS-ordning, och applicerar func på varje nod
//samma funktionalitet som en map()
Graph graphBFS(Graph g, int startVertexID, int (*func)()) { return g; }

