#include "Lista.h"
#include "arvore.h"
#include "huffman.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    TLinkedList *lista = create();
    char entrada[100] = "o rato roeu";
    int *freq = tabela_frequencia(entrada);
    if (freq == NULL) {
        printf("Erro ao processar frequências.\n");
        return 1;
    }
    preencher_lista(freq, lista);
    print(lista);
    TNo *raiz = build_huffman_tree(lista);
    if (raiz == NULL) {
        printf("Erro ao construir árvore de Huffman.\n");
        return 1;
    }
    char *codes[27] = {NULL};
    char code[100] = {0};
    generate_codes(raiz, code, 0, codes);
    printf("\nCódigos de Huffman:\n");
    for (int i = 0; i < 26; i++) {
        if (codes[i]) {
            printf("Letra '%c': %s\n", 'a' + i, codes[i]);
        }
    }
    if (codes[26]) {
        printf("Espaço: %s\n", codes[26]);
    }
    char *encoded = encode_string(entrada, codes);
    printf("\nString codificada: %s\n", encoded);
   
}