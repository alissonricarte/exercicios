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

// Função de INSERÇÃO em árvore binária (sem duplicatas)
No* inserir(No* T, int c) {
    // Caso base: árvore vazia ou chegou a uma folha
    if (T == NULL) {
        return criarNo(c);
    }
    
    // Evitar duplicatas (se já existe, retorna o nó sem modificar)
    if (c == T->dado) {
        return T;
    }
    // Inserir na subárvore esquerda se o valor for menor
    else if (c < T->dado) {
        T->esquerdo = inserir(T->esquerdo, c);
    }
    // Inserir na subárvore direita se o valor for maior
    else {
        T->direito = inserir(T->direito, c);
    }
    
    return T;
}

// Função auxiliar para imprimir a árvore (in-ordem)
void imprimirInOrdem(No* T) {
    if (T != NULL) {
        imprimirInOrdem(T->esquerdo);
        printf("%d ", T->dado);
        imprimirInOrdem(T->direito);
    }
}

int main() {
    No* raiz = NULL;
    
    // Inserindo valores na árvore
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);
    
    // Tentando inserir duplicatas (não deve alterar a árvore)
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    
    printf("Árvore binária (in-ordem): ");
    imprimirInOrdem(raiz);
    printf("\n");
    
    // Saída esperada: 20 30 40 50 60 70 80
    
    return 0;
}