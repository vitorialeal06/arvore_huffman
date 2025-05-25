#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>


typedef struct _no TNo;
typedef struct _list TLinkedList;

TLinkedList* create();
TNo* createNfill(char c, int freq);
bool insert_orden(TLinkedList* list, char c, int freq);
TNo* remove_first(TLinkedList* list);
void print(TLinkedList* list);


#endif