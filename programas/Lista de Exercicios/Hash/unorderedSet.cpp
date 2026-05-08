#include <iostream>
#include <unordered_set> 
using namespace std;

int main() {
    unordered_set<int> numeros = {10, 20, 30, 20, 10, 40};

    // size() retorna quantos elementos únicos estão armazenados
    cout << "Tamanho inicial: "
         << numeros.size() << endl;

    // Inserindo novos valores
    numeros.insert(50);
    numeros.insert(20); // não é inserido, pois já existe
    
    // Novo tamanho após as inserções
    cout << "Tamanho depois das insercoes: "
         << numeros.size() << endl;

    // Verifica se valor existe
    if (numeros.count(30)) {
        cout << "O valor 30 existe.\n";
    } else {
        cout << "O valor 30 nao existe.\n";
    }

    // remoção
    numeros.erase(10);

    cout << "\nElementos restantes:\n";
    for (int n : numeros) {
        cout << n << " ";
    }

    unordered_set<string> acessos;

    cout << "\n\nControle de acesso:\n";
    string usuario = "joao";

    // insert() retorna um pair<iterator, bool>
    // O campo .second do par indica se a inserção ocorreu (true) ou não (false)
    if (acessos.insert(usuario).second) {
        cout << usuario << " entrou.\n";
    } else {
        cout << usuario << " ja estava registrado.\n";
    }

    if (acessos.insert(usuario).second) {
        cout << usuario << " entrou.\n";
    } else {
        cout << usuario << " ja estava registrado.\n";
    }

    return 0;
}