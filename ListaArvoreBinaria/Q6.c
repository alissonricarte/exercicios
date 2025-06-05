// codigo c
void testarFuncoes() {
    No* raiz = NULL;
    
    // Teste de inserção
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);
    
    // Teste de busca
    printf("Buscar 40: %s\n", buscar(raiz, 40) ? "Encontrado" : "Não encontrado");
    printf("Buscar 90: %s\n", buscar(raiz, 90) ? "Encontrado" : "Não encontrado");
    
    // Teste de remoção
    printf("Árvore antes da remoção:\n");
    imprimirInOrdem(raiz);
    printf("\n");
    
    raiz = remover(raiz, 20);
    raiz = remover(raiz, 30);
    
    printf("Árvore após remoção:\n");
    imprimirInOrdem(raiz);
    printf("\n");
    
    // Liberar memória
    liberarArvore(raiz);
}

int main() {
    testarFuncoes();
    return 0;
}