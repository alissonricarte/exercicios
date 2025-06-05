#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;

// Função para criar um novo nó/aluno
Aluno* criarAluno(const char* nome, int matricula, float nota) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    
    strncpy(novo->nome, nome, 49);
    novo->nome[49] = '\0'; // Garante terminação nula
    novo->matricula = matricula;
    novo->nota = nota;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    
    return novo;
}

// Função para inserir um aluno na árvore (ordenado por matrícula)
Aluno* inserirAluno(Aluno* raiz, const char* nome, int matricula, float nota) {
    if (raiz == NULL) {
        return criarAluno(nome, matricula, nota);
    }
    
    if (matricula < raiz->matricula) {
        raiz->esquerdo = inserirAluno(raiz->esquerdo, nome, matricula, nota);
    } else if (matricula > raiz->matricula) {
        raiz->direito = inserirAluno(raiz->direito, nome, matricula, nota);
    } else {
        // Matrícula já existe (pode atualizar ou ignorar)
        printf("Matrícula %d já existe na árvore!\n", matricula);
    }
    
    return raiz;
}

// Função para buscar um aluno por matrícula
Aluno* buscarAluno(Aluno* raiz, int matricula) {
    if (raiz == NULL || raiz->matricula == matricula) {
        return raiz;
    }
    
    if (matricula < raiz->matricula) {
        return buscarAluno(raiz->esquerdo, matricula);
    } else {
        return buscarAluno(raiz->direito, matricula);
    }
}

// Função para imprimir a árvore em ordem (ordenado por matrícula)
void imprimirEmOrdem(Aluno* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerdo);
        printf("Matrícula: %d, Nome: %s, Nota: %.2f\n", 
               raiz->matricula, raiz->nome, raiz->nota);
        imprimirEmOrdem(raiz->direito);
    }
}

// Função para liberar a memória da árvore
void liberarArvore(Aluno* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerdo);
        liberarArvore(raiz->direito);
        free(raiz);
    }
}

// Exemplo de uso
int main() {
    Aluno* raiz = NULL;
    
    // Inserindo alunos
    raiz = inserirAluno(raiz, "João Silva", 12345, 8.5);
    raiz = inserirAluno(raiz, "Maria Souza", 67890, 9.2);
    raiz = inserirAluno(raiz, "Carlos Oliveira", 34567, 7.8);
    raiz = inserirAluno(raiz, "Ana Pereira", 45678, 6.5);
    
    // Imprimindo em ordem
    printf("Alunos ordenados por matrícula:\n");
    imprimirEmOrdem(raiz);
    
    // Buscando um aluno
    int matriculaBusca = 67890;
    Aluno* aluno = buscarAluno(raiz, matriculaBusca);
    if (aluno != NULL) {
        printf("\nAluno encontrado: %s, Nota: %.2f\n", aluno->nome, aluno->nota);
    } else {
        printf("\nAluno com matrícula %d não encontrado.\n", matriculaBusca);
    }
    
    // Liberando memória
    liberarArvore(raiz);
    
    return 0;
}