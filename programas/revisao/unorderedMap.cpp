#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void mostrarAlunos(const unordered_map<int, string>& alunos) {
    cout << "\nAlunos cadastrados:" << endl;

    for (const auto& aluno : alunos) {
        cout << "Matricula: " << aluno.first
             << " | Nome: " << aluno.second << endl;
    }
}

int main() {
    unordered_map<int, string> alunos;

    alunos[101] = "Ana";
    alunos[102] = "Bruno";
    alunos[103] = "Carla";

    alunos.insert({104, "Diego"});

    mostrarAlunos(alunos);

    int matriculaBuscada;
    cout << "\nDigite a matricula que deseja buscar: ";
    cin >> matriculaBuscada;

    if (alunos.find(matriculaBuscada) != alunos.end()) {
        cout << "Aluno encontrado: " << alunos[matriculaBuscada] << endl;
    } else {
        cout << "Matricula nao encontrada." << endl;
    }

    alunos[102] = "Bruno Silva";
    cout << "\nNome da matricula 102 atualizado." << endl;

    alunos.erase(103);
    cout << "Matricula 103 removida." << endl;

    cout << "\nQuantidade de alunos: " << alunos.size() << endl;

    mostrarAlunos(alunos);

    return 0;
}
