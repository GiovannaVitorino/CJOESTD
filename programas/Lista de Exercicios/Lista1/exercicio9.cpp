/*
9 - Crie uma função que inverta a ordem de uma lista ligada SEM criar uma nova lista.
Use três ponteiros (anterior, atual, proximo) para redirecionar os ponteiros um a um.
*/
#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;
};

void inserirNoFinal(No*& lista, int num) {

    No* novo = new No;
    novo->valor = num;
    novo->prox = NULL;

    if(lista == NULL) {
        lista = novo;
    }
    else {
        No* aux = lista;

        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void apresentarLista(No* lista) {

    while(lista != NULL) {
        cout << lista->valor << " -> ";
        lista = lista->prox;
    }

    cout << "NULL" << endl;
}

void inverterLista(No*& lista) {

    No* anterior = NULL;
    No* atual = lista;
    No* proximo;

    while(atual != NULL) {

        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    lista = anterior;
}

int main() {

    No* lista = NULL;

    inserirNoFinal(lista, 10);
    inserirNoFinal(lista, 20);
    inserirNoFinal(lista, 30);
    inserirNoFinal(lista, 40);
    inserirNoFinal(lista, 50);

    cout << "Lista antes da inversao:" << endl;
    apresentarLista(lista);

    inverterLista(lista);

    cout << "Lista apos a inversao:" << endl;
    apresentarLista(lista);

    return 0;
}
