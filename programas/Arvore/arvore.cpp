#include <iostream>

using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;

    //No(int v) : valor(v), esquerda(nullptr), direita(nullptr) {}
    
    No (int v){
        valor = v;
        esquerda = nullptr; 
        direita = nullptr;
    }

};


//método para inserir um valor na árvore binária de busca
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

int main() {
    No* raiz = nullptr;
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 14);

    // Liberar memória
    delete raiz;

    return 0;
}