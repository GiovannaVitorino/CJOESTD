#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<char> fila;

    // Enfileirar A, B, C
    fila.push('A');
    fila.push('B');
    fila.push('C');

    cout << "Primeiro da fila: " << fila.front() << endl;
    cout << "Ultimo da fila: " << fila.back() << endl;
    cout << "Quantidade de elementos: " << fila.size() << endl;

    // Desenfileirar e mostrar cada letra
    while (!fila.empty()) {
        cout << "Desenfileirando: " << fila.front() << endl;
        fila.pop();
    }

    return 0;
}
