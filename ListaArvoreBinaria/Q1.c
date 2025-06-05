#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
typedef struct no {
    int dado;
    struct no *esquerdo;
    struct no *direito;
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    
    novoNo->dado = valor;
    novoNo->esquerdo = NULL;
    novoNo->direito = NULL;
    
    return novoNo;
}

// Função para liberar toda a árvore recursivamente
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerdo);
        liberarArvore(raiz->direito);
        free(raiz);
    }
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
    // Criando a árvore
    No* raiz = criarNo(10);
    
    raiz->esquerdo = criarNo(5);
    raiz->direito = criarNo(15);
    
    raiz->esquerdo->esquerdo = criarNo(2);
    raiz->esquerdo->direito = criarNo(7);
    
    raiz->direito->esquerdo = criarNo(12);
    raiz->direito->direito = criarNo(20);
    
    // Imprimindo a árvore
    printf("Árvore binária (in-ordem): ");
    imprimirArvore(raiz);
    printf("\n");
    
    // Liberando memória de forma adequada
    liberarArvore(raiz);
    
    return 0;
}