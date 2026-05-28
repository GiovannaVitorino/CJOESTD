#include <iostream>
using namespace std;

struct No {
    int valor;
    No* proximo;
};

void mostrarLista(No* inicio) {
    No* atual = inicio;

    cout << "Lista: ";
    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
    cout << endl;
}

bool buscarValor(No* inicio, int valorBuscado) {
    No* atual = inicio;

    while (atual != nullptr) {
        if (atual->valor == valorBuscado) {
            return true;
        }

        atual = atual->proximo;
    }

    return false;
}

int main() {
    No* primeiro = new No{10, nullptr};
    No* segundo = new No{20, nullptr};
    No* terceiro = new No{30, nullptr};
    No* quarto = new No{40, nullptr};
    No* quinto = new No{50, nullptr};

    primeiro->proximo = segundo;
    segundo->proximo = terceiro;
    terceiro->proximo = quarto;
    quarto->proximo = quinto;

    mostrarLista(primeiro);

    int valorBuscado;
    cout << "Digite um valor para buscar: ";
    cin >> valorBuscado;

    if (buscarValor(primeiro, valorBuscado)) {
        cout << "Valor encontrado na lista!" << endl;
    } else {
        cout << "Valor nao encontrado na lista." << endl;
    }

    delete primeiro;
    delete segundo;
    delete terceiro;
    delete quarto;
    delete quinto;

    return 0;
}
