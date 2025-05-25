#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "Lista.h"
#include "arvore.h"

TNo* build_huffman_tree(TLinkedList *lista);
void generate_codes(TNo *no, char *code, int depth, char *codes[27]);
char* encode_string(char *entrada, char *codes[27]);
void free_codes(char *codes[27]);


#endif