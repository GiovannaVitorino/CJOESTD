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
        // Encontrou o nó
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
No * removerDoisFilhos(No* raiz, int valor) {
    No* aux = raiz->esquerda;
    while (aux->direita != nullptr)
        aux = aux->direita;
    raiz->valor = aux->valor;
    aux->valor = valor;
    raiz->esquerda = removerUmFilho(raiz->esquerda, valor);
    return raiz;
}

// Liberar memória da árvore inteira
void liberarArvore(No* raiz) {
    if (raiz != nullptr) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        delete raiz;
    }
}

int main() {
    No* raiz = nullptr;
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 14);

    cout << "Buscar 6: " << (buscar(raiz, 6) ? "Encontrado" : "Nao encontrado") << endl;
    cout << "Buscar 5: " << (buscar(raiz, 5) ? "Encontrado" : "Nao encontrado") << endl;

    cout << "\nPre-ordem: ";
    preOrdem(raiz);

    cout << "\nOrdem: ";
    inOrdem(raiz);

    cout << "\nPos-ordem: ";
    posOrdem(raiz);

    // Exemplo de remoção
    raiz = removerUmFilho(raiz, 10);

    cout << "\n\nApós remover nó com um filho (10): ";
    inOrdem(raiz);

    liberarArvore(raiz);

    return 0;
}
