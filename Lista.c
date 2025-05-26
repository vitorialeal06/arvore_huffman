#include "Lista.h"
#include "arvore.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    if (list->inicio == NULL || freq < list->inicio->freq) {
        novo->prox = list->inicio;
        list->inicio = novo;
    } else {
        TNo* aux = list->inicio;
        while (aux->prox != NULL && aux->prox->freq < freq) {
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
    printf("\nConteúdo da lista:\n");
    while (aux != NULL) {
        if (aux->caractere == ' ') {
            printf("Espaço ' ' == %d vez(es)\n", aux->freq);
        } else if (aux->caractere == '\0') {
            printf("Nó == %d vez(es)\n", aux->freq);
        } else {
            printf("Letra '%c' == %d vez(es)\n", aux->caractere, aux->freq);
        }
        aux = aux->prox;
    }
}

TNo* build_huffman_tree(TLinkedList* lista) {
    while (lista->tamanho > 1) {
        TNo* primeiro = remove_first(lista);
        TNo* segundo = remove_first(lista);
        TNo* raiz = createNfill('\0', primeiro->freq + segundo->freq);
        if (raiz == NULL) {
            printf("Erro ao alocar memória.,\n");
            exit(1);
        }
        raiz->left = primeiro;
        raiz->right = segundo;
        insert_orden(lista, '\0', raiz->freq);
    }
    return remove_first(lista);
}

void imprimir_arvore(TNo* raiz, int tamanho){
    if(raiz->left == NULL && raiz->right == NULL)
        printf("\n Folha == %c Altura == %d\n", raiz->caractere, tamanho);
    else{
        imprimir_arvore(raiz->left, tamanho + 1);
        imprimir_arvore(raiz->right, tamanho + 1);
    }

}

//dicionario

int altura_arvore(TNo* raiz){
    int left, right;

    if(raiz == NULL)
        return -1;
    else{
        left = altura_arvore(raiz->left) +1;
        right = altura_arvore(raiz->right) +1;

        if(left > right)
            return left;
        else
            return right;
    }

}

char** aloca_dicionario (int colunas){

    char **dicionario = malloc(sizeof(char*)*27);

    for(int i = 0; i < 27; i++)
        dicionario[i] = calloc(colunas, sizeof(char));
    
    return dicionario;
}


void gerar_dicionario(char **dicionario, TNo* raiz, char* caminho, int colunas){
   char esquerda[colunas], direita[colunas];

    if(raiz->left == NULL && raiz->right == NULL)
        strcpy(dicionario[raiz->caractere], caminho);
    else{
        strcpy(esquerda,caminho);
        strcpy(direita,caminho);

        strcat(esquerda,"0");
        strcat(direita,"1");

        gerar_dicionario(dicionario, raiz->left, esquerda, colunas);
        gerar_dicionario(dicionario, raiz->right, direita, colunas);

    }
}

void imprimir_dicionario(char **dicionario){
    printf("dicionario\n");
    for(int i=0 ;i < 27;i++){
        if(strlen(dicionario[i])>0)
            printf(" %3d = %s\n", i, dicionario[i]);
    }
}

//codifica

int calcula_tamanho_string(char **dicionario, char *texto){
    int i = 0, tam = 0;
    while(texto[i] != '\0'){
        tam = tam +strlen(dicionario[texto[i]]);
        i++;
    }
    return tam+1;
}

char* codificar(char **dicionario, char *texto){
    int i = 0;
    int tam = calcula_tamanho_string(dicionario,texto);
    char *codigo = calloc(tam, sizeof(char));

    while(texto[i] != '\0'){
        strcat(codigo,dicionario[texto[i]]);
        i++;
    }
    return codigo;
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

//decodifica
char* decode_string(TNo* raiz, char* encoded) {
    if (!raiz || !encoded) return NULL;

    size_t max_len = strlen(encoded) + 1;
    char* decoded = malloc(max_len);
    if (!decoded) {
        printf("Erro ao alocar memória para decodificação\n");
        exit(1);
    }
    decoded[0] = '\0';
    size_t pos = 0;

    TNo* atual = raiz;
    for (size_t i = 0; encoded[i]; i++) {
        if (encoded[i] == '0') {
            atual = atual->left;
        } else if (encoded[i] == '1') {
            atual = atual->right;
        } else {
            printf("Erro: string codificada contém caractere inválido '%c'\n", encoded[i]);
            free(decoded);
            return NULL;
        }

        if (atual && atual->left == NULL && atual->right == NULL) {
            decoded[pos++] = atual->caractere;
            atual = raiz;
        }
    }
    decoded[pos] = '\0';

    decoded = realloc(decoded, pos + 1);
    if (!decoded) {
        printf("Erro ao realocar memória\n");
        exit(1);
    }

    return decoded;
}