#include <iostream>
#include <unordered_map> //também define unordered_multimap

using namespace std;

int main() {
    unordered_multimap<string, double> notas;

    // Inserindo pares
    notas.insert({"Ana", 8.5});
    notas.insert({"Ana", 7.0});
    notas.insert({"Ana", 9.2}); // mesma chave "Ana" → permitido no multimap

    notas.insert({"Carlos", 6.8});
    notas.insert({"Maria", 10.0});

    // count() no multimap retorna quantas entradas existem para aquela chave
    cout << "Quantidade de notas da Ana: "
         << notas.count("Ana") << endl; // imprime 3

    cout << "\nNotas da Ana:\n";

    
    // equal_range() retorna um par de iteradores que delimita todas as entradas com a chave fornecida
    //   faixa.first  → aponta para a primeira entrada de "Ana"
    //   faixa.second → aponta para logo após a última entrada de "Ana"
    auto faixa = notas.equal_range("Ana");

    // Percorre apenas as entradas de "Ana"
    for (auto it = faixa.first; it != faixa.second; ++it) {
        cout << it->second << endl;
    }

    // Exibindo tamanho antes do erase
    cout << "\nTamanho antes do erase: "
         << notas.size() << endl;

    // erase() com uma chave remove TODAS as entradas com aquela chave
    notas.erase("Ana");

    cout << "Tamanho depois do erase: "
         << notas.size() << endl;

    return 0;
}