/*#include "Lista.h"
#include "arvore.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 256



int* tabela_frequencia(char entrada[]) {
    int *freq = (int *)malloc(27 * sizeof(int));
    if (freq == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    for (int i = 0; i < 27; i++) {
        freq[i] = 0;
    }

    if (entrada[strlen(entrada) - 1] == '\n') {
        entrada[strlen(entrada) - 1] = '\0';
    }

    int tamanho = strlen(entrada);
    if (tamanho == 0) {
        printf("Frase vazia!\n");
        free(freq);
        return NULL;
    }

    for (int i = 0; i < tamanho; i++) {
        char c = tolower(entrada[i]);
        if (c >= 'a' && c <= 'z') {
            freq[c - 'a']++;
        } else if (c == ' ') {
            freq[26]++;
        }
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%c", entrada[i]);
    }
    printf("\n");

    printf("tabela frequencia\n");
    for (int j = 0; j < 26; j++) {
        if (freq[j] > 0) {
            printf("Letra %c == %d vezes \n", 'a' + j, freq[j]);
        }
    }
    if (freq[26] > 0) {
        printf("espacos == %d vezes \n", freq[26]);
    }

    return freq;
}



BinTree* BinTree_create() {
    BinTree* T = malloc(sizeof(BinTree));
    if (T) {
        T->inicio = NULL;
        T->tamanho = 0;
    }
    return T;
}

TNo* TNo_createNFill(char c, int freq) {
    return createNfill(c, freq);
}


void preencher_lista(int *freq, TLinkedList *lista) {
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            insert_orden(lista, 'a' + i, freq[i]);
        }
    }
    if (freq[26] > 0) {
        insert_orden(lista, ' ', freq[26]);
    }
}

*/