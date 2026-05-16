#include <iostream>
using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;

    No(int v) {
        valor = v;
        esquerda = nullptr;
        direita = nullptr;
    }
};

// Inserir na árvore binária de busca
No* inserir(No* raiz, int valor) {
    if (raiz == nullptr) {
        return new No(valor);
    }
    
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    
    return raiz;
}

// Função de busca
bool buscar(No* raiz, int valor) {
    if (raiz == nullptr) return false;
    if (raiz->valor == valor) return true;
    if (valor < raiz->valor) 
        return buscar(raiz->esquerda, valor);
    else 
        return buscar(raiz->direita, valor);
}

// Percurso em pré-ordem
void preOrdem(No* raiz) {
    if (raiz != nullptr) {
        cout << raiz->valor << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Percurso em ordem (in-ordem)
void inOrdem(No* raiz) {
    if (raiz != nullptr) {
        inOrdem(raiz->esquerda);
        cout << raiz->valor << " ";
        inOrdem(raiz->direita);
    }
}

// Percurso em pós-ordem
void posOrdem(No* raiz) {
    if (raiz != nullptr) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        cout << raiz->valor << " ";
    }
}

int main() {
    No* raiz = nullptr;
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 14);

    cout << "Buscar 6: " << (buscar(raiz, 6) ? "Encontrado" : "Não encontrado") << endl;
    cout << "Buscar 5: " << (buscar(raiz, 5) ? "Encontrado" : "Não encontrado") << endl;

    cout << "\nPré-ordem: ";
    preOrdem(raiz);

    cout << "\nIn-ordem: ";
    inOrdem(raiz);

    cout << "\nPós-ordem: ";
    posOrdem(raiz);

    // Liberar memória (exemplo simples)
    delete raiz;

    return 0;
}
