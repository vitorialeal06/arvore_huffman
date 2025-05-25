#ifndef ARVORE_H
#define ARVORE_H

#include "Lista.h"

typedef struct {
    TNo* inicio;
    int tamanho;
} BinTree;

BinTree* BinTree_create();
TNo* TNo_createNFill(char c, int freq);
void liberarArvore(TNo* no);
void preencher_lista(int *freq, TLinkedList *lista);
int* tabela_frequencia(char entrada[]);

#endif