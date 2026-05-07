#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

    // 1. Criando o unordered_multimap
    unordered_multimap<string, double> notas;

    // Inserindo notas
    notas.insert({"Ana", 8.5});
    notas.insert({"Ana", 7.0});
    notas.insert({"Ana", 9.2});

    notas.insert({"Carlos", 6.8});
    notas.insert({"Maria", 10.0});

    // 3. Usando count()
    cout << "Quantidade de notas da Ana: "
         << notas.count("Ana") << endl;

    // 4. Usando equal_range()
    cout << "\nNotas da Ana:\n";

    auto faixa = notas.equal_range("Ana");

    for (auto it = faixa.first; it != faixa.second; ++it) {
        cout << it->second << endl;
    }

    // Exibindo tamanho antes do erase
    cout << "\nTamanho antes do erase: "
         << notas.size() << endl;

    // 5. Removendo todas as notas da Ana
    notas.erase("Ana");

    // Confirmando com size()
    cout << "Tamanho depois do erase: "
         << notas.size() << endl;

    return 0;
}