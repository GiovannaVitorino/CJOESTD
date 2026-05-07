#include <iostream>
#include <set>
#include <unordered_set>
#include <string>

int main() {
    // 1. Criar um set com nomes de 5 cidades em ordem aleatória
    std::set<std::string> cidades_set = {"São Paulo", "Rio de Janeiro", "Curitiba", "Belo Horizonte", "Fortaleza"};

    // 2. Exibir todas as cidades — saída em ordem alfabética
    std::cout << "Saída com set (ordenado):\n";
    for (auto& c : cidades_set) {
        std::cout << c << std::endl;
    }

    // 3. Tentar inserir uma cidade já existente
    cidades_set.insert("São Paulo");
    std::cout << "\nTamanho após tentar inserir São Paulo novamente: "
              << cidades_set.size() << std::endl;

    // 4. Fazer o mesmo com unordered_set e comparar a ordem
    std::unordered_set<std::string> cidades_uset = {"São Paulo", "Rio de Janeiro", "Curitiba", "Belo Horizonte", "Fortaleza"};

    std::cout << "\nSaída com unordered_set (não ordenado):\n";
    for (auto& c : cidades_uset) {
        std::cout << c << std::endl;
    }

    // 5. Usar find() para verificar se uma cidade está no set
    std::string busca = "Curitiba";
    auto it = cidades_set.find(busca);
    if (it != cidades_set.end()) {
        std::cout << "\nCidade encontrada: " << *it << std::endl;
    } else {
        std::cout << "\nCidade não encontrada." << std::endl;
    }

    return 0;
}
