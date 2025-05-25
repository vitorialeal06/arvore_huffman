#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _no {
    char caractere; // 'a'-'z', ' ', ou '\0' para nós internos
    int freq;
    struct _no* prox;
    struct _no* left;
    struct _no* right;
} TNo;

struct _list {
    TNo* inicio;
    int tamanho;
};

TNo* createNfill(char c, int freq) {
    TNo* novo = malloc(sizeof(TNo));
    if (novo) {
        novo->caractere = c;
        novo->freq = freq;
        novo->prox = NULL;
        novo->left = NULL;
        novo->right = NULL;
    }
    return novo;
}

TLinkedList* create() {
    TLinkedList* list = malloc(sizeof(TLinkedList));
    if (list != NULL) {
        list->inicio = NULL;
        list->tamanho = 0;
    }
    return list;
}

bool insert_orden(TLinkedList* list, char c, int freq) {
    TNo* novo = createNfill(c, freq);
    if (novo == NULL)
        return false;

    if (list->inicio == NULL || freq < list->inicio->freq ||
        (freq == list->inicio->freq && c < list->inicio->caractere)) {
        novo->prox = list->inicio;
        list->inicio = novo;
    } else {
        TNo* aux = list->inicio;
        while (aux->prox != NULL &&
               (aux->prox->freq < freq ||
                (aux->prox->freq == freq && aux->prox->caractere <= c))) {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }

    list->tamanho++;
    return true;
}

TNo* remove_first(TLinkedList* list) {
    if (list->inicio == NULL)
        return NULL;
    TNo* no = list->inicio;
    list->inicio = no->prox;
    list->tamanho--;
    no->prox = NULL;
    return no;
}

void print(TLinkedList* list) {
    if (list->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    TNo* aux = list->inicio;
    printf("Conteúdo da lista:\n");
    while (aux != NULL) {
        if (aux->caractere == ' ') {
            printf("Espaço: %d vez(es)\n", aux->freq);
        } else if (aux->caractere == '\0') {
            printf("Nó interno: %d vez(es)\n", aux->freq);
        } else {
            printf("Letra '%c': %d vez(es)\n", aux->caractere, aux->freq);
        }
        aux = aux->prox;
    }
}
