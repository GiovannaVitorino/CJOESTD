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

    if (raiz->valor == valor)
        return true;

    if (valor < raiz->valor) 
        return buscar(raiz->esquerda, valor);
    else 
        return buscar(raiz->direita, valor);
}

// Percursos
void preOrdem(No* raiz) {
    if (raiz != nullptr) {
        cout << raiz->valor << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void inOrdem(No* raiz) {
    if (raiz != nullptr) {
        inOrdem(raiz->esquerda);
        cout << raiz->valor << " ";
        inOrdem(raiz->direita);
    }
}

void posOrdem(No* raiz) {
    if (raiz != nullptr) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        cout << raiz->valor << " ";
    }
}

// Remover folha
No* removerFolha(No* raiz, int valor) {
    if (raiz == nullptr) return nullptr;

    if (valor < raiz->valor) {
        raiz->esquerda = removerFolha(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = removerFolha(raiz->direita, valor);
    } else {
        if (raiz->esquerda == nullptr && raiz->direita == nullptr) {
            delete raiz;
            return nullptr;
        }
    }

    return raiz;
}

// Remover nó com um filho
No* removerUmFilho(No* raiz, int valor) {
    if (raiz == nullptr) return nullptr;

    if (valor < raiz->valor) {
        raiz->esquerda = removerUmFilho(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = removerUmFilho(raiz->direita, valor);
    } else {

        if (raiz->esquerda == nullptr && raiz->direita != nullptr) {
            No* aux = raiz->direita;
            delete raiz;
            return aux;

        } else if (raiz->direita == nullptr && raiz->esquerda != nullptr) {
            No* aux = raiz->esquerda;
            delete raiz;
            return aux;
        }
    }

    return raiz;
}

// Remover nó com dois filhos
No* removerDoisFilhos(No* raiz, int valor) {
    No* aux = raiz->esquerda;

    while (aux->direita != nullptr) {
        aux = aux->direita;
    }

    raiz->valor = aux->valor;
    aux->valor = valor;

    raiz->esquerda = removerUmFilho(raiz->esquerda, valor);

    return raiz;
}

int main() {
    No* raiz = nullptr;

    // Inserindo valores
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 14);
    raiz = inserir(raiz, 1);

    cout << "Arvore em ordem: ";
    inOrdem(raiz);

    // Busca
    cout << "\n\nBuscar 6: "
         << (buscar(raiz, 6) ? "Encontrado" : "Nao encontrado");

    cout << "\nBuscar 5: "
         << (buscar(raiz, 5) ? "Encontrado" : "Nao encontrado");

    // Remover folha
    cout << "\n\nRemovendo folha (1)...";
    raiz = removerFolha(raiz, 1);

    cout << "\nArvore em ordem: ";
    inOrdem(raiz);

    // Remover nó com um filho
    cout << "\n\nRemovendo no com um filho (2)...";
    raiz = removerUmFilho(raiz, 2);

    cout << "\nArvore em ordem: ";
    inOrdem(raiz);

    // Remover nó com dois filhos
    cout << "\n\nRemovendo no com dois filhos (12)...";
    raiz = removerDoisFilhos(raiz->direita, 12);

    cout << "\nArvore em ordem: ";
    inOrdem(raiz);

    cout << "\n";

    return 0;
}