#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esquerdo;
    struct no *direito;
} No;

No* criarNo(int c) {
    // Alocar espaço para o novo nó
    No* T = (No*)malloc(sizeof(No));
    
    // Verificar se a alocação foi bem-sucedida
    if (T != NULL) {
        T->esquerdo = NULL;
        T->direito = NULL;
        T->dado = c;
    } else {
        printf("Erro na alocação de memória!\n");
    }
    
    return T;
}

// Função auxiliar para imprimir a árvore (in-ordem)
void imprimirArvore(No* raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esquerdo);
        printf("%d ", raiz->dado);
        imprimirArvore(raiz->direito);
    }
}

int main() {
    // Exemplo de uso
    No* raiz = criarNo(10);
    
    if (raiz != NULL) {
        raiz->esquerdo = criarNo(5);
        raiz->direito = criarNo(15);
        
        printf("Árvore binária (in-ordem): ");
        imprimirArvore(raiz);
        printf("\n");
        
        // Liberar memória (em aplicação real usar função recursiva)
        free(raiz->esquerdo);
        free(raiz->direito);
        free(raiz);
    }
    
    return 0;
}