#include <stdio.h>
#include <stdlib.h>

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

// Função para remover/liberar toda a árvore (pós-ordem)
No* removerArvore(No* T) {
    if (T != NULL) {
        // Primeiro remove as subárvores esquerda e direita
        T->esquerdo = removerArvore(T->esquerdo);
        T->direito = removerArvore(T->direito);
        
        // Depois libera o nó atual
        free(T);
        T = NULL;  // Importante: setar o ponteiro como NULL após liberar
    }
    return T;  // Retorna NULL para o chamador poder atualizar seu ponteiro
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
    // Construindo a árvore de exemplo
    No* raiz = criarNo(10);
    raiz->esquerdo = criarNo(5);
    raiz->direito = criarNo(15);
    raiz->esquerdo->esquerdo = criarNo(2);
    raiz->esquerdo->direito = criarNo(7);
    raiz->direito->esquerdo = criarNo(12);
    raiz->direito->direito = criarNo(20);

    printf("Árvore antes da remoção: ");
    imprimirArvore(raiz);
    printf("\n");

    // Removendo toda a árvore
    raiz = removerArvore(raiz);

    printf("Árvore após remoção: ");
    imprimirArvore(raiz);  // Não deve imprimir nada
    printf("\n");

    // Verificando se a raiz foi realmente liberada
    if (raiz == NULL) {
        printf("Árvore foi completamente removida.\n");
    } else {
        printf("ERRO: Árvore não foi completamente removida.\n");
    }

    return 0;
}