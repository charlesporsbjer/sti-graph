#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
	createListNode() finns f�r att g�ra koden l�ttare
	att skriva. det �r en s� kallad hj�lpfunktion.

	den �r _inte_ med i interfacet, och �r d�rmed static.

	vad den ska g�ra:
	allokera minne f�r en ny nod
	unders�k om allokering lyckas
		returnera NULL ifall mislyckas
	initiera noden
	returnera noden */

static struct node* createListNode(const Data d) {
	struct node* n = (struct node*)malloc(sizeof(struct node));
	if (n)
	{
		n->d = d;
		n->rest = NULL;
	}
	return n;
}


//----

List createEmptyList(void) {
	return NULL; //funktionen �r f�rdig, �ndra inte
}

int isEmpty(const List l) {
	if (l == NULL)
		return 1;
	return 0;
}

int addFirst(List* l, const Data d) {
	struct node* n = createListNode(d);
	if (n)
	{
		n->rest = *l;
		*l = n;
		return 1;
	}
	return 0;
}

int addLast(List* l, const Data d) {
	if (isEmpty(*l))
		return addFirst(l, d);
	else
		return addLast(&(*l)->rest, d); // kr�ngel???
}

void removeFirst(List* l) {
	//precondition: listan �r inte tom (testa med assert)
	assert(!isEmpty(*l));

	struct node* toRemove = *l;
	*l = (*l)->rest;
	free(toRemove);
}

void removeLast(List* l) {
	//precondition: listan �r inte tom (testa med assert)
	assert(!isEmpty(*l));

	if (isEmpty((*l)->rest))
		removeFirst(l);
	else
		return removeLast(&(*l)->rest);
}

int removeElement(List* l, const Data d) {
	if (isEmpty(*l))
		return 0;
	if ((*l)->d == d)
	{
		removeFirst(l);
		return 1;
	}
	return removeElement(&(*l)->rest, d);
}

int isInList(const List l, const Data d) {
	if (isEmpty(l))
		return 0;
	if (l->d == d)
		return 1;
	return isInList(l->rest, d);
}

int lengthOfList(const List l) {
	if (isEmpty(l))
		return 0;
	else
		return 1 + lengthOfList(l->rest);
}

void clearList(List* l) {
	//postcondition: listan �r tom (testa med assert)

	if (isEmpty(*l))
		return;
	removeFirst(l);
	clearList(l);
	assert(isEmpty(*l));
}

void printList(const List l, FILE* stream) {
	// om listan �r tom
		// newline
	// annars
		// skriv ut f�rsta elementet
		// rekursivt anrop
	if (isEmpty(l))
		fprintf(stream, "\n");
	else
	{
		fprintf(stream, "%d, ", l->d);
		printList(l->rest, stream);
	}
}

Data getFirstElement(const List l) {
	//precondition: listan �r inte tom (testa med assert)
	assert(!isEmpty(l));

	return l->d;
}

Data getLastElement(const List l) {
	assert(!isEmpty(l));

	if (isEmpty(l->rest))
		return l->d;
	return getLastElement(l->rest);
}

void mapList(const List l, Data(*f) (Data)) {
	if (!isEmpty(l)) {
		l->d = (*f)(l->d);
		mapList(l->rest, f);
	}
}

Data foldList(const List l, Data(*f) (Data, Data)) {
	if (isEmpty(l->rest->rest))
		return (*f) (l->d, l->rest->d);
	else
		return (*f) (l->d, foldListl(->rest, f));

	// om finns tv� element
	// flolda f�rsta tv�
	// folda med det och nsta element
	Data res = (*f) (l->d, l->rest->d);
}



