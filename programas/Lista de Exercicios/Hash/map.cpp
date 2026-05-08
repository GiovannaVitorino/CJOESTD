#include <iostream>
#include <map>         // armazena pares ordenados pela chave
#include <unordered_map> // armazena pares sem ordenação
#include <string>

int main() {
    // map ordena as chaves  em ordem alfabética automaticamente
    std::map<std::string, double> alunos_map = {
        {"Carlos", 7.5},
        {"Ana",    9.0},
        {"Bruno",  8.2},
        {"Daniela",6.8},
        {"Eduardo",7.9}
    };

    std::cout << "Saída com map (ordenado):\n";
    for (auto& p : alunos_map) {
        std::cout << p.first << " -> " << p.second << std::endl;
    }

    // cria um unordered_map com os mesmos dados onde a ordem de exibição depende da função hash
    std::unordered_map<std::string, double> alunos_umap = {
        {"Carlos", 7.5},
        {"Ana",    9.0},
        {"Bruno",  8.2},
        {"Daniela",6.8},
        {"Eduardo",7.9}
    };

    std::cout << "\nSaída com unordered_map (não ordenado):\n";
    for (auto& p : alunos_umap) {
        std::cout << p.first << " -> " << p.second << std::endl;
    }

    // Buscando um aluno específico
    std::string busca = "Ana";
    auto it = alunos_map.find(busca);

    if (it != alunos_map.end()) {
        std::cout << "\nNota de " << busca << ": " << it->second << std::endl;
    } else {
        std::cout << busca << " não encontrada." << std::endl;
    }

    // Inserindo com o map, a nova chave é inserida na posição correta da ordem alfabética
    alunos_map["Felipe"] = 8.7;

    std::cout << "\nApós adicionar Felipe (map ordenado):\n";
    for (auto& p : alunos_map) {
        std::cout << p.first << " -> " << p.second << std::endl;
    }

    return 0;
}