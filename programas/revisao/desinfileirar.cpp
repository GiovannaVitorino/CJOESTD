#include <iostream>
#include <queue>

using namespace std;

// Função para mostrar os elementos da fila
void mostrarFila(queue<char> fila) {
    while (!fila.empty()) {
        cout << fila.front() << " ";
        fila.pop();
    }
    cout << endl;
}

int main() {
    queue<char> fila;

    // 1. push() -> enfileirar elementos
    fila.push('A');
    fila.push('B');
    fila.push('C');

    cout << "Fila apos enfileirar A, B e C: ";
    mostrarFila(fila);

    // 2. front() -> mostrar primeiro elemento
    cout << "Primeiro elemento da fila: " << fila.front() << endl;

    // 3. back() -> mostrar ultimo elemento
    cout << "Ultimo elemento da fila: " << fila.back() << endl;

    // 4. size() -> quantidade de elementos
    cout << "Quantidade de elementos: " << fila.size() << endl;

    // 5. empty() -> verificar se a fila esta vazia
    if (fila.empty()) {
        cout << "A fila esta vazia" << endl;
    } else {
        cout << "A fila nao esta vazia" << endl;
    }

    // 6. pop() -> desenfileirar elementos
    cout << "\nDesenfileirando elementos..." << endl;

    while (!fila.empty()) {
        cout << "Removido: " << fila.front() << endl;
        fila.pop();
    }

    cout << "\nFila final: ";
    mostrarFila(fila);

    return 0;
}