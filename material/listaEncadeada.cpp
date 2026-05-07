#include <iostream>
using namespace std;

struct No
{
    int dado;
    No* proximo;
};

void inserirNoFim(No*& cabeca, int dado){
    No* novoNo = new No{dado, nullptr};

    if (cabeca == nullptr)
        cabeca = novoNo;
    else{
        No* aux = cabeca;
        while (aux->proximo != nullptr)
            aux = aux->proximo;
        aux->proximo = novoNo;
    }
}

void exibirLista(const No* cabeca){
    const No* aux = cabeca;
    while (aux != nullptr){
        cout << aux->dado << " - ";
        aux = aux->proximo;
    }
    cout << endl;
}

int main()
{
    No* cabeca = nullptr;
    int novoValor;
    
    do
    {
        cin >> novoValor;

        inserirNoFim(cabeca, novoValor);
        exibirLista(cabeca);
    } while (novoValor != -1);
    
    return 0;
}
