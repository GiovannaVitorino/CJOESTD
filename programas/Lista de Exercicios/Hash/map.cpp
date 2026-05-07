#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

int main() {
    // 1. Criar um map com 5 alunos e suas notas
    std::map<std::string, double> alunos_map = {
        {"Carlos", 7.5},
        {"Ana", 9.0},
        {"Bruno", 8.2},
        {"Daniela", 6.8},
        {"Eduardo", 7.9}
    };

    // 2. Exibir todos os alunos com for — saída em ordem alfabética
    std::cout << "Saída com map (ordenado):\n";
    for (auto& p : alunos_map) {
        std::cout << p.first << " -> " << p.second << std::endl;
    }

    // 3. Fazer o mesmo com unordered_map e comparar a ordem
    std::unordered_map<std::string, double> alunos_umap = {
        {"Carlos", 7.5},
        {"Ana", 9.0},
        {"Bruno", 8.2},
        {"Daniela", 6.8},
        {"Eduardo", 7.9}
    };

    std::cout << "\nSaída com unordered_map (não ordenado):\n";
    for (auto& p : alunos_umap) {
        std::cout << p.first << " -> " << p.second << std::endl;
    }

    // 4. Usar find() para buscar um aluno específico
    std::string busca = "Ana";
    auto it = alunos_map.find(busca);
    if (it != alunos_map.end()) {
        std::cout << "\nNota de " << busca << ": " << it->second << std::endl;
    } else {
        std::cout << busca << " não encontrada." << std::endl;
    }

    // 5. Adicionar mais um aluno e verificar que a ordem se mantém no map
    alunos_map["Felipe"] = 8.7;
    std::cout << "\nApós adicionar Felipe (map ordenado):\n";
    for (auto& p : alunos_map) {
        std::cout << p.first << " -> " << p.second << std::endl;
    }

    return 0;
}
