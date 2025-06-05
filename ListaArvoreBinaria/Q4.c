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

// Função de BUSCA em árvore binária
No* buscar(No* T, int c) {
    // Caso base: árvore vazia ou chave encontrada na raiz
    if (T == NULL || T->dado == c) {
        return T;
    }
    
    // Se a chave é menor que a raiz, busca na subárvore esquerda
    if (c < T->dado) {
        return buscar(T->esquerdo, c);
    }
    // Se a chave é maior que a raiz, busca na subárvore direita
    else {
        return buscar(T->direito, c);
    }
}

// Função auxiliar para inserção (para construir a árvore de teste)
No* inserir(No* T, int c) {
    if (T == NULL) {
        return criarNo(c);
    }
    if (c < T->dado) {
        T->esquerdo = inserir(T->esquerdo, c);
    } else if (c > T->dado) {
        T->direito = inserir(T->direito, c);
    }
    return T;
}

int main() {
    No* raiz = NULL;
    
    // Construindo a árvore de teste
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 20);
    
    // Testando a busca
    int valores[] = {7, 15, 2, 20};
    for (int i = 0; i < 4; i++) {
        No* resultado = buscar(raiz, valores[i]);
        if (resultado != NULL) {
            printf("Valor %d encontrado na árvore.\n", valores[i]);
        } else {
            printf("Valor %d NÃO encontrado na árvore.\n", valores[i]);
        }
    }
    
    return 0;
}