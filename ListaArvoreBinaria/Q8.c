#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura do aluno (mantida como antes)
typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;

// Função auxiliar para comparar strings ignorando case
int compararStrings(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        if (tolower((unsigned char)*str1) != tolower((unsigned char)*str2)) {
            return 0; // Não é igual
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}

// Função para buscar aluno por nome (busca em toda a árvore)
Aluno* buscarPorNome(Aluno* raiz, const char* nome) {
    if (raiz == NULL) {
        return NULL;
    }
    
    // Verifica se o nome do nó atual corresponde
    if (compararStrings(raiz->nome, nome)) {
        return raiz;
    }
    
    // Busca nos subárvores
    Aluno* encontrado = buscarPorNome(raiz->esquerdo, nome);
    if (encontrado != NULL) {
        return encontrado;
    }
    
    return buscarPorNome(raiz->direito, nome);
}

// Versão que encontra todas as ocorrências (para nomes repetidos)
void buscarTodosPorNome(Aluno* raiz, const char* nome) {
    if (raiz == NULL) {
        return;
    }
    
    // Verifica o nó atual
    if (compararStrings(raiz->nome, nome)) {
        printf("Encontrado: Matrícula: %d, Nome: %s, Nota: %.2f\n",
               raiz->matricula, raiz->nome, raiz->nota);
    }
    
    // Busca nas subárvores
    buscarTodosPorNome(raiz->esquerdo, nome);
    buscarTodosPorNome(raiz->direito, nome);
}

// Exemplo de uso na função main
int main() {
    Aluno* raiz = NULL;
    
    // Inserindo alguns alunos (código de inserção omitido para brevidade)
    raiz = inserirAluno(raiz, "João Silva", 12345, 8.5);
    raiz = inserirAluno(raiz, "Maria Souza", 67890, 9.2);
    raiz = inserirAluno(raiz, "Carlos Oliveira", 34567, 7.8);
    raiz = inserirAluno(raiz, "Ana Pereira", 45678, 6.5);
    raiz = inserirAluno(raiz, "João Silva", 11223, 7.5); // Nome repetido
    
    // Buscando por nome
    char nomeBusca[50] = "João Silva";
    
    printf("Buscando por '%s':\n", nomeBusca);
    
    // Versão que encontra a primeira ocorrência
    Aluno* encontrado = buscarPorNome(raiz, nomeBusca);
    if (encontrado != NULL) {
        printf("Primeira ocorrência encontrada:\n");
        printf("Matrícula: %d, Nota: %.2f\n", encontrado->matricula, encontrado->nota);
    } else {
        printf("Aluno não encontrado.\n");
    }
    
    printf("\nTodas as ocorrências de '%s':\n", nomeBusca);
    buscarTodosPorNome(raiz, nomeBusca);
    
    liberarArvore(raiz);
    return 0;
}