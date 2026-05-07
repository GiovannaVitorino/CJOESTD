/*
8 - Monte uma lista com os valores 5, 15, 25, 35, 45. Peça ao usuário um valor, busque-o na lista e,
se encontrado, remova-o e imprima a lista atualizada. Se não encontrado, exiba mensagem de erro.
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

bool removerValor(No*& lista, int num) {

    No* atual = lista;
    No* anterior = NULL;

    while(atual != NULL && atual->valor != num) {
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL) {
        return false;
    }

    if(anterior == NULL) {
        lista = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    delete atual;
    return true;
}

int main() {

    No* lista = NULL;

    inserirNoFinal(lista, 5);
    inserirNoFinal(lista, 15);
    inserirNoFinal(lista, 25);
    inserirNoFinal(lista, 35);
    inserirNoFinal(lista, 45);

    cout << "Lista:" << endl;
    apresentarLista(lista);

    int num;

    cout << "Qual numero deseja remover? ";
    cin >> num;

    if(removerValor(lista, num)) {
        cout << "Valor removido com sucesso!" << endl;
        cout << "Lista depois da remocao:" << endl;
        apresentarLista(lista);
    }
    else {
        cout << "Valor nao encontrado na lista!" << endl;
    }

    return 0;
}
