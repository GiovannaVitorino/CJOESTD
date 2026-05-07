#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    // 1. Criando o unordered_set
    unordered_set<int> numeros = {10, 20, 30, 20, 10, 40};

    // Exibindo tamanho inicial
    cout << "Tamanho inicial: "
         << numeros.size() << endl;

    // 2. Inserindo 50 e 20
    numeros.insert(50);
    numeros.insert(20);

    // Exibindo tamanho depois
    cout << "Tamanho depois das insercoes: "
         << numeros.size() << endl;

    // 3. Verificando se 30 existe
    if (numeros.count(30)) {
        cout << "O valor 30 existe.\n";
    } else {
        cout << "O valor 30 nao existe.\n";
    }

    // 4. Removendo o 10
    numeros.erase(10);

    cout << "\nElementos restantes:\n";

    for (int n : numeros) {
        cout << n << " ";
    }

    // 5. Simulando controle de acesso
    unordered_set<string> acessos;

    cout << "\n\nControle de acesso:\n";

    string usuario = "joao";

    // Primeiro acesso
    if (acessos.insert(usuario).second) {
        cout << usuario << " entrou.\n";
    } else {
        cout << usuario << " ja estava registrado.\n";
    }

    // Tentando inserir novamente
    if (acessos.insert(usuario).second) {
        cout << usuario << " entrou.\n";
    } else {
        cout << usuario << " ja estava registrado.\n";
    }

    return 0;
}