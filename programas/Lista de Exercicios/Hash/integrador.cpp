#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

int main() {
    // unordered_map para cadastrar 5 alunos e notas
    unordered_map<string, double> notas_finais = {
        {"Carlos", 8.5}, 
        {"Ana", 9.0}, 
        {"Bruno", 7.0}, 
        {"Daniela", 10.0}, 
        {"Eduardo", 6.5}
    };

    // unordered_set para quem entregou o trabalho
    unordered_set<string> entregou_trabalho = {"Ana", "Carlos", "Daniela"};

    // unordered_multimap para disciplinas de cada aluno (pode ter mais de uma disciplinas por aluno/chave)
    unordered_multimap<string, string> disciplinas;
    disciplinas.insert({"Ana", "Matematica"});
    disciplinas.insert({"Ana", "Fisica"});
    disciplinas.insert({"Carlos", "Portugues"});
    disciplinas.insert({"Bruno", "Historia"});

    // map para exibir em ordem alfabética
    map<string, double> notas_ordenadas(notas_finais.begin(), notas_finais.end());
    
    cout << "--- Alunos e Notas (Ordem Alfabetica) ---" << endl;
    for (const auto& p : notas_ordenadas) {
    cout << p.first << ": " << p.second << endl;
}

    //set para exibir em ordem a lista de quem entregou o trabalho
    set<string> entregou_ordenado(entregou_trabalho.begin(), entregou_trabalho.end());

    cout << "\n--- Quem entregou o trabalho (Ordem Alfabetica) ---" << endl;
    for (const string& nome : entregou_ordenado) {
        cout << nome << endl;
    }

    return 0;
}