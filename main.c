#include "Lista.h"
#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    TLinkedList *lista = create(); //lista
    char entrada[100] = "o rato roeu"; //entrada
    int *freq = tabela_frequencia(entrada); //mostrando freq
    int colunas;
    TNo *arvore;
    char **dicionario;

    if (freq == NULL) 
        printf("Erro ao processar frequências.\n");

        //lista
    preencher_lista(freq, lista);
    print(lista);

        //arvore
    arvore = build_huffman_tree(lista);
    imprimir_arvore(arvore,0);

        //dicionario
    colunas = altura_arvore(arvore) + 1;
    dicionario = aloca_dicionario(colunas);
    gerar_dicionario(dicionario,arvore," ", colunas);
    imprimir_dicionario(dicionario);
    

/*    char *codes[27] = {NULL};
    char code[100] = {0};
    generate_codes(arvore, code, 0, codes);
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
*/
}