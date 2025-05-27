#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>


typedef struct _no TNo;
typedef struct _list TLinkedList;

TLinkedList* create();
TNo* createNfill(char c,int freq);
void insert_orden(TLinkedList* lista, TNo* no);
void tabela_frequencia(unsigned char entrada[], unsigned int tab[] );
void imprimir_frequencia(unsigned int tab[]);
void criar_lista(TLinkedList *lista);
void preencher_lista(unsigned int tab[], TLinkedList *lista);
void imprimir_lista(TLinkedList *lista);
TNo* remove_primeiro(TLinkedList* list);
void print(TLinkedList* list);
void print_arvore(TNo* raiz, int tamanho);
TNo* montar_arvore(TLinkedList* lista);
void generate_codes(TNo *no, char *code, int depth, char *codes[27]);
char* encode_string(char *entrada, char *codes[27]);
void imprimir_arvore(TNo* raiz, int tamanho);
char** aloca_dicionario (int colunas);
int altura_arvore(TNo* raiz);
void gerar_dicionario(char **dicionario, TNo* raiz, char* caminho, int colunas);
void imprimir_dicionario(char **dicionario);
char* codificar(char **dicionario, char *texto);
char *decodificar(char texto[], TNo* raiz);
char* decode_string(TNo* raiz, char* encoded);






#endif