#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

int main() {
    // 1. unordered_map para cadastrar 5 alunos e notas
    unordered_map<string, double> notas_finais = {
        {"Carlos", 8.5}, {"Ana", 9.0}, {"Bruno", 7.0}, {"Daniela", 10.0}, {"Eduardo", 6.5}
    };

    // 2. unordered_set para quem entregou o trabalho
    unordered_set<string> entregou_trabalho = {"Ana", "Carlos", "Daniela"};

    // 3. unordered_multimap para disciplinas de cada aluno (permite várias disciplinas por chave)
    unordered_multimap<string, string> disciplinas;
    disciplinas.insert({"Ana", "Matematica"});
    disciplinas.insert({"Ana", "Fisica"});
    disciplinas.insert({"Carlos", "Portugues"});
    disciplinas.insert({"Bruno", "Historia"});

    // 4. map para exibir alunos em ordem alfabética com notas
    // Dica: Podemos inicializar o map passando o conteúdo do unordered_map
    map<string, double> notas_ordenadas(notas_finais.begin(), notas_finais.end());
    
    cout << "--- Alunos e Notas (Ordem Alfabetica) ---" << endl;
    for (const auto& [nome, nota] : notas_ordenadas) {
        cout << nome << ": " << nota << endl;
    }

    // 5. set para exibir em ordem a lista de quem entregou o trabalho
    set<string> entregou_ordenado(entregou_trabalho.begin(), entregou_trabalho.end());

    cout << "\n--- Quem entregou o trabalho (Ordem Alfabetica) ---" << endl;
    for (const string& nome : entregou_ordenado) {
        cout << nome << endl;
    }

    return 0;
}