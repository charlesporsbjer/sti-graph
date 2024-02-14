
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

//undersöker om grafen är tom och returnerar 1 om tom
int isGraphEmpty(Graph g);

//lägg till en nod till grafen med värdet value
//noden ska få ett ID automatiskt
//IDt returneras
int addVertex(Graph* g, int value);

//tips: gör med hjälp av addDirectedEdge()
int addEdge(Graph g, int vertexID1, int vertexID2, int edgeValue);

//lägger till en riktad båge i grafen
int addDirectedEdge(Graph g, int startVertexID, int endVertexID, int edgeValue);

//skriver ut alla noder i ID-ordning, och deras värden
void printGraphID(Graph g);

//skriver ut alla bågar i valfri ordning, och deras värden
void printGraphEdge(Graph g);

//skriv ut alla noder i DFS-ordning, startar i en specifik nod
//tar nodens ID
//tips: använd graphDFS()
void printGraphDFS(Graph g, int startVertexID);

//skriv ut alla noder i BFS-ordning, startar i en specifik nod
//tar nodens ID
//tips: använd graphBFS()
void printGraphBFS(Graph g, int startVertexID);

//går igenom grafen i DFS-ordning, och applicerar func på varje nod
//samma funktionalitet som en map()
Graph graphDFS(Graph g, int startVertexID, int (*func));

//går igenom grafen i BFS-ordning, och applicerar func på varje nod
//samma funktionalitet som en map()
Graph graphBFS(Graph g, int startVertexID, int (*func));

#endif