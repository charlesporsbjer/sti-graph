
#ifndef LIST_H
#define LIST_H

#include <stdio.h>

typedef int Data; //ifall vi n�gonsin vi vill �ndra typen av sparat data

struct node
{
	Data d;
	struct node* rest; //notera att detta �r en lista
};

typedef struct node* List; //nodepointers �r listor



//INTERFACE

//skapar och returnerar en ny lista
List createEmptyList(void);

//unders�ker om en lista �r tom
int isEmpty(const List l);

//l�gger till 'd' f�rst i listan
//returnerar 1 ifall lyckades, annars 0
int addFirst(List* l, const Data d);

//l�gger till 'd' sist i listan
//returnerar 1 ifall lyckades, annars 0
int addLast(List* l, const Data d);

//tar bort f�rsta noden fr�n listan
void removeFirst(List* l);

//tar bort sista noden fr�n listan
void removeLast(List* l);

//tar bort f�rsta f�rekomsten av 'd' fr�n listan
//returnerar 1 ifall elementet fanns, annars 0
int removeElement(List* l, const Data d);

//unders�k om datat 'd' finns i listan
//returnerar 1 ifall det finns, annars 0
int isInList(const List l, const Data d);

//returnerar antal element i listan
int lengthOfList(const List l);

//t�mmer listan och frig�r allt minne
void clearList(List* l);

//skriver ut alla element i listan till den angivna str�mmen
void printList(const List l, FILE* stream);

//returnerar v�rdet p� f�rsta datat i listan
Data getFirstElement(const List l);

//returnerar v�rdet p� sista datat i listan
Data getLastElement(const List l);

// Mappar listan
void mapList(const List l, Data(*f) (Data));

// G�r igenom listan och
Data foldList(const List l, Data(*f) (Data, Data));


#endif
