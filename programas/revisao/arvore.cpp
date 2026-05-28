#include <iostream>
using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;
};

No* criarNo(int valor) {
    return new No{valor, nullptr, nullptr};
}

No* inserir(No* raiz, int valor) {
    if (raiz == nullptr) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

void preOrdem(No* raiz) {
    if (raiz != nullptr) {
        cout << raiz->valor << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void posOrdem(No* raiz) {
    if (raiz != nullptr) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        cout << raiz->valor << " ";
    }
}

int altura(No* raiz) {
    if (raiz == nullptr) {
        return -1;
    }

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);

    if (alturaEsquerda > alturaDireita) {
        return alturaEsquerda + 1;
    }

    return alturaDireita + 1;
}

void liberarArvore(No* raiz) {
    if (raiz != nullptr) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        delete raiz;
    }
}

int main() {
    int valores[] = {15, 8, 22, 4, 11, 9, 13, 18, 27};
    No* raiz = nullptr;

    for (int valor : valores) {
        raiz = inserir(raiz, valor);
    }

    cout << "Pre-ordem: ";
    preOrdem(raiz);

    cout << "\nPos-ordem: ";
    posOrdem(raiz);

    int alturaEmArestas = altura(raiz);

    cout << "\nAltura da arvore: " << alturaEmArestas << " arestas" << endl;
    cout << "Altura da arvore em niveis: " << alturaEmArestas + 1 << endl;
    cout << "Profundidade maxima: " << alturaEmArestas << endl;

    liberarArvore(raiz);

    return 0;
}
