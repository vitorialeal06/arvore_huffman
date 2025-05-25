#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


TNo* build_huffman_tree(TLinkedList* lista) {
    while (lista->tamanho > 1) {
        TNo* left = remove_first(lista);
        TNo* right = remove_first(lista);
        TNo* pai = createNfill('\0', left->freq + right->freq);
        if (pai == NULL) {
            printf("Erro ao alocar memória para nó pai.\n");
            exit(1);
        }
        pai->left = left;
        pai->right = right;
        insert_orden(lista, '\0', pai->freq);
    }
    return remove_first(lista);
}

void generate_codes(TNo *no, char *code, int depth, char *codes[27]) {
    if (no == NULL) return;
    if (no->left == NULL && no->right == NULL && no->caractere != '\0') {
        code[depth] = '\0';
        int index = (no->caractere == ' ') ? 26 : no->caractere - 'a';
        codes[index] = strdup(code);
        return;
    }
    if (no->left) {
        code[depth] = '0';
        generate_codes(no->left, code, depth + 1, codes);
    }
    if (no->right) {
        code[depth] = '1';
        generate_codes(no->right, code, depth + 1, codes);
    }
}

char* encode_string(char *entrada, char *codes[27]) {
    int tamanho = strlen(entrada);
    char *encoded = (char *)malloc(tamanho * 8 + 1);
    if (encoded == NULL) {
        printf("Erro ao alocar memória para codificação.\n");
        exit(1);
    }
    encoded[0] = '\0';
    for (int i = 0; i < tamanho; i++) {
        char c = tolower(entrada[i]);
        int index = (c == ' ') ? 26 : c - 'a';
        if (codes[index]) {
            strcat(encoded, codes[index]);
        }
    }
    return encoded;
}

void free_codes(char *codes[27]) {
    for (int i = 0; i < 27; i++) {
        if (codes[i]) {
            free(codes[i]);
        }
    }
}
