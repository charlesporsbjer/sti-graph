
#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include "list.h"


typedef struct Graph {
	int size;
	List* listArray;
} Graph;




//skapar en tom graf
Graph createEmptyGraph();

//unders�ker om grafen �r tom och returnerar 1 om tom
int isGraphEmpty(Graph g);

//l�gg till en nod till grafen med v�rdet value
//noden ska f� ett ID automatiskt
//IDt returneras
int addVertex(Graph* g, int value);

//tips: g�r med hj�lp av addDirectedEdge()
int addEdge(Graph g, int vertexID1, int vertexID2, int edgeValue);

//l�gger till en riktad b�ge i grafen
int addDirectedEdge(Graph g, int startVertexID, int endVertexID, int edgeValue);

//skriver ut alla noder i ID-ordning, och deras v�rden
void printGraphID(Graph g);

//skriver ut alla b�gar i valfri ordning, och deras v�rden
void printGraphEdge(Graph g);

//skriv ut alla noder i DFS-ordning, startar i en specifik nod
//tar nodens ID
//tips: anv�nd graphDFS()
void printGraphDFS(Graph g, int startVertexID);

//skriv ut alla noder i BFS-ordning, startar i en specifik nod
//tar nodens ID
//tips: anv�nd graphBFS()
void printGraphBFS(Graph g, int startVertexID);

//g�r igenom grafen i DFS-ordning, och applicerar func p� varje nod
//samma funktionalitet som en map()
Graph graphDFS(Graph g, int startVertexID, int (*func));

//g�r igenom grafen i BFS-ordning, och applicerar func p� varje nod
//samma funktionalitet som en map()
Graph graphBFS(Graph g, int startVertexID, int (*func));

#endif