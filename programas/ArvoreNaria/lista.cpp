#include <iostream>
using namespace std;

struct No {
    string valor;
    No* primeiroFilho;
    No* irmaoDireita;

    No(const string& v) : valor(v), primeiroFilho(nullptr), irmaoDireita(nullptr) {}
};

void adicionarFilho(No* pai, No* filho) {
    if (pai == nullptr || filho == nullptr) return;

    if (pai->primeiroFilho == nullptr) {
        pai->primeiroFilho = filho;
    } else {
        No* atual = pai->primeiroFilho;
        while (atual->irmaoDireita != nullptr) {
            atual = atual->irmaoDireita;
        }
        atual->irmaoDireita = filho;
    }
}

void percorrer(No* raiz, int nivel) {
    if (raiz == nullptr) return;

    for (int i = 0; i < nivel; i++) {
        cout << "  ";
    }
    cout << raiz->valor << endl;

    percorrer(raiz->primeiroFilho, nivel + 1);
    percorrer(raiz->irmaoDireita, nivel);
}

void liberar(No* raiz) {
    if (raiz == nullptr) return;
    liberar(raiz->primeiroFilho);
    liberar(raiz->irmaoDireita);
    delete raiz;
}

int main() {
    No* loja = new No("Loja");

    No* roupas = new No("Roupas");
    No* camisetas = new No("Camisetas");
    No* calcas = new No("Calças");
    No* vestidos = new No("Vestidos");

    No* eletronicos = new No("Eletrônicos");
    No* celulares = new No("Celulares");
    No* notebooks = new No("Notebooks");

    No* calcados = new No("Calçados");
    No* tenis = new No("Tênis");
    No* sandalias = new No("Sandálias");

    adicionarFilho(roupas, camisetas);
    adicionarFilho(roupas, calcas);
    adicionarFilho(roupas, vestidos);

    adicionarFilho(eletronicos, celulares);
    adicionarFilho(eletronicos, notebooks);

    adicionarFilho(calcados, tenis);
    adicionarFilho(calcados, sandalias);

    adicionarFilho(loja, roupas);
    adicionarFilho(loja, eletronicos);
    adicionarFilho(loja, calcados);

    percorrer(loja, 0);

    liberar(loja);
    return 0;
}
