#include <iostream>
using namespace std;

void busca() {
    int arr[10] = {3, 7, 12, 18, 25, 31, 44, 56, 70, 88};
    int n;
    bool encontrado = false;

    cout << "Escolha um numero para buscar: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < 10; i++) {
        if (arr[i] == n) {
            cout << "Encontrado na posicao " << i+1 << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Numero nao encontrado!" << endl;
    }
}

int main() {
    busca();
    return 0;
}
