/*
7 - Construa uma lista ligada inserindo os valores 10, 20, 30, 40, 50 no final.
Imprima a lista no formato abaixo e exiba a quantidade total de nós.
*/
#include <iostream>
using namespace std;

struct No {
    int valor;
    No* proximo;
};

void inserirNoFinal(No*& lista, int n) {
    if (lista == nullptr) {
        lista = new No{n, nullptr};
    } else {
        inserirNoFinal(lista->proximo, n);
    }
}
void mostrarLista(No* lista) {
    int totalNos = 0;
    while (lista != nullptr) {
        cout << lista->valor << " -> ";
        lista = lista->proximo;
        totalNos++;
    }
    cout << "NULL" << endl;
    cout << "Total de nos: " << totalNos << endl;
}

int main() {
    No* lista = nullptr;

    inserirNoFinal(lista, 10);
    inserirNoFinal(lista, 20);
    inserirNoFinal(lista, 30);
    inserirNoFinal(lista, 40);
    inserirNoFinal(lista, 50);

    mostrarLista(lista);

    return 0;
}
