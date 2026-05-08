#include <iostream>
#include <set>         // set: armazena VALORES únicos ordenados
#include <unordered_set>
#include <string>

int main() {

    // Criando um set com nomes de 5 cidades
    // set ordena as chaves  em ordem alfabética automaticamente
    std::set<std::string> cidades_set = {"São Paulo", "Rio de Janeiro", "Curitiba", "Belo Horizonte", "Fortaleza"};

    //saída
    std::cout << "Saída com set (ordenado):\n";
    for (auto& c : cidades_set) {
        std::cout << c << std::endl;
    }

    // O set ignora a inserção de valores duplicados
    cidades_set.insert("São Paulo");
    std::cout << "\nTamanho após tentar inserir São Paulo novamente: "
              << cidades_set.size() << std::endl;

    // Criando um unordered_set com os mesmos dados onde a ordem de exibição varia a cada execução
    std::unordered_set<std::string> cidades_uset = {"São Paulo", "Rio de Janeiro", "Curitiba", "Belo Horizonte", "Fortaleza"};

    // saida
    std::cout << "\nSaída com unordered_set (não ordenado):\n";
    for (auto& c : cidades_uset) {
        std::cout << c << std::endl;
    }

    // Buscando uma cidade com find()
    std::string busca = "Curitiba";
    auto it = cidades_set.find(busca);

    if (it != cidades_set.end()) {
        // *it desreferencia o iterador para acessar o valor
        std::cout << "\nCidade encontrada: " << *it << std::endl;
    } else {
        std::cout << "\nCidade não encontrada." << std::endl;
    }

    return 0;
}