#include <iostream>
#include <unordered_set> // Biblioteca necessária para o unordered_multiset

using namespace std;

int main() {
    // 1. Crie um multiset com as notas: {7, 8, 7, 9, 6, 8, 7, 10, 6, 9}
    unordered_multiset<int> notas = {7, 8, 7, 9, 6, 8, 7, 10, 6, 9};

    // 2. Use count() para descobrir quantos alunos tiraram nota 7
    cout << "Quantidade de alunos que tiraram nota 7: " << notas.count(7) << endl;

    // 3. Insira mais duas notas e exiba o tamanho total
    notas.insert(5);
    notas.insert(10);
    cout << "Tamanho total apos inserir mais duas notas: " << notas.size() << endl;

    // 4. Use erase() para remover todas as notas 6 e confirme com count()
    notas.erase(6);
    cout << "Quantidade de notas 6 apos o erase: " << notas.count(6) << endl;

    // 5. Exiba todas as notas restantes com for
    cout << "Notas restantes no multiset: ";
    for (int n : notas) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}