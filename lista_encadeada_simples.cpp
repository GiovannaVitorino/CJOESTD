#include <iostream>
using namespace std;


//estrutura base
struct No{
    int dado;
    No *proximo;

};

//função inserir dados no final a partir da cabeca
void inserirNoFim(No* & cabeca, int dado){
    No* novoNo = new No{dado, nullptr};

    if (cabeca == nullptr)
        cabeca = novoNo;
    else{
        No* aux = cabeca;
        while(aux -> proximo != nullptr){
            aux -> proximo;
            aux->proximo = novoNo;
        }
    }
}

void exibirLista(const No* cabeca){
    const No* aux = cabeca;
    while(aux -> proximo != nullptr){
        cout << aux
        aux->proximo = novoNo;
}

int main(){
    No *cabeca = nullptr;
    int novoValor;

    do{
        cin >> novoValor;
        inserirNoFim (cabeca, novoValor);

    }

    return 0;
}
