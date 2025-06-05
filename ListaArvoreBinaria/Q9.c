#include <stdbool.h>
#include <stdlib.h>

// Definição simples de uma pilha
typedef struct NoPilha {
    Aluno* aluno;
    struct NoPilha* proximo;
} NoPilha;

void empilhar(NoPilha** topo, Aluno* aluno) {
    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    novo->aluno = aluno;
    novo->proximo = *topo;
    *topo = novo;
}

Aluno* desempilhar(NoPilha** topo) {
    if (*topo == NULL) return NULL;
    NoPilha* temp = *topo;
    Aluno* aluno = temp->aluno;
    *topo = temp->proximo;
    free(temp);
    return aluno;
}

// Função iterativa para calcular a média usando pilha
float mediaNotasIterativa(Aluno* raiz) {
    if (raiz == NULL) return 0.0f;
    
    NoPilha* pilha = NULL;
    Aluno* atual = raiz;
    float soma = 0.0f;
    int quantidade = 0;
    
    while (atual != NULL || pilha != NULL) {
        // Vai até o nó mais à esquerda
        while (atual != NULL) {
            empilhar(&pilha, atual);
            atual = atual->esquerdo;
        }
        
        // Processa o nó
        atual = desempilhar(&pilha);
        soma += atual->nota;
        quantidade++;
        
        // Vai para a subárvore direita
        atual = atual->direito;
    }
    
    return soma / quantidade;
}

int main() {
    Aluno* raiz = NULL;
    
    // Inserindo alunos de exemplo
    raiz = inserirAluno(raiz, "João Silva", 12345, 8.5);
    raiz = inserirAluno(raiz, "Maria Souza", 67890, 9.2);
    raiz = inserirAluno(raiz, "Carlos Oliveira", 34567, 7.8);
    raiz = inserirAluno(raiz, "Ana Pereira", 45678, 6.5);
    
    // Calculando a média
    float media = mediaNotas(raiz);
    printf("Média das notas (recursivo): %.2f\n", media);
    
    media = mediaNotasIterativa(raiz);
    printf("Média das notas (iterativo): %.2f\n", media);
    
    liberarArvore(raiz);
    return 0;
}