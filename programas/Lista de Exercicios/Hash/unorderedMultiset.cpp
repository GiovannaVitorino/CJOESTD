#include <iostream>
#include <unordered_set> 
using namespace std;

int main() {
    unordered_multiset<int> notas = {7, 8, 7, 9, 6, 8, 7, 10, 6, 9};

    // Quantos alunos tiraram nota 7
    cout << "Quantidade de alunos que tiraram nota 7: " << notas.count(7) << endl;

    // Insire mais duas notas e exibe o novo tamanho
    notas.insert(5);
    notas.insert(10);
    cout << "Tamanho total apos inserir mais duas notas: " << notas.size() << endl;

    notas.erase(6); // Remove todas as notas 6
    cout << "Quantidade de notas 6 apos o erase: " << notas.count(6) << endl; // verifica se as notas 6 foram removidas

    // Exibe as nptas restantes
    cout << "Notas restantes no multiset: ";
    for (int n : notas) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}