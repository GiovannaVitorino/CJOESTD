#include <iostream>
#include <vector>
using namespace std;

struct No {
    string valor;
    vector<No*> filhos;

    No(string v) {
        valor = v;
    } 
};

void adicionarFilho(No* pai, No* filho) {
    pai->filhos.push_back(filho);
}

void percorrer(No* raiz, int nivel ){
    if (raiz==nullptr) return;
    for (int i = 0; i < nivel; i++) {
        cout << "  ";
    }
    cout << raiz->valor << endl;
    for (No* filho : raiz->filhos) {
        percorrer(filho, nivel + 1);
    }
}

void liberar(No* raiz) {
    if (raiz == nullptr) return;
    for (No* filho : raiz->filhos) {
        liberar(filho);
    }
    delete raiz;
}

int main() {
    No* loja = new No("Loja");

    No* roupas = new No("Roupas");
    No* camisetas = new No("Camisetas");
    No* calcas = new No("Calcas");
    No* vestidos = new No("Vestidos");

    No* eletronicos = new No("Eletronicos");
    No* celulares = new No("Celulares");
    No* notebooks = new No("Notebooks");

    No* calcados = new No("Calcados");
    No* tenis = new No("Tenis");
    No* sandalias = new No("Sandalias");

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
